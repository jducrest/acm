#include <iostream>
#include <vector>
#include <algorithm>

// test de 2-coloration avec le glouton utilisant un dfs.


using namespace std;

int color[301];
vector<int> adj[301];
bool flag = true;

void dfs(int x)
{
	for(int i=0;i<adj[x].size();i++)
	{
		if (color[adj[x][i]] == color[x])
		{
			flag = false;
			return;
		}
		else if (color[adj[x][i]] == -1)
		{
			color[adj[x][i]] = 1 - color[x];
			dfs(adj[x][i]);
		}
	}
}

int main()
{
	int N,M,n,m,x,y;
	while(cin >> N)
	{
		// cas de sortie
		if(N==0)
			break;
		for(n=1;n<=300;n++)
			adj[n].clear();
		// recuperation de la saisie
		while(1)
		{
			cin >> x >> y;
			if(x == 0 && y == 0)
				break;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		//init
		flag = true;
		for(n=1;n<=N;n++)
			color[n] = -1;
		

		// boucle principale
		for(n=1;n<=N;n++)
		{
			if(color[n] == -1) // on l'a pas encore colore
			{	
				color[n] = 1;
				dfs(n);
			}
		}	
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
}
