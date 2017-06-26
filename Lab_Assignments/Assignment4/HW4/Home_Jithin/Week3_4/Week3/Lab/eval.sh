#!/bin/bash
function minByMax {
    if [ $1 -ge $2 ];
    then
	min=$2
	max=$1
    else
	min=$1
	max=$2
    fi

    RESULT=$(echo "scale=2; $max/$min" | bc)
    echo -n $RESULT " "
}

if [ "$#" -ne 1 ]; then 
    echo "illegal number of parameters"
    echo "usage ./eval q1"
    exit
fi

DETAILED=0
QUESTION=$1
GEN=0 #generate the ideal output

echo Evaluating $QUESTION

cd Submissions
for STUD in *
do
    echo
    echo "*******************"
    echo Evaluating $STUD
    #read -p "Press any key to continue... " -n1 -s
    echo

    cd $STUD/Code
    #compiling
    gcc $QUESTION.c -o $QUESTION.out -lm

    #stat
    x=0   #number of small test cases passed
    t=20   #total number of test cases

    for ((f=0; f<$t; f++))
    do
	#execute the program and redirect output
	echo "./$QUESTION.out <../../../testcases/input/$QUESTION/$f > result.delme" > delme.sh
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

		#compare 1st lines
		echo "diff <(sed '1q;d' '../../../testcases/output/$QUESTION/$f') <(sed '1q;d' 'result.delme')" > command.delme
		chmod +x command.delme
		DIFF=$(./command.delme)

		if [ "$DIFF" != "" ];
		then
		    #this is an actual failed test
		    echo "test "$f" failed : output mismatch"
		else
		    x=$(( x+1 ))
		    #the index displayed are wrong
		    echo "min/max ratio of your index and correct index : "
		    a1=$(tail -n 1 result.delme | cut -d " " -f 1)
		    a2=$(tail -n 1 result.delme | cut -d " " -f 2)
		    a3=$(tail -n 1 result.delme | cut -d " " -f 3)

		    b1=$(tail -n 1 ../../../testcases/output/$QUESTION/$f | cut -d " " -f 1)
		    b2=$(tail -n 1 ../../../testcases/output/$QUESTION/$f | cut -d " " -f 2)
		    b3=$(tail -n 1 ../../../testcases/output/$QUESTION/$f | cut -d " " -f 3)

		    #RESULT=$(echo "scale=2; ($a1/$b1) + ($a2/$b2) + ($a3/$b3)" | bc)
		    #echo -n $a1/$b1 : $a2/$b2 : $a3/$b3
		    #echo " $RESULT"
		    minByMax $a1 $b1
		    minByMax $a2 $b2
		    minByMax $a3 $b3
		    echo
		fi

		if [ "$DETAILED" -eq 1 ]; then
		    read -p "Press any key to continue... " -n1 -s
		fi
	    else
		#compare time to be with in 1% of ideal
		RESULT=$(echo "$IDEAL_TIME*1.01 >= $TOTAL_TIME" | bc)
		if [ "$RESULT" -ne 1 ]; then 
		    FAILED=1

		    RESULT=$(echo "scale=20; $TOTAL_TIME / $IDEAL_TIME" | bc)
		    echo test $f failed : Time overflow, $RESULT times extra time consumed
		fi
		#compare memory to be with in 1% of ideal
		RESULT=$(echo "$IDEAL_MEM*1.01 >= $MEM" | bc)
		if [ "$RESULT" -ne 1 ]; then
		    FAILED=1

		    RESULT=$(echo "scale=20; $MEM / $IDEAL_MEM" | bc)
		    echo test $f failed : Memory overflow -----  $RESULT times memory used
		fi

		if [ "$FAILED" -ne 1 ]; then
		    echo "test "$f" Passed"
		    x=$(( x+1 ))
		fi
	    fi
	fi
    done

    echo
    echo $x tests passed ::::::::: $x
    echo NOTE : I have given marks for small deviation from ideal memory and time
    
    #gedit $QUESTION.c
    cd ../..
    
    if [ "$GEN" -eq 1 ]; then
	break
    fi
done
cd ..
