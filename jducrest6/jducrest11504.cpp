#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> post;
int color[100001];
vector<int> adj[100001];


void dfs(int x)
{
	color[x] = 1;    // on le note comme visite
	for(int i=0;i<adj[x].size();i++)
	{
		if(color[adj[x][i]] == 0)    // le sommet n'a pas encore ete visite
			dfs(adj[x][i]);
	}
	post.push_back(x);     // on l'ajoute a la liste post qui est du coups directement ordonnee
}

int main()
{
	int N,M,n,m,x,y,t,T,nb_composantes;
	cin >> T;
	for(t=0;t<T;t++)
	{
		// init
		cin >> N >> M;
		post.clear();
		for(n=1;n<=N;n++)
		{
			adj[n].clear();
			color[n] = 0;
		}

		// recuperation de la saisie
		for(m=0;m<M;m++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
		}

		// boucle principale
		for(n=1;n<=N;n++)
		{
			if(color[n]==0) // on l'a pas encore colore
			{	
				dfs(n);
			}
		}	
		for(n=1;n<=N;n++) // on reinitialise la couleur
			color[n]= 0;

		nb_composantes = 0;
		for(n=N-1;n>=0;n--)
		{
			
			if(color[post[n]]==0)
			{
				dfs(post[n]);
				nb_composantes ++;
			}
		}
		cout << nb_composantes << endl;
	}
}
