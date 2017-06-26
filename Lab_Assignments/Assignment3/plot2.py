import matplotlib.pyplot as plt
import sys,numpy

def plot(filename):
	with open(filename,"r") as reader:
		lst=[[] for i in range(6)]
		for lines in reader:
			lst_=map(float,lines.strip().split())
			for i in range(len(lst_)):
				lst[i].append(lst_[i])
		idx= numpy.argsort(numpy.array(lst[0]))
		lst=[[lst_[idx[i]] for i in range(len(idx))] for lst_ in lst]
		plt.plot(lst[0],lst[1],label='selection_sort')
		plt.plot(lst[0],lst[2],label='bubble_sort')
		plt.plot(lst[0],lst[3],label='insertion_sort')
		plt.plot(lst[0],lst[4],label='quick_sort')
		plt.plot(lst[0],lst[5],label='merge_sort')
		plt.legend(loc=0)
		plt.title('Running times of sorting algorithms')
		plt.xlabel('Size')
		plt.ylabel('running-time')
		plt.show()

if __name__=='__main__':
	filename= sys.argv[1]
	plot(filename)