#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<complex>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define read(f) freopen (f,"r",stdin)
#define write(f) freopen (f,"w",stdout)
typedef pair<int,int> ii;
// 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8

struct PascalCount
{
	int howMany(int i,int d);
};

int calc(int n,int p)
{
	// log(n)
	int cnt = 0;
	int q = p;
	while(q <= n)
	{
		cnt += n / q;
		q *= p;
	}
	return cnt;
}
int dp[1501][1501];
int pascalsNaive(int n,int d)
{

	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; ++i)
	{
		dp[i][0] = 1;
		for(int j = 1 ; j <= n ; ++j)
		{
			dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	int x = 0;
	for(int f = 1 ; f <= n - 1 ; ++f)
		if(dp[n][f] % d == 0) ++x;
	return x;
}
// 3^3 * (2)/ 2^2 * 5  = 3^3 * 5 * 2
// pascals = n! / ( (n - k)! * k!)
int PascalCount::howMany(int n,int d)
{
	int ans = 0;
	if(d == 2 || d == 3 || d == 5)
	{
		int num = calc(n,d);
		for(int k = 1 ; k <= n - 1 ; ++k)
		{
			int den = calc(k,d) + calc(n - k,d);
			if(num && num > den)
				++ans;
		}
	}
	if(d == 6)
	{
		int num2 = calc(n,2); int num3 = calc(n,3);

		for(int k = 1 ; k <= n - 1 ; ++k)
		{
			int den2 = calc(k,2) + calc(n - k,2);
			int den3 = calc(k,3) + calc(n - k,3);
			if(num2 && num3 && num2 > den2 && num3 > den3)
				++ans;
		}
	}

	if(d == 4)
	{
		int num = calc(n,2);
		for(int k = 1 ; k <= n - 1 ; ++k)
		{
			int den = calc(k,2) + calc(n - k,2);
			if(num && num - den >= 2)
				++ans;
		}
	}
	cerr << ans << " " << pascalsNaive(n,d);
	//assert(ans == pascalsNaive(n,d));
	return ans;
}

int main()
{
	PascalCount p;
	int n,d; cin >> n >> d;
	cout << p.howMany(n,d);
}

