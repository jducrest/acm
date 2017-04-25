#include <iostream>
#include <vector>

vector<int> kingdoms[200];

int main()
{
	int n,x,y,i;
	
	k=0;
	while(1)
	{
		cin >> n ;

		if(c == -1)
			break;

		for(i=0;i<n;i++)
		{
			cin >> x >> y;
			kingdoms_x[k].push_back(x);
			kingdoms_y[k].push_back(y);
		}
		k++;
	}

	while(cin >> x >> y)
	{
		explode_bomb(x,y);
	}
	return 0;
}
