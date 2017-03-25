#include <iostream>
#include <vector>
#include <algorithm>

// tri topologique


using namespace std;

vector<int> sommets;
int color[101];
vector<int> adj[101];

void dfs(int x)
{
	color[x] = 1;
	for(int i=0;i<adj[x].size();i++)
		if (color[adj[x][i]] == 0)
			dfs(adj[x][i]);
	color[x] = 2;
	sommets.push_back(x);
}

int main()
{
	int N,M,n,m,x,y;
	while(cin >> N >> M)
	{
		// cas de sortie
		if(N==0 && M==0)
			break;
		
		// recuperation de la saisie
		for(m = 0;m < M; m++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
		}

		// tri topo:
		//init
		sommets.clear();
		for(n=1;n<=N;n++)
			color[n] = 0;

		// boucle principale
		for(n=1;n<=N;n++)
		{
			if(color[n] == 0)
				dfs(n);
		}	

		for(n=sommets.size() -1 ;n > 0;n--)
			cout << sommets[n] << " ";
		cout << sommets[0] << endl;

	}
}
