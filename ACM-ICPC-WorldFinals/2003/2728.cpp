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

int target;
int n;
int dis[51][51];
vector<int> src,sink;
int DP[51][201][2];
int pre[2][51];
int solve(int train,int tim,int dir)
{

	if(tim > target)
		return 1 << 30;
	if(tim == target)
		return train == n - 1 ? 0 : 1 << 30;
	int &ret = DP[train][tim][dir];
	if(ret != -1)
		return ret;
	ret = 1 << 30;
	if(train == n - 1)
		ret = min(ret,target - tim);
	// go to next station
	if(!dir)
	{
		if(train != n - 1)
		{

			ret = min(ret,solve(train + 1,tim + dis[train][train + 1],dir));
		}
	}
	else
	{
		if(train != 0)
		{
			ret = min(ret,solve(train - 1,tim + dis[train][train - 1],dir));

		}
	}
	// change trains at current station
	REP(i,src)
	{
		int tohere = pre[0][train] + src[i];
		if(tohere >= tim)
		ret = min(ret,tohere - tim + solve(train,tohere,0));
	}
	REP(i,sink)
	{
		int tohere = pre[1][train] + sink[i];
		if(tohere >= tim)
		ret = min(ret,tohere - tim + solve(train,tohere,1));
	}
	return ret;
}

int main()
{
	int tc = 1;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		scanf("%d",&target);
		memset(dis,0,sizeof(dis));
		for(int i = 0 ; i < n - 1 ;++i)
		{
			int x; scanf("%d",&x);
			dis[i][i + 1] = dis[i + 1][i] = x;
		}
		memset(pre,0,sizeof(pre));

		src.clear(); sink.clear();
		memset(DP,-1,sizeof(DP));
		int m; scanf("%d",&m);
		while(m--)
		{
			int x; scanf("%d",&x); src.push_back(x);
		}
		scanf("%d",&m);
		while(m--)
		{
			int x; scanf("%d",&x); sink.push_back(x);
		}

		for(int i = 1 ; i < n ; ++i)
			pre[0][i] = pre[0][i - 1] + dis[i - 1][i];
		for(int i = n - 2 ; i >= 0 ; --i)
			pre[1][i] = pre[1][i + 1] + dis[i][i + 1];

		int ans = 1 << 30;
		for(int i = 0 ; i < sz(src) ; ++i)
			ans = min(ans,src[i] + solve(0,src[i],0));
		printf("Case Number %d: ",tc++);
		if(ans == 1 << 30)
			printf("impossible");
		else printf("%d",ans);
		printf("\n");
	}
}

