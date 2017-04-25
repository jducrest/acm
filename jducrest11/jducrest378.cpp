#include <iostream>
#include <vector>
#include <stdio.h>
#include <iomanip>
#define LINE 1
#define NONE 2
#define POINT 3

using namespace std ;
int main()
{
	
	double a,a_,b,b_;
	bool ort,ort_;
	double x1,x2,x3,x4,y1,y2,y3,y4;
	int i,n,out;
	
	
	cin >> n;
	cout <<"INTERSECTING LINES OUTPUT"<< endl;
	cout << fixed << showpoint ;
	cout << setprecision(2);
	for(i=0;i<n;i++)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 ;
		if ((x2-x1) != 0 )
		{
			ort = false;
			a = (y2-y1)/(x2-x1);	
			b = y1 - a * x1;
		}
		else{
			ort = true;
			b_ = x1;
		}

		if ((x4-x3) != 0)
		{
			ort_ = false;
			a_ = (y4-y3)/(x4-x3);
			b_ = y3 - a_ * x3;
		}
		else
		{
			ort_ = true;
			b_ = x3;
		}

		if (ort && ort_)
		{
			if (x1 == x3)
				out = LINE;
			else
				out = NONE;
		}
		else if (ort)
		{
			out = POINT;
			y1 = a_ * b + b_ ;
		}
		else if (ort_)
		{
			out = POINT;
			y1 = a * b_ + b ;
			x1 = x3;
		}
		else
		{
			if (a == a_)
			{
				if (b == b_)
				{
					out = LINE;
				}
				else
				{
					out = NONE;
				}
			}
			else
			{
				out = POINT;
				x1 = (b_-b)/(a-a_);
				y1 = a * x1 + b ;
			}
		}
		switch(out)
		{
			case LINE:
			cout <<"LINE" << endl;
			break;
			case NONE:
			cout << "NONE" << endl;
			break;
			case POINT:
			
			cout << "POINT "<< x1 << " "<< y1 << endl;
			break;
		}
	}
	cout << "END OF OUTPUT" << endl;
}
