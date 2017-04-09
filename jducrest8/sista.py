import sys

debug = False


mat = [[0 for k_ in range(50)] for k in range(50)]
S = set()


def readline():
	return next(sys.stdin)[:-1]

def dfs(s):
	S.add(s)
	for v in range(50):
			if mat[s][v] != 0 and v not in S:
				dfs(v)

def eulerianpath(x):
	l = []
	flag = True
	y = x
	while y != x or flag :
		flag = False
		for i in range(50):
			if mat[y][i] > 0:
				l.append(y)
				mat[y][i] -= 1
				mat[i][y] -= 1
				y = i
	l_ = []
	for y in l:
		l_+=eulerianpath(y)
		l_.append(y)
	return l_
	


N = int(readline())    # on recup le nombre de tests
n = 1
for n in range(1,N+1):


	#init de la matrice
	for i in range(50):
		for j in range(50):
			mat[i][j] = 0
	
	nb_beads = int(readline())

	# entry recuperation
	for k in range(nb_beads):
		l = readline().split(" ")
		mat[int(l[0])-1][int(l[1])-1]+=1
		mat[int(l[1])-1][int(l[0])-1]+=1
		i+=1

	# pour faire plaisir a euler, on teste si tout les sommets ont degre pair
	flag = True
	for k in range(50):
		if sum(mat[k])%2:
			flag = False
			break
	

	S.clear()
	dfs(0)                              # /!\ on suppose que la couleur 1 apparait a chaque fois (vrai?)
	S_ = set()
	for j in range(50):
		for j_ in range(50):
			if mat[j][j_] != 0:
				S_.add(j)
				S_.add(j_)

	# le graphe n'est pas connexe, tant pis
	if S != S_: 
		if debug : print(" non connexe" )
		flag = False

	print("Case #"+str(n))

	if flag == False:
		print("some beads may be lost")
		continue  	
	else:	
		l = eulerianpath(0)
		for i in range(len(l)):
			print(str(l[i%len(l)]+1)+" "+str(l[(i+1)%len(l)]+1))
