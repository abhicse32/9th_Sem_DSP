#!/bin/bash
for ((f=1; f<=11; f++))
do
    ./a.out < TestCases/input/input${f}.txt > TestCases/output/output${f}.txt
done
