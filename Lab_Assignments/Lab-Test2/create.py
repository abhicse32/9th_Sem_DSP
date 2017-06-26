#!/usr/bin/env python
import string
import random,os
def generate():
	str_=string.digits+string.ascii_uppercase+ string.ascii_lowercase
	str_=''.join(random.sample(str_,len(str_)))
	return str_

def gen2():
	dir_path='testcases/labtest2_prob2/'
	for i in range(1,11):
		filepath= os.path.join(dir_path,"test"+str(i)+".in")
		with open(filepath,"w") as writer:
			num= random.randint(100,1000)
			writer.write(str(num)+"\n")
			lst= random.sample(range(10,10000),num)
			writer.write(' '.join(map(str,lst))+"\n")

if __name__=='__main__':
	# str_=generate()
	# num= random.randint(20,len(str_))
	# print str_[:num]
	gen2()