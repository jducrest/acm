#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,x,y,k,i;
	vector<int> xs;
	vector<int> ys;
	while(true)
	{
		cin >> n;
		if (n == 0)
			break;
		
		xs.clear();
		ys.clear();

		for(i=0;i<n;i++)
		{
			cin >> x >> y;
			xs.push_back(x);
			ys.push_back(y);
		}

		xs.push_back(xs[0]);
		ys.push_back(ys[0]);

		cin >> x >> y;
		
		k=0;
		for(i=0;i<n;i++)
		{
			if (xs[i] == xs[i+1])
				continue;

			if (ys[i] < y)
				continue;

			if (xs[i] < x && xs[i+1] < x)
				continue;

			if (xs[i] > x && xs[i+1] > x)
				continue;

			k++;
		}
		if(k%2)
			cout << "T" << endl;
		else
			cout << "F" << endl;
		
		
	}
	return 0;
}
