#include <iostream>
#include <vector>
using namespace std;

// classique recherche de plus long segment

vector<int> tab;

int main()
{
	int n,i,j,k,N,s,imax,jmax,smax;
	cin >> N;
	do
	{
		tab.clear();
		tab.reserve(10000);
		for(n=0;n<N;n++)
		{
			cin >> k;
			tab.push_back(k);
		}

		i = 0;
		imax = 0;
		jmax = 0;
		s = 0;
		smax = 0;
		for(j=0;j<N;j++)
		{
			s+=tab[j];
			if (s < 0)
			{
				s = 0;
				i = j+1;
			}
			if (s > smax)
			{
				smax = s;
				imax = i;
				jmax = j;
			}
		}

		//	cout << imax << " " << jmax << " " << smax << endl;
		if (smax != 0)
			cout << "Winning with "<< smax <<"."<< endl;
		else
			cout << "Loose." << endl;
		
		
		cin >> N;
	}while(N!=0);
}
