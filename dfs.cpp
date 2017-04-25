#include <iostream>
#include <vector>

vector<int> adj[10000];
int color[10000];
int pred[10000];

void dfs(int x)
{
	int i;
	for(i = 0 ; i<adj[x].size(); i++)
	{
		dfs(adj[x].size());

	}
}


int main()
{
	char shit_char;
	int i,j,k,n,N,m,M,x,y,z;
	int server,nb_links;



	while(cin >> N)
	{
		//init
		for(i=0;i<10000;i++)
		{
			adj[i].clear();
			color[i] = 0;
			pred[i] = -1;
		}

		// get input
		for(n = 0;n<N;n++)
		{
			cin >> server >> shit_char >> nb_links >> shit_char;
			for(i=0;i<nb_links;i++)
			{
				cin >> x;
				adj[server].push_back(x);
			}
		}


		// algo
		dfs(0);




	}




	return 0;
}
