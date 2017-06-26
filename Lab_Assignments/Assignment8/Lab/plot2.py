import matplotlib.pyplot as plt
import sys,numpy

def plot(filename):
	with open(filename,"r") as reader:
		lst=[[] for i in range(4)]
		for lines in reader:
			lst_=map(float,lines.strip().split())
			for i in range(len(lst_)):
				lst[i].append(lst_[i])
		idx= numpy.argsort(numpy.array(lst[0]))
		lst=[[lst_[idx[i]] for i in range(len(idx))] for lst_ in lst]
		plt.plot(lst[0],lst[1],label='ascending order')
		plt.plot(lst[0],lst[2],label='descending order')
		plt.plot(lst[0],lst[3],label='randomly populated')
		plt.legend(loc=0)
		plt.title('input size Vs Running time')
		plt.xlabel('size')
		plt.ylabel('running-time')
		plt.show()

if __name__=='__main__':
	filename= sys.argv[1]
	plot(filename)