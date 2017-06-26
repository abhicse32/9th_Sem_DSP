import re,sys,os
def extract(filename):
	pattern=r"[cCAaEe][sSEe]([0-9])+[a-zA-Z]([0-9])+[_]([a-zA-Z0-9_])+"
	compiled= re.compile(pattern)
	dest="../Home/"
	for dirs, subdirs, files in os.walk(filename):
		for file in files:
			str_="\""+file+"\""
			match=compiled.search(file)
			if match:
				roll_num=(match.group()[:8]).upper()
				dir_name=os.path.join(dest,roll_num)
				print dir_name
				if not os.path.exists(dir_name):
					os.system("mkdir "+dir_name)
				if file.endswith("tar") or file.endswith("gz"):
					os.system("tar -xvf "+str_+" -C "+dir_name)
				elif file.endswith("rar"):
					os.system("unrar e "+str_+" "+dir_name)
				elif file.endswith("zip"):
					os.system("unzip "+str_+" -d "+dir_name)

def removeDirs(dirname):

if __name__=='__main__':
	# filename=sys.argv[1]
	
	extract(filename)