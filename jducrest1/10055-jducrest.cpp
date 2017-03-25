#include <iostream>

using namespace std;

long absolute(long x){
	if(x>=0)
		return x;
	else 
		return -x;
}


int main()
{
    long a,b;
    while(cin>>a>>b)
        cout << absolute(a-b)<<"\n";
    return 0;
}
