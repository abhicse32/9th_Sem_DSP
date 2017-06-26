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
    read -p "Press any key to continue... " -n1 -s
    #sleep 5
    echo

    cd $STUD
    #compiling
    #copy make file and make
    cp ../../Makefile .
    make clean all
    #gcc $QUESTION.c -o $QUESTION.out -lm

    if [ $GEN -eq 1 ]; then
	make clean all
	
	t=5;

	for ((f=0; f<$t; f++))
	do
	    ./executables/$QUESTION < ../../testcases/$QUESTION/input/$f > ../../testcases/$QUESTION/output/$f
	done
    else	
	#if [ "$QUESTION" == "q1" ];
	#then
	#    #evaluate q1
	#    #copy the run script
	#    cp ../../testcases/q1/run .
	#    #./run
	#else
	#    #evaluating q2
	#    #compile
	#    make clean all
	#fi

	#compile
	make
	make clean all

	#evaluate
	#stat
	x=0   #number of small test cases passed
	t=6   #total number of test cases

	if [ "$QUESTION" == "q2" ];
	then
	    t=7
	fi

	if [ ! -f ./executables/$QUESTION ]; then
	    echo "compilation failed"
	else
	    for ((f=1; f<$t; f++))
	    do
		#execute
		./executables/$QUESTION < ../../testcases/$QUESTION/input/$f > result.delme
		
		#compare output
		DIFF=$(diff result.delme ../../testcases/$QUESTION/output/$f)
		if [ "$QUESTION" == "q1" ];
		then
		    DIFF=$(diff <(sort result.delme) <(sort ../../testcases/$QUESTION/output/$f))
		fi
		if [ "$QUESTION" == "q2" ];
		then
		    if [ $f -eq 3 ];
		    then
			if [ "$DIFF" != "" ]
			then
			    #we have to check other possible output
			    DIFF=$(diff result.delme ../../testcases/$QUESTION/output/3_2)
			fi
		    fi
		fi

		if [ "$DIFF" != "" ] 
		then
		    #failed
		    #echo $DIFF
		    echo "test "$f" failed"
		    if [ "$QUESTION" == "q1" ];
		    then
			echo your output
			sort result.delme
			echo
			echo correct output
			sort ../../testcases/$QUESTION/output/$f
		    else
			echo your output
			cat result.delme
			echo
			echo correct output
			cat ../../testcases/$QUESTION/output/$f
		    fi
		    read -p "Press any key to continue... " -n1 -s
		else
		    x=$(( x+1 ))
		fi
	    done
	    
	    echo
	fi
	echo $x tests passed ::::::::: $x $STUD
    fi
    cd ..
    if [ $GEN -eq 1 ]; then
	break
    fi
done
cd ..
