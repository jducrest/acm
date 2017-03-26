#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// j'ai essayé d'implementer un dijkstra avec file de priorité comme j'y passait trop de temps, 
// depité j'ai fait bellman-ford horrible en O(n^3).
// une catastrophe algorithmique...


int weight[100][100];
long dist[100];


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
