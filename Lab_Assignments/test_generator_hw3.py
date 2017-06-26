from random import randint
from subprocess import call,Popen,PIPE
import os

def gen_out(infile,testfile):
	noext=os.path.splitext(infile)[0]
	os.system("gcc -o "+noext+" "+infile)
	with open(testfile,"r") as reader:
		with open("ans_"+testfile[5:],"w") as writer:
			lines= int(reader.readline())
			for i in range(lines):
				ps=Popen("./"+noext, stdin=PIPE,stdout=PIPE,stderr=PIPE)
				out,err=ps.communicate(reader.readline())
				writer.write(out)


def create(filename):
	with open(filename,"w") as w:
		w.write("10\n")
		w.write(str(5431*19*73)+" "+str(5431*2*73)+"\n")
		w.write(str(653*19*73*149)+" "+str(149*2*653)+"\n")
		w.write(str(1291*2*3*29)+" "+str(2*3*29*23)+"\n")
		w.write(str(2027*41*47*3)+" "+str(41*2*17)+"\n")
		w.write(str(2*2*37*67)+" "+str(2*2*67*61)+"\n")
		w.write(str(7919*521)+" "+str(7919*2*521)+"\n")
		w.write(str(1777*23*271)+" "+str(271*23*7)+"\n")
		w.write(str(2*7*11*13*29)+" "+str(7*11*13*53)+"\n")
		w.write(str(389*397*2*7)+" "+str(389*7)+"\n")
		w.write(str(2*3*3*29*29)+" "+str(3*37*29*29)+"\n")

infile="hw1_3.c"
testfile= os.path.splitext(infile)[0]+"_test.txt"
create(testfile)
gen_out(infile,testfile)