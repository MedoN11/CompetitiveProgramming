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
#include<string>
#include<vector>
#include<numeric>
using namespace std;


typedef long long ll;
typedef pair<int,ll> pii;
int n,k,p;
vector<int> dp;
int main()
{
	scanf("%d %d %d",&n,&k,&p);
	dp.resize(n);
	int ans = 1 << 30;
	for(int i = 0 ; i < n ; ++i)
	{
	    scanf("%d",&dp[i]);
		if(i > 0)
		dp[i] += dp[i - 1]; dp[i] %= p;
	}
	sort(dp.begin(),dp.end());

	for(int i = 1 ; i < n ; ++i)
	{
		int lo = 0;
		int hi = i - 1;
		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			if((dp[i] - dp[mid])  >= k)
			{
				ans = min(ans,dp[i] - dp[mid]);
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
	}
	printf("%d\n",ans);
}
