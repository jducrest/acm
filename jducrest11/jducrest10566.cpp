#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

float min(float x, float y)
{
	if (x < y)
		return x;
	else
		return y;
}

int main()
{
	int i;
	float x,y,c,c_,hx,hy,z,dz;

	cout << std::fixed << std::showpoint;
    cout << std::setprecision(3);

	while(cin >> x >> y >> c)
	{
		z = min(x,y);
		dz = z/2;
		for(i=0;i<100;i++)
		{
			hx = sqrt(x*x-z*z);
			hy = sqrt(y*y-z*z);
			if(hx+hy!= 0)
				c_ = hy*hx/(hx+hy);
			else 
				c_ = 0;
			//cout  << c << " " << c_ << endl;
			if(c>c_)
				z-= dz;
			else if (c< c_)
				z+= dz;
			else
				break;
			dz /= 2;
		}
		cout << z << endl;
	}
}
