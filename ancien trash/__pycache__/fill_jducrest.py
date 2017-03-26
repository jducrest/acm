import sys


def safe_sum(l):
	if l == []:
		return 0
	else :
		return sum(l)


odd = False
n = 0
cont = []
for line in sys.stdin.read().split("\n"):
	if line == "":
		continue
	line = [int(x) for x in line.split()]
	if not odd:
		n=line[1]
		odd = True  	#la prochaine saisie est un vrai test
	else:
		odd = False     #la prochaine fois on part sur un nouveaux test		
		cont = line
		
		if n >= len(cont):
			print (max(cont))
			continue
			
		
		
		
		opt = [i for i in range(n+1)]
		opt[-1]=len(cont)+1
		
		sums = [safe_sum(cont[opt[i]:opt[i+1]]) for i in range(n)] 
		
		#print(sums)
		
		flag = True

		while(flag):
			flag = False
			for i in reversed(range(n-1)):
					u = sums[i+1]
					u_ = sums[i+1]-cont[opt[i+1]]
					t_ = sums[i]+cont[opt[i+1]] 
					while  t_ < u:    #if
						opt[i+1]+=1
						sums[i] = t_
						sums[i+1] = u_
						flag = True
						u = sums[i+1]
						u_ = sums[i+1]-cont[opt[i+1]]
						t_ = sums[i]+cont[opt[i+1]]
			
			
			if flag == False:                  #on a pas reussi a baisser le max, on essaye une autre technique			
				cur_max = -1
				sum_max = 0
				for i in range(n):
					if sums[i] > sum_max:
						sum_max = sums[i]
						cur_max = i
			
				for i in reversed(range(cur_max-1)):
					if sums[i]+cont[opt[i+1]] < sum_max:
						u_ = sums[i+1]-cont[opt[i+1]]
						t_ = sums[i]+cont[opt[i+1]] 
						sums[i] = t_
						sums[i+1] = u_
						opt[i+1]+=1
						flag = True
						break 
			#print(sums)
			#print(opt)
		  
		print(max(sums))	
		
	
