from random import randint,choice
from subprocess import call,Popen,PIPE
from string import ascii_lowercase
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

def permute(str1,l):
	str2=""
	while l:
		k=randint(0,l-1)
		str2+=(str1[k])
		str1=str1[:k]+str1[k+1:]
		l-=1
	return str2

def create(filename):
	with open(filename,"w") as writer:
		writer.write("20\n")
		for i in range(20):
			len_=randint(2,100)
			str1=''.join(choice(ascii_lowercase) for i in range(len_))
			if randint(0,1):         #coin toss :P
				str2=permute(str1,len_)
			else:
				len_=randint(2,100)
				str2=''.join(choice(ascii_lowercase) for i in range(len_))
			writer.write(str1+" "+str2+"\n")

infile="hw1_4.c"
testfile= os.path.splitext(infile)[0]+"_test.txt"
create(testfile)
gen_out(infile,testfile)