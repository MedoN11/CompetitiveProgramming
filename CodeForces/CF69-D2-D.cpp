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
using namespace std;
typedef pair<int,int> pii;

// DP + min-max theorm for games
pii arr[25];
int dp[2000][2000][2][2][2];
int n,d;
int dis(int x,int y)
{
	return (x*x) + (y*y);
}
int solve(int x,int y,int turn,int refA,int refB)
{

	if(dis(x,y) > d)
	{
		// losing state
		return turn ^ 1;
	}
	int &ret = dp[x + 1000][y + 1000][turn][refA][refB];
	if(ret != -1)
		return ret;
	if(turn == 0)
	{
		 ret = 0;
		if(!refA) ret = max(ret,solve(y,x,!turn,1,refB));
		for(int i = 0 ; i < n ; ++i)
		{
			ret = max(ret,solve(x + arr[i].first,y + arr[i].second,!turn,refA,refB));
		}
		return ret;
	}
	else
	{
		ret = 1;
		if(!refB) ret = min(ret,solve(y,x,!turn,refA,1));
		for(int i = 0 ; i < n ; ++i)
		{
			ret = min(ret,solve(x + arr[i].first,y + arr[i].second,!turn,refA,refB));
		}
		return ret;
	}



}


int main()
{
	int x,y;
	scanf("%d %d %d %d",&x,&y,&n,&d);
	d *= d;
	memset(dp,-1,sizeof(dp));
	for(int i = 0 ; i < n ; ++i) scanf("%d %d",&arr[i].first,&arr[i].second);

	int ans = solve(x,y,0,0,0);
	cerr << ans << "\n";
	if(ans)
		puts("Anton");
	else puts("Dasha");

}

