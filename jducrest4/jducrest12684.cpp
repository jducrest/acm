/*
Brute force sans aucune optimisation:
. on traite les sommets au hasard alors qu'il serait plus interessant d'en selectionner un adjacent a chaque etape
. j'utilise une matrice d'adjacence qui n'est pas du tout un moyen opti pour ce qu'on veut faire, des listes d'adjacences seraient mieux (failVoisin de complexite O(n) alors que ca pourait etre 0(deg(v))).
*/



#include <iostream>
#include <vector>

using namespace std;

bool failVoisins(bool m[101][101], int color[101],int n,int i)
{
	int j;
	for(j=1;j<=n;j++)
		if(m[i][j] && color[i]==color[j])
			return true;
	return false;
}


void bruteForce(bool m[101][101], int color[101], int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(i<=0)
		{
			cout << "error\n";
			break;
		}
		color[i]++;
		if(color[i]>4)	// tant pis on a tout essaye avec ce sommet, on est oblige de backtracker
		{
			color[i]=0;	
			i=i-2;
		}
		else if(failVoisins(m,color,n,i)) // on espere que la couleur de i ne gene aucun voisin, sinon bin on la change 
		{
			i=i-1; // ca a pour effet de rester sur le meme i la boucle suivante
		}
	}
}

int abs(int x)
{
	if(x>0)
		return x;
	else
		return -x;
}

int main()
{
	bool m[101][101];
	int color[101];
	int i,j,k;
	int n,n_=-1,e_,f_;
	int flag;
	int count=1;
	char s[100];
	while(cin >> n)
	{
	
	//init:
	for(i=0;i<=100;i++)
		color[i]=0;
		
	for(i=0;i<=100;i++)
		for(j=0;j<=100;j++)
			m[i][j]=false;
	
	/* petit trick degeulasse:
	quand on lit plusieurs datasets les uns apres les autres, je fais un cin de trop, je suis donc oblige de recuperer leur donnees et de les remettre au bon endroit...
	
	*/
	if(n_!=-1)
	{
		f_=n;
		n = n_;	
		m[e_][abs(f_)]=true;
		m[abs(f_)][e_]=true;
	}
	
	
	while(cin >> i >> j)
	{
		if(j>=0)  // cas on on a trop lu, cf au dessus pour remettre ces donnees au bon endroit
		{
			n_=i;
			e_=j;
			break;
		}
		
		m[i][abs(j)]=true;
		m[abs(j)][i]=true;
	}	
	
	
	/* calcul des bonnes couleurs */
	
	bruteForce(m,color,n);
	
	/* affichage de la solution */
	
	if(count!=1)
		cout << "\n";
		
	for(i=1;i<=n;i++)
		cout << i << " " << color[i] <<"\n";
	
	flag++;
	}
	
	return 0;
}
