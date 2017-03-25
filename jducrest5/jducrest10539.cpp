#include <iostream>
#include <vector>

using namespace std;

int main()
{
	bool flag;
	unsigned long long i,j,k,l,p,N,max,min,nb,acc;
	
	bool isprime[1000000];
	for(i=0;i<1000000;i++)
		isprime[i]=true;
	vector<unsigned long long> primes;
	//crible d'erathostene
	for(i=2;i<=1000000;i++)
	{
		if(isprime[i])
		{
			primes.push_back(i);
			p=2*i;
			while(p<1000000)
			{
				isprime[p] = false;
				p+=i;
			}
		}
	}
	// et la on test exaustivement tout les primes et toutes leurs puissances
	cin >> N;
	for(i=0;i<N;i++)
	{
		cin >> min >> max;
		l = primes.size();
		nb = 0;
		for(j=0;j<l;j++)
		{
			p = primes[j];
			acc = p*p;
			// on attent la première puissance sup a min
			while(acc < min)
				acc*=p;
			// a partir de la on les compte
			while(acc < max)
			{
				nb++;
				acc*=p;
			}
		}
		cout << nb << endl;
	}
	return 0;
}
