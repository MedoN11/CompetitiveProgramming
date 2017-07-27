#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<complex>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<double,double> pii;
using namespace std;

// Dynamic Programming on strings
string str;
int t;
int dp[110][110];
int inf = 1 << 28;
int solve(int l,int r)
{
	if(l > r)
		return 0;
	int &ret = dp[l][r];
	if(ret != -1)
		return ret;
	ret = inf;
	if(str[l] == ']')
		return ret = 1 + solve(l + 1,r);
	if(str[l] == ')')
		return ret = 1 + solve(l + 1,r);
	if(str[l] == '(')
	{
		// place ) at end
		ret = min(ret,1 + solve(l + 1,r));
		for(int j = r ; j > l ; --j)
		{
			if(str[j] == ')')
				ret = min(ret,solve(l + 1,j - 1) + solve(j + 1,r));
		}
	}
	if(str[l] == '[')
	{
		// place ] at end
		ret = min(ret,1 + solve(l + 1,r));
		for(int j = r ; j > l ; --j)
		{
			if(str[j] == ']')
				ret = min(ret,solve(l + 1,j - 1) + solve(j + 1,r));
		}
	}
	return ret;
}

string trace(int l,int r)
{
	if(l > r)
		return "";

	if(str[l] == ']')
		return "[]" + trace(l + 1,r);
	if(str[l] == ')')
		return "()" + trace(l + 1,r);
	int ret = inf;
	int opt = solve(l,r);
	if(str[l] == '(')
	{
		// place ) at end
		ret = min(ret,1 + solve(l + 1,r));
		if(ret == opt) return "("+trace(l + 1,r) + ")";
		for(int j = r ; j > l ; --j)
		{
			if(str[j] == ')')
				ret = min(ret,solve(l + 1,j - 1) + solve(j + 1,r));
			if(ret == opt)
			{
				return "("+trace(l + 1,j - 1)+")" + trace(j + 1,r);
			}
		}
	}
	if(str[l] == '[')
	{
		// place ] at end
		ret = min(ret,1 + solve(l + 1,r));
		if(ret == opt) return "["+trace(l + 1,r) + "]";
		for(int j = r ; j > l ; --j)
		{
			if(str[j] == ']')
				ret = min(ret,solve(l + 1,j - 1) + solve(j + 1,r));
			if(ret == opt)
			{
				return "["+trace(l + 1,j - 1) + "]"+ trace(j + 1,r);
			}
		}
	}
	return "";
}
int main()
{

	//std::ios_base::sync_with_stdio(false);


	cin >> t; cin.ignore();
	while(t--)
	{
		getline(cin,str);
		getline(cin,str);
		//cerr << sz(str) << "\n";
		if(sz(str) == 0)
			cout <<""<<"\n";
		else
		{
			memset(dp,-1,sizeof(dp));
			//cout << solve(0,sz(str) - 1) << "\n";
			//cout << solve(0,sz(str) - 1) + sz(str) << "\n";
			//cout << sz(trace(0,sz(str) - 1)) << "\n";
			cout << trace(0,sz(str) - 1) << "\n";
		}
		if(t) cout << "\n";
	}
}
