#include <iostream>
#include <vector>
#include <algorithm>

// Floyd Warshall rien a dire...

using namespace std;

vector<int> adj[101];
int dist[100][100];

vector<int>::iterator it;


int main()
{
	int i,j,k,x,y,n,test = 1;
	while(true)
	{
		// cleaning
		for(i=0;i<100;i++)
		{
			for(j=0;j<100;j++)
				dist[i][j] = -1;
			dist[i][i] = 0;
		}


		// input
		cin >> x >> y;
		if(x==0 && y == 0)
			return 0;

		dist[x-1][y-1] = 1;	
		while(x!=0 || y != 0)
		{
			cin >> x >> y;
			dist[x-1][y-1] = 1;
		}
		// Floyd Warshal
		for(k=0;k<100;k++)
			for(i=0;i<100;i++)
				for(j=0;j<100;j++)
				{
					if(dist[i][k] != -1 && dist[k][j] != -1)
					{
						if(dist[i][j] == - 1)
							dist[i][j] = dist[i][k]+dist[k][j];
						else if(dist[i][j] > dist[i][k]+dist[k][j])
							dist[i][j] = dist[i][k]+dist[k][j];
					}
				}
		
		// calcul du resultat:
		int sum = 0;
		n = 0;
		for(i=0;i<100;i++)
			for(j=0;j<100;j++)
			{	
				if(dist[i][j]!=-1)
				{
					sum+= dist[i][j];
					if(i!=j) n++;
				}
			}
		cout.setf( ios::fixed, ios::floatfield );
		cout.precision(3);
		cout<<"Case "<<test<<": average length between pages = "<<float(sum)/float(n)<<" clicks"<<endl;
		test ++;
	}
}
