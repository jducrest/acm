#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100];
int weight[100][100];
vector<int> S;
long dist[100];

vector<int>::iterator it;


int main()
{
	int i,j,k,nb_test,test,N,E,T,M,x,y,w;
	cin >> nb_test;
	for(test = 0;test<nb_test;test++)
	{
		if(test!=0)
			cout << endl;
		for(i=0;i<100;i++)
		{
			adj[i].clear();
			dist[i] = 2147483647;
			for(j=0;j<100;j++)
				weight[i][j]=0;
		}
		
		
		cin>> N >> E >> T >> M;
		E--;

		for(i=0;i<M;i++)
		{
			cin >> x >> y >> w;
			weight[y-1][x-1] = w;
			adj[x-1].push_back(y-1);
		}

		//B-F
		dist[E] = 0;
		for(k=0;k<N;k++)
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
					if (weight[i][j]!= 0) // edge exists
						if(dist[i]+weight[i][j]<dist[j])
							dist[j] = dist[i]+weight[i][j];
	
		int sum = 0;
		for(k=0;k<N;k++)
		{
			if(dist[k] <= T)
				sum++;
		}
		cout <<  sum << endl;
		
	}
}
