import sys

def tri_radis(t,l):
	for i in l:
		t0=[]
		t1=[]
		for x in t:
			if x[i]==0:
				t0.append(x)
			else:
				t1.append(x)
		t=t0+t1
	return t

#are equals mod k		
def are_diff(u,v,l):
	for i in l:
		if u[i]!=v[i]:		#if they have a digit of difference then they are diff
			return True
	return False				#else they are similar

def compute_parts(n):
	l_ = []
	if n != 0:
		l = compute_parts(n-1)		
		for x in l:
			x_ = list(x)
			x_.append(n-1)
			l_.append(x)
			l_.append(x_)
	else:
		l_ = [[]]
	return l_


res = ""
nb_exp = int(sys.stdin.readline())

for k in range(nb_exp):
	# recuperation d'infos
	minimum = 20
	nb_leds = int(sys.stdin.readline())	
	nb_symb = int(sys.stdin.readline())
	symbs = []
	for i in range(nb_symb):
		line = sys.stdin.readline()
		symbs.append([int(x) for x in line.split()])	
	
	
	#on calcule les parties:
	
	parts = compute_parts(nb_leds)
	
	for l in parts:
		symbs = tri_radis(symbs,l)
		flag = True
		for i in range(nb_symb-1):
			if not are_diff(symbs[i],symbs[i+1],l):
				flag = False
				break
		if flag:
			minimum = min(minimum,len(l))
	res+=str(minimum)+"\n"
	print(res[:-1])

		
		
		
		
		
		
