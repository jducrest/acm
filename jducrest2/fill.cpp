/* c'est un algo bizarre, la généralisation a n segments de la separation en 2 segments de somme minimal ou on fait avancer un "curseur" entre les deux segments jusqu"a ce que la somme soit trop grande.
il y a juste un cas bizarre ou on arrive pas a baisser la somme entre le segment n et n+1, mais on a toujours pas atteint l'optimal.
Ce que je fait est je calcule la somme max, et j'essaye de faire un changement plus bas qui respecte le fait que les nouvelles sommes sont toujours inférieur a l'ancienne.
...
ca marche, une preuve utiliserait un invariant du type: a chaque itération, la somme max descend, on devrait donc arriver a un truc bien au bout d'un moment... mais j'avoue que je l'ai pas fait au propre.

*/


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

long min(long x,long y)
{
	if(x<y)
		return x;
	else 
		return y;
}

void printv(vector<long> v)
{
	long i;
	for(i = 0;i<v.size();i++)
		cout << v[i] << " ";
	cout << "\n";
	return;
}

long maxv(vector <long> v)
{
	long max = 0;
	long i;
	for(i = 0;i<v.size();i++)
		if(max<v[i])
			max = v[i];
	return max;
}

long sumv(vector<long> v,long i,long j)
{
	long sum = 0;
	int k;
	for(k=i;k<min(j,v.size());k++)
		sum+=v[k];
	return sum;
}
	

int main(void)
{
	//ofstream f;
	//f.open("res.txt");
	vector<long> vessels,opt,sums; 
	long nbVessels, nbContainers,i,temp,t,u,t_,u_,imax,summax;
	bool flag;
	while(cin >> nbVessels >> nbContainers)
	{
		/*  on recupere les valeurs */
		vessels.clear();
		opt.clear();
		sums.clear();
		
		for(i=0;i<nbVessels;i++)
		{
			cin >> temp;
			vessels.push_back(temp);
		}
	
		/* cas trivial, on renvoie juste le max puisqu'on peut mettre chaque vessel dans un container */	
		if (vessels.size() <= nbContainers) 
		{
			cout << maxv(vessels) << "\n";
			continue;
		}
		
		
		/* cas non trivial, on initialise les structures de données annexe */
		for(i=0;i<nbContainers;i++)
			opt.push_back(i);
		
		opt.push_back(nbVessels);
		
		for(i=0;i<nbContainers;i++)
			sums.push_back(sumv(vessels,opt[i],opt[i+1]));
		/* debug ****************	
		cout << "before while:\n";
		prlongv(sums);
		prlongv(opt);
		****************/	
		/* boucle principale */	
		
		
		
		flag = true	;
		while(flag)
		{
			flag = false;
			
			for(i=nbContainers-2;i>=0;i--)
			{
				t = sums[i];
				u = sums[i+1];
				t_ = sums[i]+vessels[opt[i+1]];
				u_ = sums[i+1]-vessels[opt[i+1]];
				while(t_<u)
				{
					opt[i+1]++;
					sums[i] = t_;
					sums[i+1] = u_;
					flag = true;
					t = sums[i];
					u = sums[i+1];
					t_ = sums[i]+vessels[opt[i+1]];
					u_ = sums[i+1]-vessels[opt[i+1]];
				}
			}
			
			if(!flag)               // le cas ou on ne peut plus avancer 
			{
				imax = -1;
				summax = 0;
				for(i=0;i<nbContainers;i++)    // on trouve la somme max
				{
					if(sums[i] > summax)
					{
						summax = sums[i];
						imax = i;
					}
				}
				
				for(i=imax-1;i>=0;i--)    // on etait bloqué, opération de débloquage
				{
					if(sums[i]+vessels[opt[i+1]] < summax)
					{
						u_ = sums[i+1]-vessels[opt[i+1]];
						t_ = sums[i] + vessels[opt[i+1]];
						sums[i] = t_;
						sums[i+1] = u_;
						opt[i+1]++;
						flag = true;
						break;
					}
				}
			}
		}
		
		
		/* debug ******************
		prlongv(sums);
		prlongv(opt);
		prlongv(vessels);
		*************************/
		cout << maxv(sums) << "\n";	
	}
	return 0;
}
