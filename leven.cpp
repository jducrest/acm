#include <iostream>
#include <vector>

#define DEL 1
#define REP 2
#define INS 3

using namespace std;

vector<int> position; 
vector<int> action;
int d[100][100];
char s[100];
char t[100];
char ch[100][100];
int ldist(int len_s,int len_t);
int find(int ls,int lt);

int find(int ls,int lt)
{
	if(d[ls][lt]==-1)
	{
		d[ls][lt] = ldist(ls,lt);
		return d[ls][lt];
	}
	else
		return d[ls][lt];
}
// len_s and len_t are the number of characters in string s and t respectively
int ldist(int len_s,int len_t)
{ 
  int cost,a,b,c;

  /* base case: empty strings */
  if (len_s == 0)
  {
  	ch[len_s][len_t] = t[len_t];
  	return find(len_s,len_t-1)+1;
  }
  if (len_t == 0) return len_s;

  /* test if last characters of the strings match */
  if (s[len_s-1] == t[len_t-1])
      cost = 0;
  else
      cost = 1;

  /* return minimum of delete char from s, delete char from t, and delete char from both */
  a = find(len_s -1, len_t);
  b = find(len_s, len_t-1);
  c = find(len_s-1,len_t-1);
  if(c<= a && c <= b)
  {
  	ch[len_s][len_t] = t[len_t];
  	return c+cost;
  }
  else if (a<= b && a <= c)
  {
  	ch[len_s][len_t] = t[len_t];
		return a + 1;
  }
  else if(b<= a && b <= c)
  {
  	ch[len_s][len_t] = t[len_t];
  	return b+1;
  }
}

int main()
{
	int i,j,k;
	int len_s, len_t;
	while(cin >> s >> t)
	{
		// clean
		for(i=0;i<100;i++)
			if(s[i]=='\0')
				break;
				
		len_s = i;
		for(i=0;i<100;i++)
			if(t[i] == '\0')
				break;
		len_t = i;
		
		for(i=0;i<100;i++)
			for(j=0;j<100;j++)
				d[i][j] = i-1;
		

		// algo:
		find(len_s,len_t);
		
		cout << "dist: " << d[len_s][len_t] << endl;
		while(len_s!=0)
		{
			if(d[len_s][len_t] == d[len_s-1][len_t-1])
			{
				cout << "rien fait sur "<<len_s<<endl;
				len_s--;
				len_t--;
			}
			else if(d[len_s][len_t] == d[len_s-1][len_t-1] + 1)
			{
				cout << "Replace " << len_s<<","<<ch[len_s][len_t]<< endl; 
				len_t--;
				len_s--;
			}
			else if(d[len_s][len_t] == d[len_s-1][len_t]+1)
			{
				cout << "Delete " << len_s << endl;
				len_s--;
			}
			else if(d[len_s][len_t] == d[len_s][len_t-1] + 1)
			{
				cout << "Insert " << len_s << "," << ch[len_s][len_t] << endl;
				len_t--;
			}
		}
		
	}
	
}
