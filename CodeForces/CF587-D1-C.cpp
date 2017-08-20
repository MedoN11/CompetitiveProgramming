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
const int maxn = 100005,maxlog = 18;
vector<int> node[maxn];
vector<int> tree[maxn];
bool dp[maxn][maxlog];
int dp_anc[maxn][maxlog];
vector<int> cache[maxn][maxlog];
int pr[maxn];
int n,m,q;
int lvl[maxn];

// LCA + Binary Lifting
// Modification of LCA Binary lifting to keep track of 10 minimums

void dfs(int u,int dep)
{
	lvl[u] = dep;
	REP(i,tree[u])
	{
		int v = tree[u][i];
		if(v == pr[u])
			continue;
		pr[v] = u;
		dfs(v,dep + 1);
	}
}
int anc(int u,int k)
{
	if(k == 0)
		return pr[u];
	int &ret = dp_anc[u][k];
	if(ret != -1)
		return ret;
	ret = anc(anc(u, k - 1),k - 1);
	return ret;
}

vector<int> merge(vector<int> &res,vector<int> &a, vector<int> &b)
								{
	int ptr1 = 0, ptr2 = 0;
	while(sz(res) < 10 && ptr1 < sz(a) && ptr2 < sz(b))
	{
		if(a[ptr1] < b[ptr2])
			res.pb(a[ptr1++]);
		else res.pb(b[ptr2++]);
	}
	while(sz(res) < 10 && ptr1 < sz(a)) res.pb(a[ptr1++]);
	while(sz(res) < 10 && ptr2 < sz(b)) res.pb(b[ptr2++]);
	return res;
								}
vector<int> solve(int u,int k)
		{
	if(dp[u][k])
		return cache[u][k];
	dp[u][k] = true;
	if(k == 0)
	{
		vector<int> ans;
		if(u != pr[u])
		{
			ans = node[u];
		}
		return cache[u][k] = vector<int>(ans.begin(),ans.begin() + min(10,sz(ans)));
	}

	dp[u][k] = true;
	vector<int> L = solve(u,k - 1);
	vector<int> R = solve(anc(u,k - 1),k - 1);

	vector<int> ret;
	ret = merge(ret,L,R);
	return cache[u][k] = vector<int>(ret.begin(),ret.begin() + min(10,sz(ret)));


		}
int LCA(int u,int v)
{
	if(lvl[u] > lvl[v])
		swap(u,v);
	for(int k = 17 ; k >= 0 ; --k)
	{
		int nxt = anc(v,k);
		if(lvl[nxt] >= lvl[u])
			v = nxt;
	}
	if(u == v)
		return u;
	for(int k = 17 ; k >= 0 ; --k)
	{
		int nxt_u = anc(u,k),nxt_v = anc(v,k);
		if(nxt_u != nxt_v)
			u = nxt_u, v = nxt_v;
	}
	return pr[u];
}

vector<int> merge(int u,int v)
		{
	if(lvl[u] < lvl[v])
		swap(u,v);
	int lca = LCA(u,v);
	vector<int> L,R;
	bool in = 0;
	int c1 = v,c2 = u;


	for(int k = 17 ; k >= 0 ; --k)
	{
		int nxt = anc(u,k);
		if(lvl[nxt] > lvl[lca] && lvl[nxt] < lvl[u])
		{
			//cerr << u+1 << " " << nxt+1 << "\n";
			in = 1;
			vector<int> curr = solve(u,k);
			vector<int> tmp;
			L = merge(tmp,curr,L);
			u = nxt;
		}

	}

	if(c2 != lca)
	{
		for(int i = 0 ; i < min(10,sz(node[u])) ; ++i)
		{
			L.pb(node[u][i]);
		}

	}



	for(int k = 17 ; k >= 0 ; --k)
	{
		int nxt = anc(v,k);
		if(lvl[nxt] > lvl[lca] && lvl[nxt] < lvl[v])
		{
			in = 1;
			//cerr << u << " " << nxt << "\n";
			vector<int> curr = solve(v,k);
			vector<int> tmp;
			R = merge(tmp,curr,R);
			v = nxt;
		}
	}

	if(c1 != lca)
	{
		for(int i = 0 ; i < min(10,sz(node[v])) ; ++i)
		{
			R.pb(node[v][i]);
		}
	}
	vector<int> ans;
	//	cerr <<"L : ";
	//	REP(i,L) cerr << L[i] + 1 << " ";
	//	cerr << "\n";
	//	cerr <<"R : ";
	//	REP(i,R) cerr << R[i] + 1 << " ";
	//	cerr << "\n";
	//	cerr <<"LCA : ";
	//REP(i,node[lca]) cerr << node[lca][i] + 1 << " ";
	for(int i = 0 ; i < min(10,sz(node[lca])) ; ++i) ans.pb(node[lca][i]);

	REP(i,L) ans.pb(L[i]);
	REP(i,R) ans.pb(R[i]);
	sort(all(ans));
	return vector<int> (ans.begin(),ans.begin() + min(sz(ans),10));

		}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	memset(dp_anc,-1,sizeof(dp_anc));
	int u,v;
	for(int i = 0 ; i < n - 1 ; ++i)
	{
		scanf("%d %d",&u,&v); --u; --v;
		tree[u].pb(v); tree[v].pb(u);
	}
	int x;
	for(int j = 0 ; j < m ; ++j)
	{
		scanf("%d",&x); --x;
		node[x].pb(j);
	}
	pr[0] = 0;
	dfs(0,0);
	int a;
	while(q--)
	{
		scanf("%d %d %d",&u,&v,&a); --u; --v;
		vector<int> res = merge(u,v);
		printf("%d",min(a,sz(res)));
		for(int i = 0 ; i < min(sz(res),a) ; ++i) printf(" %d",res[i] + 1);
		puts("");
	}
}
