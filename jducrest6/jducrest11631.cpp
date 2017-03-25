#include <iostream>
#include <vector>
#include <algorithm>

// kruskal algo, rien a dire de special


using namespace std;
unsigned int parent[200000];
unsigned int ranking[200000];

struct edge
{
	int x;
	int y;
	int w;
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

void kruskal(int N)
{
	int u,v;
	min_set.clear();
	for(int v = 0;v<N;v++)
	{
		parent[v] = v;
		ranking[v] = 0;
	}

	sort(edges.begin(),edges.end(),weight_sort);

	for(int e = 0;e<edges.size();e++)
	{
		u = edges[e].x;
		v = edges[e].y;
		if(find(u) != find(v))
		{
			min_set.push_back(edges[e]);
			unite(u,v);
		}
	}
}



int main()
{

	int sum,sum_min,M,N,x,y,w,i;
	M = 1;
	N = 1;
	struct edge e;
	while(1)
	{
		cin >> M >> N; //nb of junctions / nb or roads
		if ( M == 0 && N == 0)
			break;
		sum = 0;
		edges.clear();
		for(i=0;i<N;i++)
		{
			cin >> x >> y >> w;
			e.x = x;
			e.y = y;
			e.w = w;
			sum += w;
			edges.push_back(e);
		}
		
		kruskal(M);
		
		sum_min = 0;
		for(i=0;i<min_set.size();i++)
		{
			sum_min+=min_set[i].w;
		}
		
		cout << sum - sum_min << endl;

	}
}
