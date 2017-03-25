/*
le classique algo de prog dyn pour knapsack....
*/

#include <iostream>
#include <vector>

using namespace std;

int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}



void knapsack(int* weight,int* value,int* dyn,int nb_Objs)
{
	int i,j;
	for(j=0;j<=30;j++)
		dyn[j]=0;
	
	for(i=1;i<=nb_Objs;i++)
	{
		for(j=0;j<=30;j++)
		{
			if(weight[i-1] > j)
				dyn[31*i+j] = dyn[31*(i-1)+j];
			else
				dyn[31*i+j] = max(dyn[31*(i-1)+j],dyn[31*(i-1)+(j-weight[i-1])]+value[i-1]);
		}
	}
}


int main()
{
	int dyn[31*1001];
	int weight[1000];
	int value[1000];
	int i,j,test,nb_Tests,obj,nb_Objs,pers,nb_Pers,pers_strength,s;

	cin >> nb_Tests;

	for(test = 0; test < nb_Tests; test++)
	{
		// on recupere l'input des objets
		
		cin >> nb_Objs;
		for(obj = 0; obj < nb_Objs; obj++)
		{
			cin >> value[obj] >> weight[obj];
		}
		// on calcule l'optimal
		knapsack(weight,value,dyn,nb_Objs);


		// on renvoie le bon resultat pour chaque membre de la famille
		cin >> nb_Pers;
		s=0;
		for(pers = 0; pers < nb_Pers; pers++)
		{
			cin >> pers_strength;
			s+= dyn[31*nb_Objs+pers_strength];
		}
		cout << s<< "\n";



	}

	
}
