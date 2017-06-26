#!/usr/bin/env python
from random import randint,choice,uniform
import random
from subprocess import call,Popen,PIPE
from string import ascii_lowercase
import os

solDir="solutions"
testDir="testcases"
progDir="CS12B032_HOME_2"
execs="executables"

def gen_out(infile,testfile):
    noext=os.path.splitext(infile)[0]
    execPath=os.path.join(execs,noext)
    ansPath= os.path.join(solDir,noext+".ans")
    progPath= infile
    os.system("gcc -o "+execPath+" "+progPath+" -lm")
    with open(testfile,"r") as reader:
        with open(ansPath,"w") as writer:
            lines= int(reader.readline())
            for i in range(lines):
                ps=Popen("./"+execPath, stdin=PIPE,stdout=PIPE,stderr=PIPE)
                if noext=='q1':
                    lst=[reader.readline() for k in range(3)]
                elif noext=='q2':
                    lst=[reader.readline() for k in range(4)]
                out,err=ps.communicate(os.linesep.join(lst))
                writer.write(out)

def generate2(w,size):
    w.write(str(size)+"\n")
    lst=[randint(-size,size) for i in range(size)]
    lst.sort()
    w.write(' '.join(map(str,lst))+"\n")

def create_lab2(infile):
    testfile=os.path.join(testDir,os.path.splitext(infile)[0]+".in")
    with open(testfile,"w") as w:
        w.write("10\n")
        for i in range(9):
            m=randint(1,40)
            generate2(w,m)
            m=randint(10,30)
            generate2(w,m)
        m=randint(50,100)
        generate2(w,m)
        m=randint(50,100)
        generate2(w,m)


def generate(w, size):
    w.write(str(size)+"\n")
    lst=random.sample(xrange(-size,size),size)
    lst.sort()
    w.write(' '.join(map(str,lst))+"\n")
    toss=randint(1,10)
    if toss<6:
        k=randint(size+1,size+10)
    else:
        k=lst[randint(0,size-1)]
    w.write(str(k)+"\n")

def create_lab1(infile):
    testfile=os.path.join(testDir,os.path.splitext(infile)[0]+".in")
    with open(testfile,"w") as w:
        w.write("10\n")
        # first 5-testcases won't have more than 100 elements in them
        for i in range(9):
            size=randint(10,10**2)
            generate(w,size)

        size=randint(500,10**3)
        generate(w,size)


if __name__=='__main__':
        if not os.path.exists(solDir):
            os.system("mkdir "+solDir)
        if not os.path.exists(testDir):
            os.system("mkdir "+testDir)
        if not os.path.exists(execs):
            os.system("mkdir "+execs)
        # create_lab1("q1.c")
        # create_lab2("q2.c")
        # gen_out("q2.c","testcases/q2.in")
