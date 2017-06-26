import subprocess
import os
from os.path import join

def evaluate(qno, ansPath, outPath):
	if qno==2:
		with open(ansPath) as ansObj:
			ans = ansObj.readline().rstrip('\n')
		with open(outPath) as outObj:
			out = outObj.readline().rstrip('\n')

		ansWords = ans.split()
		outWords = out.split()

		if sorted(ansWords) == sorted(outWords):
			return 10
		else:
			return 0
	else:
		diff = os.system("diff -b "  + ansPath + " " + outPath)
		if(diff == 0):
			return 10
		else:
			return 0

marks = {}

for student in os.listdir("home"):
	qDir = join("home", student, "Code");
	rollNo = student[:-4]
	
	

	for qno in range(1,4):
		pstr = "p" + str(qno)
		qstr = "q" + str(qno)
		for tc in os.listdir("testcases/" + pstr + "/"):
			if tc[-1] == '~':
				continue
			tcPath = join("testcases", pstr, tc)
			if not os.path.exists(join(qDir, pstr)):
				os.makedirs( join(qDir, pstr))
			outPath = join(qDir, pstr, tc[:-3]+".out")
			try:		
				os.system("timeout 5 " + join(qDir, qstr) + " < " + tcPath + " > " + outPath)
				ansPath = "outputs/" + pstr + "/" + tc[:-3]+".out"
				
				if rollNo not in marks:
					marks[rollNo] = 0
				marks[rollNo] = marks[rollNo] + evaluate(qno, ansPath, outPath)
			except:
				pass

			
	#	if rollNo not in marks:
	#		marks[rollNo] = 0
	#	marks[rollNo] += evaluateq1(tcPath, outPath)

#	for tc in os.listdir("testcases/p2"):
#		tcPath = join("testcases", "p2", tc)
#		os.makedirs( join(qDir, "p2"))
#		outPath = join(qDir, "p2", tc[:-3]+".out")
#		subprocess.call([join(qDir, "q2"), "<", tcPath, ">", outPath])

	print(rollNo + " finished")

for item in sorted(marks.iteritems()):
	print item
