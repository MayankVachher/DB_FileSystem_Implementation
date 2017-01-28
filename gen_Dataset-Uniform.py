import numpy as np

def gen_numbers(range_min, range_max, size):
	return np.random.randint(range_min+1, range_max, size)

toGenSize = 100000
range_l = 0
range_h = 800000

with open('Dataset-Uniform.txt', 'w') as f:
	for i in gen_numbers(range_l, range_h, toGenSize):
		f.write(str(i)+"\n")