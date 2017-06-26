from random import randint
from subprocess import call,Popen,PIPE
import os

def gen_out(infile,testfile):
	noext=os.path.splitext(infile)[0]
	os.system("gcc -o "+noext+" "+infile)
	with open(testfile,"r") as reader:
		with open(noext+"_ans.txt","w") as writer:
			lines= int(reader.readline())
			for i in range(lines):
				ps=Popen("./"+noext, stdin=PIPE,stdout=PIPE,stderr=PIPE)
				out,err=ps.communicate(os.linesep.join([reader.readline(),reader.readline()]))
				writer.write(out)

def create(filename):
	with open(filename,"w") as w:
		w.write("20\n")
		for i in range(19):
			size=randint(2,100)
			w.write(str(size)+"\n")
			w.write(' '.join(map(str,[randint(-10**4,10**4) for j in range(size)]))+"\n")
		
		size=randint(1,10**5)		
		w.write(str(size)+"\n")
		w.write(' '.join(map(str,[randint(-10**4,10**4) for j in range(size)]))+"\n")

infile="hw1_1.c"
testfile=os.path.splitext(infile)[0]+"_test.txt"
create(testfile)
gen_out(infile,testfile)