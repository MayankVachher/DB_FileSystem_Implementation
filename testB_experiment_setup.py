import sys
import numpy as np

def main():
	if len(sys.argv) != 2:
		print "ABORT"
		exit()

	fname = sys.argv[1]
	counter = 1

	data = []

	with open(fname, 'r') as f:
		for line in f:
			data.append(line.strip())

	indexes = range(0,len(data)+1,5000)

	for ind1 in range(1,len(indexes)):
		for val in data[indexes[ind1-1]:indexes[ind1]]:
			print 'i'
			print val

		for i in range(50):
			print 's'
			ind2 = np.random.randint(0,ind1)
			print data[ind2]
		print 'c'
	print '0'


if __name__ == '__main__':
	main()