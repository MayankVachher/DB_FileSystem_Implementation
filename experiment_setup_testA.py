with open('Dataset-Uniform.txt', 'r') as f:
	with open('TestA_file_Uniform', 'w') as g:
		for line in f:
			if line.strip() == '':
				g.write('0')
			g.write('i\n'+line)
		g.write('0')

with open('Dataset-HighBit.txt', 'r') as f:
	with open('TestA_file_HighBit', 'w') as g:
		for line in f:
			if line.strip() == '':
				g.write('0')
			g.write('i\n'+line)
		g.write('0')