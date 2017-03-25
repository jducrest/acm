#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// une utilisation tout a fait astucieuse de __gcd de algorithm ...

int main()
{
	long  t, c, s, r, i, j, k, d, p, max;	
	cin >> t;
	
	for(i=0;i<t;i++)
	{
		cin >> c;
		max = 0;
		for(j=0;j<c;j++)
		{
			s = 0;
			for(k=0;k<9;k++)
			{
				cin >> r;
				s+= r;
			}	
			cin >> r;
			if (r > max)
				max = r;

			if(j==0)
				p = s-r;
			else
				p = __gcd(p,s-r);
		}
		if( p <= max || p <= 1 )
			cout <<"impossible" << endl;
		else
			cout << p << endl;
	}
	return 0;
}
