f = open('runJoca','w')

for i in range(1,34):
	f.write('./ijparser < testsInput_Joca/test'+str(i)+'.txt > OutCenas/joca'+str(i)+'.txt\n')
f.close()