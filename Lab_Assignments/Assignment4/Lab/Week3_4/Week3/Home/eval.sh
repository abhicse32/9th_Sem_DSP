#!/bin/bash
if [ "$#" -ne 1 ]; then 
    echo "illegal number of parameters"
    echo "usage ./eval q1"
    exit
fi

if [ $1 == "q1" ]; then
    ./eval_generate_output.sh q1
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

    cd $STUD
    #compiling
    cp ../../Makefile_internal Makefile
    make clean all
    #gcc $QUESTION.c -o $QUESTION -lm

    if [ -f $QUESTION ];
    then
	if [ $GEN -eq 1 ];
	then
	    #generate the correct out put
	    ./$QUESTION <../../testcases/$QUESTION/0 > ../../testcases/$QUESTION/0.out
	else
	    #execute the program and redirect output
	    rm out2.txt
	    rm out3_bubble.txt
	    echo "&&&&&&&&&&&&"
	    ./$QUESTION <../../testcases/$QUESTION/0 > result.delme

	    #stat
	    x=0   #number of test cases passed
	    t=100   #total number of test cases

	    #check if the outputs are correct
	    for ((f=1; f<=$t; f++))
	    do
		#compare t'th lines
		echo "diff <(sed '${t}q;d' '../../testcases/$QUESTION/0.out') <(sed '${t}q;d' 'result.delme')" > command.delme
		chmod +x command.delme
		DIFF=$(./command.delme)

		if [ "$DIFF" != "" ] 
		then
		    #sorting failed
		    x=$x
		else
		    x=$(( x+1 ))
		fi
	    done
	    echo $x/100 correct sorting ::::::::::::: $x
	    
	    #check the code
	    #gedit Code/$QUESTION.c
	    #if [ $QUESTION == "q2" ]; then
	    #	gedit Code/q2_sort.c
	    #fi
	    #generate the plot
	    if [ $QUESTION == "q2" ]; then
		echo q2
		if [ -f out2.txt ];
		then
		    #generate plot
		    QUESTION=$QUESTION
		    rm *.png
		    python ../../plot2.py out2.txt
		    eog *.png
		else
		    echo out2.txt missing
		fi
	    else
		echo q3
		if [ -f out3_bubble.txt ];
		then
		    #generate plot
		    rm *.png
		    python ../../plot3.py
		    eog *.png
		else
		    echo out3_bubble.txt missing
		fi	    
	    fi
	fi
    else
	echo compilation failed
    fi
    
    cd ..

    if [ $GEN -eq 1 ];
    then
	break;
    fi
done
cd ..
