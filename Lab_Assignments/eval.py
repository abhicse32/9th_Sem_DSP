import sys,os
def evaluate(dir_name):
	testcases=os.listdir("testcases")
	solutions=os.listdir("solutions")
	

if __name__=='__main__':
	rollno= sys.argv[1]
	dir_name= rollno+"_PA1"
	if not os.path.exists(dir_name):
		tarname=dir_name+".tar.gz"
		zipname=dir_name+".zip"
		if os.path.exists(tarname):
			os.system("tar -xvf "+tarname)
		elif os.path.exists(zipname):
			os.system("unzip "+zipname)

	if not os.path.exists(dir_name):
		print "directory doesn't exist"
	else:
		evaluate(dir_name)