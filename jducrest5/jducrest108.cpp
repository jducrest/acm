#include <iostream>

using namespace std;

int main()
{
	int N,i,i_,j,j_,max,sum;
	long tab[101][101];
	long sums[101][101];
	cin >> N;
	for(i=0;i<=100;i++)
	{
		tab[i][0] = 0;
		tab[0][i] = 0;
	}
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			cin >> tab[i][j];
	
	for(j=1;j<=N;j++)
		for(i=2;i<=N;i++)
			tab[i][j] = tab[i-1][j] + tab[i][j];
	
	// on a transforme notre tableau en tableau de sommes partielles
	max = tab[1][1];
	for(i=1;i<=N;i++)
		for(i_=0;i_<i;i_++)
		{
			// on vient de choisir une certaine range et on fait l'algo lin dedans
			sum = 0;
			for(j=1;j<=N;j++)
			{
				sum+=(tab[i][j]-tab[i_][j]);
				if (sum > max)
					max = sum;
				if(sum < 0)
					sum = 0;
			}
		}
	cout << max << endl;

}
