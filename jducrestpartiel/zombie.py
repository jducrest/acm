import sys
import math

def readline():
	return next(sys.stdin)[:-1]

N = int(readline())

for n in range(N):
	l = readline()
	l = l.split(' ')
	W = int(l[0])
	C = int(l[2])
	M = int(l[1])
	i = 0
	while W < M:
		i+=1
		W*=C
	
	r = math.log(i,2)
	r = math.ceil(r)
	print("Case #"+str(n+1)+": "+str(int(r)))
