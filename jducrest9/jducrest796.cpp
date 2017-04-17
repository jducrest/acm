#include <iostream>
#include <vector>

#define SIZE 10000
#define BLUE 1

/*
On fait juste un dfs en gardant la precedance, quand on retombe sur un sommet deja colore on trouve une boucle:
 on refait la boucle et on dit que ces aretes ne sont pas critiques
*/




using namespace std;


vector<int> adj[SIZE] ;
int pred[SIZE] ;
bool color[SIZE] ;
bool in_cycle[SIZE][SIZE];
bool used_edge[SIZE][SIZE];
bool first_round = true;
void find_cycle(int x, int y)
{
	//cout << "start cycle" << endl;
	int p;
	//cout << "in cycle "<< x << " "<< y << endl;

	in_cycle[x][y] = true;
	in_cycle[y][x] = true;
	while(x!=y)
	{
		p = pred[x];
		if (p == -1)
			break;
		in_cycle[x][p] = true;
		in_cycle[p][x] = true;
		//cout << "in cycle "<< x << " "<< p << endl;
		x = p;
	}
	//cout << "end cycle" << endl;
}


void blue_bug(int x)
{
	//cout << "start bb " << x << endl;
	color[x] = BLUE;
	for(int i = 0;i<adj[x].size();i++)
	{
		int y = adj[x][i];
		if(!used_edge[x][y])
		{
		used_edge[x][y] = true;
		used_edge[y][x]=true;
		if (color[y] == BLUE)
		{
				find_cycle(x,y);
		}
		else
		{	
			pred[y] = x;
			blue_bug(y);
		}
		}
	}
	//cout << "end bb" << endl;
}


int main()
{
	int S,i,j,k,s,d,p;
	char c1,c2;
	while(cin >> S)
	{
		// clear
		for(i=0;i<SIZE;i++)
		{
			adj[i].clear();
			pred[i] = -1;
			color[i] = WHITE;
			for(j=0;j<SIZE;j++)
			{
				used_edge[i][j] = false;
				in_cycle[i][j] = false;
			}
		}
		
		// parsing
		

		for(i= 0;i<S;i++)
		{
			//cout << "la ca va "<<i<< endl;
			cin >> s >> c1 >> d >> c2;
			//cout << c1<< " "<< c2 << " " << d;
			for(j= 0;j<d;j++)
			{
				cin >> p ;
				adj[s].push_back(p);
				//cout << "i,j "<< i << " "<< j << endl;
			}
		}
		// calcul:
		//cout << "jusquicitoutvabien";
		///*
		for(i=0;i<SIZE;i++)
		{
			if(color[i]!=BLUE)
				blue_bug(i);
		}

		// affichage:
		k = 0;
		for(i=0;i<SIZE;i++)
			for(j=i+1;j<SIZE;j++)
				if(!in_cycle[i][j]&&used_edge[i][j])
					k++;	
		/*
		if(!first_round)
			cout << endl;
		first_round = false;
		*/
		cout << k << " critical links" << endl;

		for(i=0;i<SIZE;i++)
		{
			for(j = i+1;j<SIZE;j++)
			{
				if(!in_cycle[i][j]&&used_edge[i][j])
				{
					cout << i << " - "<<j<< endl;
				}
			}
		}

		cout << endl;
		
		//*/
	}

}
