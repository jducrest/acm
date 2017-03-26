import sys

primes = [True, True, True, True, False, True, False, True, False, False, False, True, False, True, False, False, False, True, False, True, False, False, False, True, False, False, False, False, False, True, False, True, False, False, False, False, False, True, False, False]

affichage = ""

def is_prime(x):
	return primes[x]
	
	
def print_(l):
	l_ = [str(x) for x in l]
	l_ = " ".join(l_)
	global affichage
	affichage += l_ 
	affichage += "\n"
	if(len(affichage)>1000):
		sys.stdout.write(affichage)
		affichage = ""

def back_track(l,n):
	global t
	flag = True
	for i in range(2,n+1):
		if t[i] == False:
			flag = False
			if is_prime(l[-1]+i):
				t[i] = True
				l.append(i)
				back_track(l,n)
				l.pop()
				t[i] = False
	if flag and is_prime(l[-1]+l[0]):
		print_(l)				
			
			
k = 1		
for l in sys.stdin:
	n = int(l)
	l = [1]
	t = [False for i in range(2*n)]
	print("Case "+str(k)+":")
	back_track(l,n)
	print(affichage)
	affichage = ""
	k+=1
