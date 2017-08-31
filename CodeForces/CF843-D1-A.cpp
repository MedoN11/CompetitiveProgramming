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
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,ll> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
int n;
const int maxn = 100005;
vector<int> grp[maxn];
int pr[maxn];
int sets;
void merge(int u,int v)
{
	u = pr[u],v = pr[v];
	if(u == v)
		return;
	--sets;
	if(sz(grp[u]) < sz(grp[v]))
	{
		swap(u,v);
	}
	REP(i,grp[v])
	{
		int x = grp[v][i]; pr[x] = u;
		grp[u].pb(x);
	}
}
bool vis[maxn];
int main()
{
	scanf("%d",&n); int x;
	vector<pii> a(n);
	sets = n;
	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%d",&x);
		a[i].first = x;
		grp[i].pb(i);
		pr[i] = i;
		a[i].second = i;

	}
	sort(all(a));
	for(int i = 0 ; i < n ; ++i)
	{
		merge(a[i].second,i);
	}
	printf("%d\n",sets);
	for(int i = 0 ; i < n ; ++i)
	{
		if(vis[pr[i]])
			continue;
		vis[pr[i]] = true;
		printf("%d",sz(grp[pr[i]]));
		REP(j,grp[pr[i]])
		printf(" %d",grp[pr[i]][j] + 1);
		puts("");
	}


}
