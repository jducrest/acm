import sys

#une manière très classe de gerer les input faire des boucles infinies et try except pour chopper la sortie


def readline():
	return next(sys.stdin)[:-1]

n = int(readline())
for k in range(1,n+1):
	l = readline()
	out = ""
	out += "Case "
	out += str(k)
	out += ": "
	i = 0
	while i<len(l):
		c = l[i]
		i+=1
		try:
			m = int(l[i])
		except:
			break
		try :
			while True:
				i+=1
				m = m*10+int(l[i])
		except:
			i-=1
		out+=c*m
		i+=1
	print(out)
