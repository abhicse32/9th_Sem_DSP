import re,sys,os
from subprocess import Popen, PIPE
def extract(filename):
	pattern=r"[cCAaEemM][sSEemM]([0-9])+[a-zA-Z]([0-9])+[_]([a-zA-Z0-9_])+"
	compiled= re.compile(pattern)
	dest="Home/"
	if not os.path.exists(dest):
		os.system("mkdir "+dest)
	for dirs, subdirs, files in os.walk(filename):
		for file in files:
			str_=os.path.join(filename,"\""+file+"\"")
			match=compiled.search(file)
			if match:
				roll_num=(match.group()[:8]).upper()
				dir_name=os.path.join(dest,roll_num)
				# print dir_name
				if not os.path.exists(dir_name):
					os.system("mkdir "+dir_name)
				if file.endswith("tar") or file.endswith("gz"):
					os.system("tar -xvf "+str_+" -C "+dir_name)
				elif file.endswith("rar"):
					os.system("unrar e "+str_+" "+dir_name)
				elif file.endswith("zip"):
					os.system("unzip "+str_+" -d "+dir_name)
			else:
				print file

def removeDirs(dirname):
	lst= os.listdir(dirname)
	for dirs in lst:
		subdirname= os.path.join(dirname,dirs)
		if os.path.isdir(subdirname):
			subdir_lst= os.listdir(subdirname)
			for contents in subdir_lst:
				subpath= os.path.join(subdirname,contents)
				if os.path.isdir(subpath):
					files= os.path.join(subpath,"*.c")
					os.system("cp "+files+" "+subdirname+"; rm -rf "+subpath)

def renameFiles(dirname):
	compiled= re.compile(r"[1-5]\.c")
	for dirs, subdirs, files in os.walk(dirname):
		for file in files:
			if file.endswith(".c"):
				match= compiled.search(file)
				path= os.path.join(dirs,file)
				newPath= os.path.join(dirs,"q"+match.group())
				os.system("mv "+path+" "+newPath)

def evaluate(dirname):
	dirsList= os.listdir(dirname)
	for dirs in dirsList:
		dirPath= os.path.join(dirname,dirs)
		print dirs
		os.system("./eval "+dirPath)



if __name__=='__main__':
	dirname=sys.argv[1]
	# extract(dirname)
	# dirname= sys.argv[1]
	removeDirs(dirname)
	# renameFiles(dirname)
	# evaluate(dirname)