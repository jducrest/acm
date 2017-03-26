#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


// kruskal algo
// quand on fait un arbre couvrant sur N sommets, il faut N-1 aretes, ce que l'on fait ici c'est l'algo de kruskal et dès 
// qu'on a (N-1)-S parties connexes couvertes, on complete avec les S connexion satellite, comme kruskal est glouton, on a
// juste a renvoyer le poids de la dernière arete ajoutée

using namespace std;
unsigned int parent[200000];
unsigned int ranking[200000];

struct edge
{
	int x;
	int y;
	float w;
};


vector<edge> edges;
vector<edge> min_set;


bool weight_sort(edge a,edge b)
{
	if(a.w >= b.w)
		return false;
	else
		return true;
}

int find(int u)
{
	if (parent[u] != u)
		parent[u] = find(parent[u]);	
	return parent[u];
}

void unite(int x, int y)
{
	int xroot = find(x);
	int yroot = find(y);

	if (xroot == yroot)
		return;
	if (ranking[xroot] < ranking[yroot])
		parent[xroot] = yroot;
	else if (ranking[xroot] > ranking[yroot])
		parent[yroot] = xroot;
	else
	{
		parent[yroot] = xroot;
		ranking[xroot] ++;
	}
}

void kruskal(int N,int opt_conn)
{
	int u,v;
	min_set.clear();
	for(int v = 0;v<N;v++)
	{
		parent[v] = v;
		ranking[v] = 0;
	}

	sort(edges.begin(),edges.end(),weight_sort);

	int nb_conn = N;

	for(int e = 0;e<edges.size();e++)
	{
		u = edges[e].x;
		v = edges[e].y;
		if(find(u) != find(v))
		{
			min_set.push_back(edges[e]);
			unite(u,v);
			nb_conn --; // on a relie 2 parties connexes
		}

		if(nb_conn == opt_conn)
		{
			cout.setf( ios::fixed, ios::floatfield );
			cout.precision(2);
			cout << edges[e].w << endl;
			return;
		}
	}
}

int xs[501];
int ys[501];

int main()
{

	int sum,sum_min,M,N,x,y,w,i,j,n,m,P,S;
	M = 1;
	N = 1;
	struct edge e;

	cin >> N;
	for(n=0;n<N;n++)	// pour chaque test case:
	{
		// recup saisie
		cin >> S >> P;
		for(i=0;i<P;i++)
		{
			cin >> x >> y;
			xs[i] = x;
			ys[i] = y;
		}
		// traitement de l'input
		edges.clear();
		for(i=0;i<P;i++)
			for(j=i+1;j<P;j++)
			{
				e.x = i;
				e.y = j;
				e.w = sqrt(pow(float(xs[i]-xs[j]),2)+pow(float(ys[i]-ys[j]),2));
				edges.push_back(e);
			}

		kruskal(P,S);



	}

}
