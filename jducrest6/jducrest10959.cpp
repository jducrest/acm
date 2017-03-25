#include <iostream>
#include <vector>
#include <queue>

// breadth first algo

using namespace std;

int main()
{
	
	int n,N,p,P,D,x,y,i;
	int dist[1001];
	bool coloration[1001];
	vector<int> adj[1001];
	queue<int> unefile;
	cin >> N;
	for(n=0;n<N;n++)
	{
		// on vide dist et adj
		for(p=0;p<P;p++)
		{
			adj[p].clear();
			dist[p]=-1;
			coloration[p]=false;
		}
		cin >> P >> D;
		for(p = 0; p< D; p++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		p=0;
		dist[0] = 0;
		coloration[p]=true;
		while(1) // on boucle tant qu'on a pas fini
		{
			for(i=0;i<adj[p].size();i++)
				if(!coloration[adj[p][i]]) // ceux qu'on a pas encore vu on a leur dist min
				{
					unefile.push(adj[p][i]);
					dist[adj[p][i]] = dist[p]+1;
					coloration[adj[p][i]] = true;
				}
					
			if (unefile.size() == 0)
				break;

			p = unefile.front();
			unefile.pop();
		}

		for(p=1;p<P;p++)
			cout << dist[p] << endl;
		

		if(n!=N-1)
			cout << endl;
	}

}
