/*
on teste toutes les masks possibles (sauf ceux de taille inférieure au log du nombre de symbs puisque on peut stocker au mieux 2^n info sur n bits.

lors du test, on utilise une map (temps d'accès log(n) si je ne m'abuse c'est un arbre binaire de recherche a peu pres equilibré) pour verifier que tout les elements sont différents.

une amélioration a ajouter serait de tester les masks dans l'ordre croissant de nombre de bits et de s'arreter des qu'on a une solution.
une autre serait de tester avant si une ligne n'a que des zeros ou des uns (elle n'apporte aucune information).
une derniere serait de trier les lignes par 'quantité d'information', cad si il y a a peu pres autant de 1 que de 0 et de commencer par les parties ayant une forte chance de garder toute l'information.

Comme ces améliorations ont un impact difficile a mesurer (dans le pire cas la complexité est la meme) je ne les ai pas implémentées.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int logarithm(long x)
{
	int i = 0;
	int s = 1;
	while(s<x)
	{
		s=s<<1;
		i++;
	}
	return i;
}

void printv(vector<long> v)
{
	long i,k;
	k = v.size();
	for(i = 0;i<k;i++)
		cout << v[i] << " ";
	cout << "\n";
	return;
}

int computeMaskRange(long m)
{
	int c = 0;
	while(m!=0)
	{
		if (m%2)
			c++;
		m = m>>1;
	}
	return c;
}

void computeMasks(vector<long>* v, int n)
{	
	if(n==0)
	{	
		(*v).clear();
		(*v).push_back(0);
	}
	else
	{
		computeMasks(v,n-1);
		int k = (*v).size();
		for(int i=0;i<k;i++)
		{
			(*v)[i] = (*v)[i] << 1;
			(*v).push_back((*v)[i]+1);
		}
	}
}

int main()
{
	
	int nbExpl,nbLeds,nbSymbs,i,j;
	long val,temp;
	int log,msize,minimaskrange,maskrange;
	bool isnicemask;
	vector<long> symbs,masks;
	map<long,bool> hmap;

	cin >> nbExpl;
	for(nbExpl = nbExpl;nbExpl>0;nbExpl--)
	{
		
		// recuperation des informations
		symbs.clear();
		cin >> nbLeds;
		cin >> nbSymbs;
		for(i= 0;i<nbSymbs;i++)
		{
			val = 0;
			for(j=0;j<nbLeds;j++)
			{
				cin >> temp;
				val = (val << 1) + temp;
			}
			symbs.push_back(val);
		}
		// init
		minimaskrange = 200;
		// construction des masques:
		computeMasks(&masks,nbLeds);
		msize = masks.size();
		
		log = logarithm(nbSymbs);
		
		for(i=0;i<msize;i++)
		{
			hmap.clear();
			isnicemask = true;
			maskrange = computeMaskRange(masks[i]);
			if(maskrange>=log)    // on ne peut stocker que 2^n infos dans n bits, pas la peine d'essayer si n<log(nbSymbs)
			{
				for(j=0;j<nbSymbs;j++)
				{
					if(hmap.end()==hmap.find(symbs[j]&masks[i]))
					{
						hmap[symbs[j]&masks[i]]=true;
					}
					else
					{
						isnicemask = false;
						break;
					}
				}
				if(isnicemask)
				{
					if(maskrange < minimaskrange)
						minimaskrange = maskrange;
				}
			}
		} 
		
		cout << minimaskrange << "\n";
	}
}
