/*
Solution par algo dyn, je ne clamme pas l'avoir trouvé, j'ai trouvée l'idée de faire de la prog dyn sur ce site:
https://turing13.wordpress.com/2016/03/11/uva-10616-divisible-group-sums/

car je ne voyais pas de moyen "intelligent" de le faire (j'allais partir sur la methode d'enumeration brutale alors j'ai vite fait googlé ca pour voir si il n'y avait pas un algo plus intelligent).

Neanmoins tout le code est de moi.

L'idée est que,
soit N nombres,
nb_subsets a n elts qui congruent a (x mod m) = 
	nb_subsets a n elts qui congruent a (x mod m) des N-1 premiers elts  
+ nb_subsets a n-1 elts qui congruent a (x-val(Nieme) mod m) puisque cest derniers auquel on ajoute le Nieme elt forment des subsets corrects.

a chaque fois qu'on rajoute un nombre x, il ne faut pas oublier de rajouter 1 aux subsets a 1 elt qui congruent a (x mod m)

*/



#include <iostream>
#include <vector>

using namespace std;

int modulo(int x,int div)
{
	return (x%div+div)%div;
}

int main()
{
	int count=0;
	int querie;
	int nb_Ints,nb_Queries;
	int i,j,k;
	int m[2][10][20];
	int nbrs[200];
	int queries_subsets[10];
	int queries_mods[10];
	int pred=1,cur=0;
	int subset,mod,cmod;
	
	while(cin >> nb_Ints >> nb_Queries)
	{
		count++;
		
		if(nb_Ints == 0 && nb_Queries == 0)
			break;
			
		// recuperation de la saisie
		for(i=0;i<nb_Ints;i++)
		{
			cin >> nbrs[i];
		}
		for(i=0;i<nb_Queries;i++)
		{
			cin >> queries_mods[i] >> queries_subsets[i];
		}

		// boucle principale
		cout << "SET "<<count<<":\n";
		for(querie = 0;querie < nb_Queries; querie++)
		{
			// on reinitiallise notre matrice
			for(i=0;i<10;i++)
			{
				for(j=0;j<20;j++)
				{
					m[pred][i][j] = 0;
					m[cur][i][j] = 0;
				}
			}
			mod = queries_mods[querie];
			subset = queries_subsets[querie]; 
			

			// on traite le premier element a part:
			m[pred][0][modulo(nbrs[0],mod)]=1;

			for(i=1;i<nb_Ints;i++)
			{
				cmod = modulo(nbrs[i],mod);
				
				for(k=0;k<mod;k++)
					m[cur][0][k]=m[pred][0][k];

				m[cur][0][cmod]++;


				for(j=1;j<subset;j++)
				{
					for(k=0;k<mod;k++)
					{
						m[cur][j][k]=m[pred][j][k]+m[pred][j-1][(k-cmod+mod)%mod];
					}
				}


				pred = 1-pred;
				cur = 1-cur;
			}
		cout << "QUERY "<<querie+1<<": "<<m[pred][subset-1][0] << "\n";
		}

	}
	return 0;
}

