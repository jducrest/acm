# prog dyn en O(n^2)
# on garde la solution optimale pour 1, 2, ... n missiles
# si un missile peut s'inserer derriere le missile n et que sa hauteur est supérieure a la solution actuelle a n+1 missiles,
# alors on a un nouveau optimum pour n+1 missiles.


import sys

flag = False
opt = []
it=0
while True:
	line = sys.stdin.readline()
	x = int(line)
	if x == -1 :
		if not flag:
			break;
		else:
			it+=1
			if(it!=1):
				print()
			maximum = str(len(opt))
			print('Test #'+str(it)+':')
			if maximum != 0:
				print('  maximum possible interceptions: '+str(len(opt)))
			else:
				print('')
			opt = []
			flag = False
	else:
		flag = True
		if len(opt)==0:
			opt.append(x)
		else:
			for i in reversed(range(len(opt))):
				val = opt[i]
				if(val>=x):
					if(i<len(opt)-1):
						opt[i+1]=max(x,opt[i+1])
					elif(i==len(opt)-1):
						opt.append(x)
			opt[0]=max(opt[0],x)
