#include <iostream>
#include <vector>

int mat[50][50];
int S[50];
vector<int> liste;
void dfs(int x):
{
	S[x] = 1;
	for(int i = 0;i<50;i++)
		if (mat[x][i] != 0 && S[v]==0)
			dfs(x);
}

void eulerian_path(int x)
{
	int y = x;
	vector<int> l;
	do
	{
		for(int i=0;i<50;i++)
		{
			if (mat[y][i] > 0)
			{
				l.push_back(y);
				mat[y][i] --;
				mat[i][y] --;
				y = i;
			}
		}
	}while(y!=x)

	for(int i = 0;i<l.size();i++)
	{
		eulerian_path(l[i]);
		liste.push_back(l[i]);
	}
}


