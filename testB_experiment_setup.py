import sys

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

	indexes = range(0,len(data),5000)


if __name__ == '__main__':
	main()