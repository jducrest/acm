#include <iostream>
#include <vector>

// un algo de fast fibonnaci

using namespace std;

void fib (unsigned long *r0, unsigned long *r1, unsigned long n)
{
	unsigned long r0_,r1_;
	if(n==1)
		return;
	
	if(n%2)
	{
		fib(r0,r1,n-1);
		r0_ = *r0;
		r1_ = *r1;
		*r0 = r1_;
		*r1 = r1_ + r0_;
	}
	else
	{
		fib(r0,r1,n>>1);
		r0_ = *r0;
		r1_ = *r1;
		*r0 = r0_ * (2 * r1_ - r0_);
		*r1 = r1_* r1_ + r0_*r0_;
	}
}

int main()
{
	unsigned long n,m;
	unsigned long r0, r1;
	
	while(cin >> n >> m)
	{
		m = (1<<m)-1; // m devient notre mask
		r0 = 1;
		r1 = 1;
		if(n==0)
			cout << 0 << endl;
		else if(n==1)
			cout << 1 << endl;
		else
		{
			fib(&r0,&r1,n);
			cout << (r0 & m) << endl;

		}
	}

}
