#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
using namespace std;
#define ll long long
typedef long double ld;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define clr(x) memset(x,0,sizeof(x));
typedef vector<int> vi;
#include <iostream>
#include <cmath>
#include <complex>
#include <cassert>
using namespace std;
string str;
int diff = 0;


/*


 if number of different charaters <= S then it's possible by assinging each character to it's own stack
 otherwise some stacks will contain mixed characters
 otherwise
  process string from left to right
  greedily pick the nearest character on top a stack to the current character
  if none exists use a new stack




 */

int solve()
{

	char top[5001]; for(int k = 0 ; k < 5001 ; ++k) top[k] = '-';
	int lst = 0;
	REP(j,str)
	{
		char least = 'Z';
		int ind = -1;
		for(int i = 0 ; i <= lst ; ++i)
		{
			if(top[i] == '-')
				continue;
			if(str[j] <= top[i] && top[i] <= least)
			{
				least = top[i];
				ind = i;
			}
		}
		if(ind == -1)
		{
			top[lst++] = str[j];

		}
		else top[ind] = str[j];
	}

	return lst;

}
int main()
{

	//	for(char c = 'A'; c <= 'Z' ; ++c)
	//		cerr << c << " ";
	int tc = 1;
	while(cin >> str)
	{
		if(str == "end")
			break;
		set<char> seen;
		REP(j,str)
		{
			if(seen.find(str[j]) != seen.end())
				continue;
			seen.insert(str[j]);
		}
		diff = seen.size();
		int ans = solve();

		printf("Case %d: %d\n",tc++,min(ans,diff));

	}
}
