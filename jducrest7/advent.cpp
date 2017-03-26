#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int power[101];
long dist[101];
struct edge
{
	int start;
	int end;
};
vector<edge>::iterator it;
vector<edge> edges;

void relax(int s, int e)
{
	if(dist[s]<=0) // point is not reachable -> nothing to do
		return;
		
	if(dist[e]<=0) // point e is not reachable -> everything is better than the current
	{
		dist[e] = dist[s] + power[e];
		return;
	}
	
	int d = dist[s] + power[e]; 
	
	if (d <= 0)
		return; // point e is not reachable from s
	
	if(dist[e] < d)
		dist[e] = d; // we found a new minimum

}




int main()
{
	int i,j,k,nb_test,test,N,E,T,M,x,y,w,n;
	
	edge e;

	while(true)
	{
		cin >> N;
		if(N==-1)    // in case the test is finished
			break;
		
		edges.clear();
		for(i=1;i<=100;i++)
			dist[i] = 0; // infinity
		
		for(n=1;n<=N;n++)
		{
			cin >> w >> x;

			power[n] = w;
			
			for(i=0;i<x;i++)
			{
				cin >> y; // on recupere une door
				e.start = n;
				e.end = y;
				edges.push_back(e);
			}
			
		}
		/*
		for(n=1;n<=N;n++)
			cout << power[n] << " ";
		cout << endl << endl;

		for(i = 0;i<edges.size();i++)
			cout << "s " << edges[i].start << " e " << edges[i].end << endl;
		*/

		//B-F
		dist[1] = 100;
		for(k=0;k<100000;k++)
			for(it = edges.begin();it != edges.end();it++)
				relax(it->start,it->end);
		
		if(dist[N]>0)
			cout << "winnable" << endl;
		else
			cout << "hopeless" << endl;
		/*
		for(i=1;i<=N;i++)
			cout << dist[i] << " ";
		cout << endl;
		*/
	}

}
