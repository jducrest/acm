#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimum(int a,int b)
{
	if (a < b)
	return a;
	else
	return b;
}


int main()
{
	vector<int> adj[1000];
	int next[1000];
	bool used[1000];
	int n,N,p,P,d,D,x,y,i,j,p_,min;
	cin >> N;
	for(n=0;n<N;n++)
	{
		cin >> P >> D;
		for(d=0;d<D;d++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		// dijk
		for(p=0;p<P;p++)
		{
			next[p] = 1 << 30;
			used[p]= false;
		}
		next[0]=0;
		for(p=0;p<P;p++)
		{
			// on extrait le min
			min = -1;
			for(p_=0;p_<P;p_++)
				if(!used[p_])
					if(min == -1)
						min = p;
					else if (next[p] < next[min])
						min = p;
			
			used[min]=true;
			// on applique la relaxation
			x = min;
			for(i=0;i<adj[x].size();i++)
				next[adj[x][i]]= minimum(next[adj[x][i]], next[x]+1);
		}


		for(p=1;p<P;p++)
			cout << next[p] << endl;
		
		cout << endl;








	}
}
