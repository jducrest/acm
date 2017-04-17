#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int N,n,i,j,k,last,d,nb_planches,length;
	int aller,retour,s;
	char c;
	bool unepourlaller;
	cin >> N;
	for(n =1;n<=N;n++)
	{
		cin >> nb_planches >> length;
		s = 0;
		aller = 0; 
		retour = 0;
		for(i=0;i<nb_planches;i++)
		{
			// on recup l'input
			cin >> c;
			cin >> d;
			d = -d;

			// calcul
			if(c=='B')
			{
				s = max(s,d-aller);
				s = max(s,d-retour);
				aller = d;
				retour = d;
			}
			else // cas ou on ne peut passer qu'une fois l'idee est que la sol optimale est d'alterner une planche aller une retour
			{
				if(unepourlaller)
				{
					unepourlaller = false;
					s = max(s,d-aller);
					aller = d;
				}
				else
				{
					unepourlaller = true;
					s = max(s,d-retour);
					retour = d;
				}

			}

			
		}
		s = max(s,length-aller);
		s = max(s,length-retour);
		cout << "Case " << n<< ": " << s << endl;
	}
}
