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
#include<complex>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
using namespace std;
#define ll  long long
int two[205],five[205];
int dp[2][201][5005];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);

	for(int i = 0 ; i < n ; ++i)
	{
		ll num;
		scanf("%lld",&num);
		while(num % 2 == 0) two[i]++,num /= 2;
		while(num % 5 == 0) five[i]++, num /= 5;
	}
	int INF = 1 << 30;


	for(int j = 0 ; j < k ; ++j)
	{
		for(int k = 0 ; k < 5001 ; ++k) dp[0][j][k] = dp[1][j][k] = -INF;
	}


	dp[n % 2][0][0] = 0;
	for(int i = n - 1 ; i >= 0 ; --i)
	{
		for(int j = 0 ; j <= k ; ++j)
		{
			for(int c = 0 ; c < 5001 ; ++c)
			{

				dp[i % 2][j][c] = -INF;

			}
		}
		for(int j = 0 ; j <= k ; ++j)
		{
			for(int c = 0 ; c < 5001 ; ++c)
			{
				if(c - five[i] >= 0 && j - 1 >= 0)
				{
					dp[i % 2][j][c] = max(dp[i & 1][j][c],two[i] + dp[(i + 1) % 2][j - 1][c - five[i]]);
				}
				dp[i % 2][j][c] = max(dp[i % 2][j][c],dp[(i + 1) % 2][j][c]);

			}
		}
	}
	int best = 0;
	for(int i = 0 ; i < 5001 ; ++i)
	{
		best = max(best,min(i,dp[0][k][i]));
	}
	cout << best << "\n";

}
