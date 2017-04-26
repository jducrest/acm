#include <iostream>
#include <vector>
#include <iomanip>
#define D false
#define DEBUG(s,x) if(D) cout<<s<<" "<<x<<endl
using namespace std;


vector<long> kingdoms_x[30];
vector<long> kingdoms_y[30];
vector<long> convexes_x[30];
vector<long> convexes_y[30];
double areas[30];
bool paralyzed[30] = {false} ;


long scalar_product(long x, long y, long x_, long y_)
{
	return x*x_+y*y_;
}
long find_leftmost(long n)
{
	long l = 0;
	for(long i=0;i<kingdoms_x[n].size();i++)
		if (kingdoms_x[n][i] < kingdoms_x[n][l]) 
			l = i;
	
	return l;
}

void compute_area(long n)
{
	long a = 0;
	for(long i = 1;i<convexes_x[n].size();i++)
	{
		a+=convexes_x[n][i-1]*convexes_y[n][i] - convexes_x[n][i]*convexes_y[n][i-1];
	}
	areas[n] =  double(a)/2;
}


void compute_jarvis(long n)
{
	long i,k;

	long next_x,next_y,last_x,last_y;
	// clear convex
	convexes_x[n].clear();
	convexes_y[n].clear();
	
	//find leftmost and add it to convex (first polong)
	i = find_leftmost(n);
	convexes_x[n].push_back(kingdoms_x[n][i]);
	convexes_y[n].push_back(kingdoms_y[n][i]); 
	DEBUG("x of next convex point (leftmost) :",convexes_x[n][0]);
	DEBUG("y of next convex point (leftmost) :",convexes_y[n][0]);
	k=0;
	do{
		last_x = convexes_x[n][k];
		last_y = convexes_y[n][k];

		next_x = kingdoms_x[n][0];
		next_y = kingdoms_y[n][0];

		for(i=1;i<kingdoms_x[n].size();i++)
		{
			if ( (next_x == last_x && next_y == last_y) || (scalar_product ( next_y-last_y, -(next_x-last_x) , kingdoms_x[n][i]-last_x, kingdoms_y[n][i]-last_y) > 0))
				{ 
				next_x = kingdoms_x[n][i]; 
				next_y = kingdoms_y[n][i];
				}
		}
		convexes_x[n].push_back(next_x);
		convexes_y[n].push_back(next_y);
		DEBUG("x of next convex point : ",next_x);
		DEBUG("y of next convex point : ",next_y);
		k++;
	}while(!(convexes_x[n][0] == next_x && convexes_y[n][0] == next_y));

}

long parse()
{
	long i,x,y,n,k=0;
	while(1)
	{
		cin >> n ;

		if(n == -1)
			break;
		
		for(i=0;i<n;i++)
		{
			cin >> x >> y;
			kingdoms_x[k].push_back(x);
			kingdoms_y[k].push_back(y);
		}
		k++;
	}
	return k;
}

bool in(long x, long y, long k)
{
	long c = 0;
	vector<long> xs = convexes_x[k];
	vector<long> ys = convexes_y[k];
	for(long i = 1;i<xs.size();i++)
	{
		if (scalar_product( ys[i]-ys[i-1], -(xs[i]-xs[i-1]), x-xs[i-1], y-ys[i-1]) > 0)
			return false;
	}
	return true;
}

void explode_bomb(long x,long y,long k)
{
	for(long i=0;i<k;i++)
	{
		// check if bomb falls in kingdom i
		if ( in(x,y,i) )
		{
			paralyzed[i] = true;
			return;
		}
	}

}

int main()
{
	long n,x,y,i,j,k;
		
	cout << fixed << setprecision(2);


	// k = nb_of_kingdoms
	k=parse();

	// find convex hull
	for(i=0;i<k;i++)
	{
		DEBUG("jarvis of :",i);
		compute_jarvis(i);
		compute_area(i);
		DEBUG("area :",areas[i]);
	}


	while(cin >> x >> y)
	{
		explode_bomb(x,y,k);
	}

	for(i=0;i<k;i++)
		DEBUG("paralyzed :",paralyzed[i]);
	
	float p = 0;
	for(i=0;i<k;i++)
	{
		if (paralyzed[i])
		{
			cout << "para " << areas[i] << endl;
			p+= areas[i];
		}
		else
			cout << "not  " << areas[i] << endl;
	}
	// print area of disabled coutries:
	cout << p<< endl;

	return 0;
}
