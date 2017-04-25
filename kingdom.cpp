#include <iostream>
#include <vector>

using namespace std;

vector<int> kingdoms_x[30];
vector<int> kingdoms_y[30];
vector<int> convexes_x[30];
vector<int> convexes_y[30];

int scalar_product(int x, int y, int x_, int y_)
{
	return x*x_+y*y_;
}
int find_leftmost(vector<int> kingdom_x)
{
	int l = 0;
	for(int i=0;i<kingdom_x.size();i++)
		if (kingdom_x[i] < kingdom_x[l]) 
			l = i;
	
	return l;
}


void jarvis(vector<int> kingdom_x, vector<int> kingdom_y, vector<int> convex_x, vector<int> convex_y)
{
	int i,k;
	int next_x,next_y,last_x,last_y;
	// clear convex
	convex_x.clear();
	convex_y.clear();
	
	//find leftmost and add it to convex (first point)
	i = find_leftmost(kingdom_x);
	cout << "leftmost: " << i << endl;
	convex_x.push_back(kingdom_x[i]);
	convex_y.push_back(kingdom_y[i]); 
	k=0;
	do{
		cout << k << "th while" << endl;
		last_x = convex_x[k];
		last_y = convex_y[k];

		next_x = kingdom_x[0];
		next_y = kingdom_y[0];

		for(i=1;i<kingdom_x.size();i++)
		{
			if ( (next_x == last_x && next_y == last_y) || (scalar_product ( next_y-last_y, -next_x+last_x , kingdom_x[i]-last_x, kingdom_y[i]-last_y) > 0))
				{ 
				next_x = kingdom_x[i]; 
				next_y = kingdom_y[i];
				}
		}
		convex_x.push_back(next_x);
		convex_y.push_back(next_y);
		k++;
	}while(!(convex_x[0] == next_x && convex_y[0] == next_y));

}


int main()
{
	int n,x,y,i,j,k;
	



	k=0;
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

	// test leftmost:
	cout << "test leftmost: " << find_leftmost(kingdoms_x[0]) << endl;
	jarvis(kingdoms_x[0],kingdoms_y[0],convexes_x[0],convexes_y[0]);
	
	cout << "convex: " << convexes_x[0].size() << " " << convexes_y[0].size() << endl;

	while(cin >> x >> y)
	{
		//explode_bomb(x,y);
	}
	return 0;
}
