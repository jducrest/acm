import sys

d = {};
line=sys.stdin.readline()
for i in range(int(line)):
	line=sys.stdin.readline()
	line = line.split()
	if(len(line)!=0):
		if(d.get(line[0])==None):
			d[line[0]]=1
		else :
			d[line[0]]+=1

for (key,count) in sorted(d.items()):
	print(key,count)
	
