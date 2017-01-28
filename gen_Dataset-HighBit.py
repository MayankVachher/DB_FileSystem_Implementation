import numpy as np

def gen_numbers(range_min, range_max, size):
	return np.random.randint(range_min+1, range_max, size)

toGenSize1 = 70000
range_l1 = 700000
range_h1 = 800000

toGenSize2 = 30000
range_l2 = 0
range_h2 = 700000

with open('Dataset-HighBit.txt', 'w') as f:
	for i in gen_numbers(range_l1, range_h1, toGenSize1):
		f.write(str(i)+"\n")

	for i in gen_numbers(range_l2, range_h2, toGenSize2):
		f.write(str(i)+"\n")