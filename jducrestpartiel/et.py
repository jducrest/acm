import sys

def readline():
	return next(sys.stdin)[:-1]


def sortie(n,k):
	print("Case #"+str(n+1)+": "+str(k))
	return

N = int(readline())
d = dict()
for n in range(N):
	d.clear()
	l = readline()
	d[l[0]] = 1
	zerounused = True
	
	i = 2
	for c in l:
		if c not in d:
			if c == '\r':
				continue
			if zerounused:
				d[c] = 0
				zerounused = False
			else:
				d[c] = i
				i += 1
	base = i # le nombre d'elements qu'on a
	result = 1
	for c in l[1::]:
		if c != '\r':
			result*=base
			result+=d[c]
	
	sortie(n,result)	

