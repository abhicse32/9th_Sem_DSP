#!/bin/bash
if [ "$#" -ne 1 ]; then 
    echo "illegal number of parameters"
    echo "usage ./eval q1"
    exit
fi

DETAILED=0
QUESTION=$1
GEN=0 #generate the ideal output

echo Evaluating $QUESTION

cd submissions
for STUD in *
do
    echo
    echo "*******************"
    echo Evaluating $STUD
    #read -p "Press any key to continue... " -n1 -s
    echo

    cd $STUD/Code
    #compiling
    cp ../../Makefile_internal Makefile
    make clean all
    #code is already compiled
    #gcc $QUESTION.c -o $QUESTION -lm

    #stat
    x=0   #number of small test cases passed
    t=20   #total number of test cases

    for ((f=0; f<$t; f++))
    do
	#execute the program and redirect output
	echo "../$QUESTION <../../../testcases/input/$QUESTION/$f > result.delme" > delme.sh
	chmod +x delme.sh
	/usr/bin/time -f "%M\n%S\n%U" -o timeTaken.delme ./delme.sh #2> timeTaken.delme
	INFO=( $(tail -n 3 timeTaken.delme) )
	MEM="${INFO[0]}"
	TOTAL_TIME=$(echo "${INFO[1]} + ${INFO[2]}" | bc)
	FAILED=0

	if [ "$GEN" -eq 1 ]; then
	    mv result.delme ../../../testcases/output/$QUESTION/$f
	    echo $TOTAL_TIME >  ../../../testcases/time/$QUESTION/$f
	    echo $MEM > ../../../testcases/memory/$QUESTION/$f
	else

	    IDEAL_TIME=$(cat ../../../testcases/time/$QUESTION/$f)
	    IDEAL_MEM=$(cat ../../../testcases/memory/$QUESTION/$f)

	    if [ "$DETAILED" -eq 1 ]; then
		echo mem : $MEM
		echo IDEAL_MEM : $IDEAL_MEM
		echo t1  : "${INFO[1]}"
		echo t2  : "${INFO[2]}"
		echo total time : $TOTAL_TIME
		echo IDEAL_TIME : $IDEAL_TIME
	    fi

	    #compare output
	    DIFF=$(diff result.delme ../../../testcases/output/$QUESTION/$f)

	    if [ "$DIFF" != "" ] 
	    then
		FAILED=1

		echo "test "$f" failed : output mismatch"
		if [ "$DETAILED" -eq 1 ]; then
		    echo result : 
		    cat result.delme
		    echo correct result : 
		    cat ../../../testcases/output/$QUESTION/$f
		    read -p "Press any key to continue... " -n1 -s
		fi
	    else
		#compare time to be with in 1% of ideal
		RESULT=$(echo "$IDEAL_TIME*1.01 >= $TOTAL_TIME" | bc)
		if [ "$RESULT" -ne 1 ]; then 
		    FAILED=1

		    RESULT=$(echo "scale=2; $TOTAL_TIME / $IDEAL_TIME" | bc)
		    echo test $f failed : Time overflow, $RESULT times time consumed
		fi
		#compare memory to be with in 1% of ideal
		RESULT=$(echo "$IDEAL_MEM*1.01 >= $MEM" | bc)
		if [ "$RESULT" -ne 1 ]; then
		    FAILED=1

		    RESULT=$(echo "scale=2; $MEM / $IDEAL_MEM" | bc)
		    echo test $f failed : Memory overflow -----  $RESULT times memory used
		fi

		if [ "$FAILED" -ne 1 ]; then
		    echo "test "$f" Passed"
		    x=$(( x+1 ))
		fi
	    fi
	fi
    done

    cd ../..
    
    if [ "$GEN" -eq 1 ]; then
	break
    else
	echo
	echo tests passed ::::::::::::: $x
	echo Note : Minor deviation from ideal memory and time have been considered as pass
    fi
done
cd ..
