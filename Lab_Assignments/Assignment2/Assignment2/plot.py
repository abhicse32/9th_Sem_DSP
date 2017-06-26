from csv import reader
from matplotlib import pyplot


with open('output.csv', 'r') as f:
    data = list(reader(f))
    
itdata = [i[0] for i in data]
recdata = [i[1] for i in data]
pyplot.plot(range(len(itdata)), itdata)
pyplot.plot(range(len(recdata)), recdata)
pyplot.show()


