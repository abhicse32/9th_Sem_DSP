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
	with open(filename,"w") as writer:
		writer.write("20\n")
		for i in range(20):
			writer.write(str(randint(1,10**4))+"\n")

infile="hw1_5.c"
testfile= os.path.splitext(infile)[0]+"_test.txt"
create(testfile)
gen_out(infile,testfile)