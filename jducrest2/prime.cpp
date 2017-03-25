/*
pas grand chose a dire, un algo de backtrack classique.
le seul truc "intelligent" est quand on teste les nombres a ajouter derriere, on teste que ceux de la parité différente du dernier placé.
*/

#include <iostream>
#include <vector>

using namespace std;

int is_prime[40] = {true, true, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, false, false, false, false, true, false, true, false, false, false, false, false, true, false, false};

void print_(int* l,int n)
{
	int i;
	
	cout << l[0];
	for(i = 1;i<n;i++)
		cout << " " << l[i];
	cout << "\n";
}

void backtrack(int* l,int lsize,bool* t,int n)
{
	int i;
	bool flag = true;
	for(i=2+(lsize-1)%2;i<=n;i+=2)
	{
		if(!t[i])
		{
			flag = false;
			if (is_prime[l[lsize-1]+i])
			{
				t[i]=true;
				l[lsize]=i;
				backtrack(l,lsize+1,t,n);
				t[i]=false;
			}
		}
	}
	if(lsize == n && is_prime[l[n-1]+l[0]])
		print_(l,n);
}

int main()
{
	int tsize;
	bool t[20];
	int lsize;
	int l[20];
	int n;
	int i,k;
	
	k=1;
	while(cin >> n)
	{
		// init:
		for(i=0;i<20;i++)
		{
			t[i]=false;
			l[i] = 0;

		} 	
		l[0]=1;
		lsize = 1;
		tsize = n;
				
		// backtracking
		if(k!=1)
			cout << "\n";
		cout << "Case " << k <<":\n";
		backtrack(l,lsize,t,n);
		
		k++;
	}
	
	
}

