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

bool can(int sz)
{
	if(sz >= diff)
		return 1;
	char top[sz + 5]; for(int k = 0 ; k < sz + 5 ; ++k) top[k] = '-';
	int lst = 0;
	REP(j,str)
	{
		char least = 'Z';
		int ind = -1;
		for(int i = 0 ; i < sz ; ++i)
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
			if(lst > sz)
				return 0;
		}
		else top[ind] = str[j];
	}

	return 1;

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
		int ans = 0;
		int lo = 1;
		int hi = 5000;
		set<char> seen;
		REP(j,str)
		{
			if(seen.find(str[j]) != seen.end())
				continue;
			seen.insert(str[j]);
		}
		diff = seen.size();
		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			if(can(mid))
			{
				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		printf("Case %d: %d\n",tc++,ans);

	}
}

