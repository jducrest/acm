#include <vector>
#include <iostream>

/* pourquoi mon algo est mauvais:
ma stratégie etait de resoudre mathématiquement le problème par recurrence sur le nombre de pieces:
c'est a dire que le nombres de solutions avec seulement des pieces de 1, puis avec des pieces de {1,5} etc...

notes: / représente la division euclidienne, et f5 se lit "le nombre de combinaisons possibles avec des pieces inférieures ou egales a 5"

{1}:
f1(n) = 1

{1,5}:
f5(n) = sum_{i=0}^{n/5} (f1(n-5i)) = n/5 + 1

{1,5,10}:
f10(n) = sum_{i=0}^{n/10} (f5(n-5i)) = ... = (n/10 + 1)(n/5+1-n/10)            

...
et la ca devient vraiement long et fastidieux a resouldre je suis donc parti sur la methode brutasse pour la suite.

on peut dire que j'ai juste fait un "proof of concept" ;)


*/

using namespace std;

unsigned long f10(unsigned long x)
{
	return (x/10+1)*(x/5+1-x/10);
}

unsigned long f25(unsigned long x)
{
	unsigned long s = 0,i;
	for(i=0;i<=x/25;i++)
		s+=f10(x-25*i);
	return s;
}

unsigned long f50(unsigned long x)
{
	unsigned long s = 0,i;
	for(i=0;i<=x/50;i++)
		s+=f25(x-50*i);
	return s;
}



int main()
{
	unsigned long s;
	unsigned long k;
	while(cin >> k)
	{
		s = f50(k);
		if(s==1)
			cout << "There is only 1 way to produce "<< k <<" cents change.\n";
		else
			cout << "There are " << s <<" ways to produce "<<k<<" cents change.\n";
	}
	return 0;
}
