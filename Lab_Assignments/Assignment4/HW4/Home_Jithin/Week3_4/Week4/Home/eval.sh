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

#setting memory limit 2MB
cd Submissions
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
    #gcc $QUESTION.c -o $QUESTION.out -lm

    if [ $GEN -eq 1 ]; then
	make
	make clean all
	
	t=20;

	for ((f=0; f<$t; f++))
	do
	    ./executables/$QUESTION < ../../testcases/input/$QUESTION/$f > ../../testcases/output/$QUESTION/$f
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
	t=20   #total number of test cases

	if [ ! -f ./executables/$QUESTION ]; then
	    echo
	    echo
	    echo "compilation failed"
	else
	    for ((f=0; f<$t; f++))
	    do
		#execute
		echo "ulimit -m 200000" > run_delme.sh
		echo "ulimit -v 200000" >> run_delme.sh
		echo "./executables/$QUESTION < ../../testcases/input/$QUESTION/$f > result.delme" >> run_delme.sh
		chmod +x run_delme.sh
		./run_delme.sh

		#sleep 1
		
		#compare output
		if [ ! -f result.delme ]; then
		    ls
		    echo execution $f failed
		else
		    FILESIZE=$(stat -c%s result.delme)
		    if (( $FILESIZE <= 200000 ));
		    then
			DIFF=$(diff result.delme ../../testcases/output/$QUESTION/$f)

			if [ "$DIFF" != "" ] 
			then
			    #failed
			    #echo "test "$f" failed"
			    x=$x
			else
			    echo "test "$f" passed"
			    x=$(( x+1 ))
			fi
		    else
			#size of file is too big
			#test failed
			echo the $f results file too big 
			x=$x
		    fi
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
