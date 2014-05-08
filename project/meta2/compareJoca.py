f = open('compareJoca','w')

for i in range(1,34):
	f.write('meld testsOutput_Joca/out_test'+str(i)+'.txt OutCenas/joca'+str(i)+'.txt\n')
f.close()