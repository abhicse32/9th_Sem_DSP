from random import randint,choice,uniform
from subprocess import call,Popen,PIPE
from string import ascii_lowercase
import os

def gen_out(infile,testfile):
	noext=os.path.splitext(infile)[0]
	os.system("gcc -o "+noext+" "+infile+" -lm")
	with open(testfile,"r") as reader:
		with open(noext+".ans","w") as writer:
			lines= int(reader.readline())
			for i in range(lines):
				ps=Popen("./"+noext, stdin=PIPE,stdout=PIPE,stderr=PIPE)
				if noext=='hw1_1':
					lst=[reader.readline() for i in range(2)]
				elif noext=='lab1_1':
					lst=[reader.readline() for i in range(3)]
				else:
					lst=[reader.readline()]
				out,err=ps.communicate(os.linesep.join(lst))
				writer.write(out)

def gen_out1(infile,testfile):
	noext=os.path.splitext(infile)[0]
	os.system("gcc -o "+noext+" "+infile+" -lm")
	with open(testfile,"r") as reader:
		with open(noext+".ans","w") as writer:
			lines= int(reader.readline())
			for i in range(lines):
				ps=Popen("./"+noext, stdin=PIPE,stdout=PIPE,stderr=PIPE)
				out,err=ps.communicate(os.linesep.join([reader.readline(),reader.readline()]))
				writer.write(out)

def gen_out_lab1(infile,testfile):
	noext=os.path.splitext(infile)[0]
	os.system("gcc -o "+noext+" "+infile+" -lm")
	with open(testfile,"r") as reader:
		with open(noext+".ans","w") as writer:
			lines= int(reader.readline())
			for i in range(lines):
				ps=Popen("./"+noext, stdin=PIPE,stdout=PIPE,stderr=PIPE)
				out,err=ps.communicate(os.linesep.join([reader.readline(),reader.readline(),reader.readline()]))
				writer.write(out)

def create1(infile):
	testfile=os.path.splitext(infile)[0]+".in"
	with open(testfile,"w") as w:
		w.write("20\n")
		for i in range(19):
			size=randint(2,100)
			w.write(str(size)+"\n")
			w.write(' '.join(map(str,[randint(-10**4,10**4) for j in range(size)]))+"\n")
		
		size=randint(1,10**4)		
		w.write(str(size)+"\n")
		w.write(' '.join(map(str,[randint(-10**4,10**4) for j in range(size)]))+"\n")
	gen_out(infile,testfile)

def create2(infile):
	testfile=os.path.splitext(infile)[0]+".in"
	with open(testfile,"w") as w:
		w.write("20\n")
		for i in range(10):
			w.write(str(randint(1,10**4))+"\n")
			w.write(str(randint(1,10**8))+"\n")
	gen_out(infile,testfile)

def create3(infile):
	testfile=os.path.splitext(infile)[0]+".in"
	with open(testfile,"w") as w:
		w.write("20\n")
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
		w.write(str(2*3*46061*5)+" "+str(3*5*46061)+"\n")
		w.write(str(787*45763)+" "+str(3*37*45763)+"\n")
		w.write(str(14897*93*59)+" "+str(59*14897*11)+"\n")
		w.write(str(1627*1637)+" "+str(1627*1181)+"\n")
		w.write(str(19*17*53*67)+" "+str(51*19*67)+"\n")
		w.write(str(25*81)+" "+str(19*39*10)+"\n")
		w.write(str(13*19*29*37*41)+" "+str(10*13*19*29*37)+"\n")
		w.write(str(883*751*79)+" "+str(883*79*73)+"\n")
		w.write(str(2*5*7*11*13*19)+" "+str(9*5*7*11*13*19)+"\n")
		w.write(str(12)+" "+str(32)+"\n")
	gen_out(infile,testfile)

def permute(str1,l):
	str2=""
	while l:
		k=randint(0,l-1)
		str2+=(str1[k])
		str1=str1[:k]+str1[k+1:]
		l-=1
	return str2

def create4(infile):
	testfile= os.path.splitext(infile)[0]+".in"	
	with open(testfile,"w") as writer:
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
	gen_out(infile,testfile)

def create5(infile):
	testfile= os.path.splitext(infile)[0]+".in"	
	with open(testfile,"w") as writer:
		writer.write("20\n")
		for i in range(20):
			writer.write(str(randint(1,10**4))+"\n")
	gen_out(infile,testfile);


def create_lab1(infile):
	testfile= os.path.splitext(infile)[0]+".in"	
	with open(testfile,"w") as writer:
		writer.write("20\n")
		for i in range(20):
			writer.write(str("{0:.6f}".format(uniform(1,100)))+" "+str("{0:.6f}".format(uniform(1,100)))+"\n")
			writer.write(str("{0:.6f}".format(uniform(1,100)))+" "+str("{0:.6f}".format(uniform(1,100)))+"\n")
			writer.write(str(randint(1,5))+"\n")
	gen_out(infile,testfile)	

#create1("hw1_1.c")
# create2("hw1_2.c")
create3("hw1_3.c")
# create4("hw1_4.c")
# create5("hw1_5.c")
# create_lab1("lab1_1.c")
# create1("lab1_2.c")