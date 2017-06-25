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
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define pb push_back
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

int f[26];
int dp[1000001];

void calc(int n)
{
	for(int i = 1 ; i <= n ; ++i)
	{
		int x = i;
		for(int j = 2 ; j * j <= x; ++j)
		{

			while(x % j == 0)
			{
				dp[j]++;
				x /= j;
			}
		}
		if(x > 1) dp[x]++;
	}
}
void calc2(int n)
{
	for(int i = 1 ; i <= n ; ++i)
	{
		int x = i;
		for(int j = 2 ; j * j <= x; ++j)
		{

			while(x % j == 0)
			{
				dp[j]--;
				x /= j;
			}
		}
		if(x > 1) dp[x]--;
	}
}
int main()
{

	fast
	string str;
	while(cin >> str)
	{
		memset(f,0,sizeof(f));

		REP(i,str) f[str[i]-'a']++;
		calc(sz(str));
		for(int i = 0 ; i < 26 ; ++i) if(f[i] > 1)calc2(f[i]);
		if(dp[2] > dp[5])
		{
			dp[2] -= dp[5];
			dp[5] = 0;
		}
		else dp[5] -= dp[2],dp[2] = 0;
		int ans = 1;
		for(int i = 1 ; i <= sz(str) ; ++i)
		{
			while(dp[i] > 0) ans *= i,ans %= 10,dp[i]--;
		}
		cout << ans << "\n";
		//printf("%d\n",ans);
	}
}
