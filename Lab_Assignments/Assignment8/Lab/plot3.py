import matplotlib.pyplot as plt
import sys,numpy,re,os

def plot(filename):
	with open(filename,"r") as reader:
		lst=[[] for i in range(4)]
		# print filename
		for lines in reader:
			lst_=map(float,lines.strip().split())
			for i in range(len(lst_)):
				lst[i].append(lst_[i])
		idx= numpy.argsort(numpy.array(lst[0]))
		lst=[[lst_[idx[i]] for i in range(len(idx))] for lst_ in lst]
		plt.plot(lst[0],lst[1],label='unsorted')
		plt.plot(lst[0],lst[2],label='sorted_ascending')
		plt.plot(lst[0],lst[3],label='sorted_descending')
		plt.legend(loc=0)
		plt.title(re.search(r'[_][a-zA-Z]+',os.path.basename(filename)).group()[1:]+" sort")
		plt.xlabel('Size')
		plt.ylabel('Running-time')
		plt.show()

if __name__=='__main__':
	path="CS12B032_HOME"
	files=['out3_insertion.txt','out3_selection.txt','out3_bubble.txt','out3_quick.txt','out3_merge.txt']
	for file in files:
		plot(os.path.join(path,file))