#!/usr/bin/env python
from __future__ import division
import  sys,os,re
from difflib import Differ
from subprocess import call,Popen,PIPE
solDir,outDir,execDir,testDir="solutions","outputs","executables","testcases"
problem1 , problem2,problem3 = "problem1", "problem2", "problem3"

def execute(opts="all"):
    os.system("make clean")
    os.system("make " + opts)

    execs= [f for f in os.listdir(execDir) if not f.startswith(".") and not f.startswith("~")]
    for noext in execs:
        if noext == "q1":
            testPath = os.path.join(testDir,problem1,noext+".inp")
            outPath = os.path.join(outDir,problem1,noext+".out")
            execPath = os.path.join(execDir,noext)
            if not os.path.exists(outPath):
                os.system("mkdir "+os.path.join(outDir,problem1))

            os.system("./"+execPath+" < "+testPath+" > "+outPath)

        elif noext == "q2":
            testPath = os.path.join(testDir,problem2,noext+".inp")
            outPath = os.path.join(outDir,problem2,noext+".out")
            execPath = os.path.join(execDir,noext)
            if not os.path.exists(outPath):
                os.system("mkdir "+os.path.join(outDir,problem2))

            os.system("./"+execPath+" < "+testPath+" > "+outPath)

        else:
            testPath = os.path.join(testDir,problem3,noext+".inp")
            outPath = os.path.join(outDir,problem3,noext+".out")
            execPath = os.path.join(execDir,noext)
            if not os.path.exists(outPath):
                os.system("mkdir "+os.path.join(outDir,problem3))

            os.system("./"+execPath+" < "+testPath+" > "+outPath)


def supportFunc(sol_path,out_path,noext):

    print "evaluating %s.c"%(noext)
    with open(sol_path,"r") as sol_reader:
        with open(out_path,"r") as out_reader:
            d = Differ()
            total,passed=0,0
            for sol_line in sol_reader:
                total+=1
                for out_line in out_reader:
                    if " ".join( out_line.strip()) == " ".join(sol_line.strip()):
                        # print "line %d: passed"%total
                        passed=passed+1
                        break

                    else:
                    	result = list(d.compare(out_line.strip(), sol_line.strip() ) )
                    	print noext , "=", out_line.strip() , "\t" , sol_line.strip()

                        # print "line %d:failed"%total
                        break
            print "result: %d/%d passed"%(passed,total)
            return (passed/float(total))*100

def evaluate():
    marks1 = 0
    marks2 = 0
    marks3 = 0

    execs= [file for file in os.listdir(execDir) if not file.startswith(".") and not file.startswith("~")]
    for noext in execs:
        if noext == "q1":
            sol_path,out_path= os.path.join(solDir,problem1,noext+".ans"),os.path.join(outDir,problem1,noext+".out")
            marks1 = supportFunc(sol_path,out_path,noext)
        
        elif noext == "q2":
            sol_path,out_path= os.path.join(solDir,problem2,noext+".ans"),os.path.join(outDir,problem2,noext+".out")
            marks2 = supportFunc(sol_path,out_path,noext)
            # print marks2
        else:
            sol_path,out_path= os.path.join(solDir,problem3,noext+".ans"),os.path.join(outDir,problem3,noext+".out")
            marks3 = supportFunc(sol_path,out_path,noext)
            # print marks3

    print marks1 , marks2,marks3
    with open("result.txt", "w+") as myfile:
        myfile.write("Final Marks = " + str( (marks1/9)*0.5 + marks2*0.25 + marks3*0.25 ))

    print "Final Marks = " + str( marks1*0.4 + marks2*0.3 + marks3*0.3 )

if __name__=='__main__':
    opts="all"
    if len(sys.argv)>1:
        opts=' '.join(sys.argv[1:])
    if not os.path.exists(outDir):
        os.system("mkdir "+outDir)
        os.system("mkdir "+outDir+"/"+problem1)
        os.system("mkdir "+outDir+"/"+problem2)
        os.system("mkdir "+outDir+"/"+problem3)

    # print opts
    execute(opts)
    evaluate()
