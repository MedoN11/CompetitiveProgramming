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
int n,m;
vector<int> g[500];
int col[500];
int comp = 0;
vector<int> compLeft[500];
vector<int> compRight[500];
bool BAD = 0;
vector<int> v1,v2;
void bia(int ind)
{
	queue<int> q;
	q.push(ind);
	col[ind] = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(!col[u])
			compLeft[comp].pb(u);
		else compRight[comp].pb(u);
		REP(i,g[u])
		{
			int nxt = g[u][i];
			if(col[nxt] == -1)
			{
				col[nxt] = 1 - col[u];
				q.push(nxt);
			}
			else
			{
				if(col[nxt] == col[u])
					BAD = 1;
			}
		}
	}
}
int dp[500][500];
int solve(int ind,int rem)
{
	if(rem < 0)
		return 0;
	if(ind == comp)
	{
		return rem == 0 ? 1 : 0;
	}
	int &ret = dp[ind][rem];
	if(ret !=  -1)
		return ret;
	ret = 0;
	// assign left
	ret |= solve(ind + 1,rem - sz(compLeft[ind]));

	// assign right
	ret |= solve(ind + 1,rem - sz(compRight[ind]));
	return ret;


}

void trace(int ind,int rem)
{
	if(rem < 0)
		return;
	if(ind == comp)
	{
		return;
	}
	int &ret = dp[ind][rem];

	ret = 0;
	// assign left
	if(solve(ind + 1,rem - sz(compLeft[ind])))
	{
		REP(i,compLeft[ind]) v1.pb(compLeft[ind][i]);
		REP(i,compRight[ind]) v2.pb(compRight[ind][i]);
		trace(ind + 1,rem - sz(compLeft[ind]));
	}
	else
	{
		REP(i,compLeft[ind]) v2.pb(compLeft[ind][i]);
		REP(i,compRight[ind]) v1.pb(compRight[ind][i]);
		trace(ind + 1,rem - sz(compRight[ind]));

	}



}
int main()
{
	scanf("%d %d",&n,&m);
	n <<= 1;
	int u,v;
	memset(col,-1,sizeof(col));
	for(int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d",&u,&v); --u; --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(col,-1,sizeof(col));
	for(int i = 0 ; i <  n && !BAD ; ++i)
	{
		if(col[i] == -1)
		{
			bia(i);
			comp++;
		}
	}
	if(BAD)
	{
		puts("IMPOSSIBLE");
		return 0;
	}

	memset(dp,-1,sizeof(dp));
	int ok = solve(0,n / 2);
	if(!ok)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	trace(0,n / 2);
	sort(all(v1)); sort(all(v2));
	printf("%d",v1[0] + 1);
	for(int i = 1 ; i < sz(v1) ; ++i) printf(" %d",v1[i] + 1);
	printf("\n");
	printf("%d",v2[0] + 1);
	for(int i = 1 ; i < sz(v2) ; ++i) printf(" %d",v2[i] + 1);
	printf("\n");


}
