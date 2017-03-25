/*
Algo classique de LCS.
Ma solution n'est pas tres "maligne" puisque j'alloue 
un tableau de taille 1001*1001 alors qu'on pourrait le faire intelligemment
avec seulement 2 tableaux de taille 1001 en switchant a chaque fois de l'un 
vers l'autre puisqu'on a besoin dans l'algo que de la ligne précédente(on peut meme le faire avec un seul tableau mais le code commence a etre vraiement illisible).
*/



#include <iostream>
#include <vector>

using namespace std;

int max (int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}


int main()
{
	int a[1001*1001];
	char s1[1001];
	char s2[1001];
	int i,j,l1,l2;
	while(cin.getline(s1,1001))
	{
		cin.getline(s2,1001);
		l1 = 1001;
		l2 = 1001;
		for(i=0;i<=1001;i++)
		{
			a[i]=0;
			if(s1[i]=='\0')
			{
				l1 = i;
				break;
			}
		}
		for(j=0;j<=1001;j++)
		{
			a[1001*j]=0;
			if(s2[j]=='\0')
			{
				l2 = j;
				break;
			}
		}
		for(i=1;i<=l1;i++)
		{
			for(j=1;j<=l2;j++)
			{
				if(s1[i-1]==s2[j-1])
					a[i+1001*j] = a[i-1+1001*(j-1)] + 1;
				else
					a[i+1001*j] = max( a[i-1+1001*j], a[i+1001*(j-1)]); 
			}
		}
		cout << a[l1+1001*(l2)] << "\n";
		
	}
	
	
	return 0;
}
