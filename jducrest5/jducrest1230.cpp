#include <iostream>
#include <vector>

using namespace std;
// merci Mr Knuth
unsigned long fast_int(unsigned long x,unsigned long y,unsigned long n)
{
	if(!y)
		return 1;
	else if(y==1)
		return x;
	else if(y%2)
		return (x*(fast_int(x,y-1,n))) % n;
	else
		return (fast_int((x*x% n),y>>1,n)) % n;
}

int main()
{
	unsigned long x,y,n,z; 
	cin >> z;
	while(cin >> x >> y >> n)
	{	
		if(!x)
			break;
		z= fast_int(x,y,n);
		cout << z << endl;
	}
	return 0;
}
