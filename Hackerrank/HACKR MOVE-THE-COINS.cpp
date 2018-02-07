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
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define time __time
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 300005;
vector<int> tree[maxn];
int dp[maxn][2];
int dep[maxn];
int pr[maxn];
int deg[maxn];
int tin[maxn],tout[maxn];
int arr[maxn];
int n;
int tim = 0;
int sum = 0;
//Staircase nim on trees.
//We also need to calculate some  dp on trees storing sum of xor values of even/odd levels for every node.
void dfs(int u,int d) {
	dep[u] = d;
	tin[u] = tim++;
	dp[u][1] = arr[u];
	dp[u][0] = 0;
	REP(i,tree[u]) {
		int v = tree[u][i];
		if(pr[u] == v)
			continue;
		pr[v] = u;
		dfs(v,d + 1);
		dp[u][0] ^= dp[v][1];
		dp[u][1] ^= dp[v][0];
	}
	tout[u] = tim++;
}

bool subtree(int u,int v) {
	// v lies in subtree of u
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}
int main() {
	scanf("%d",&n);
	for (int i = 0 ; i  < n ; ++i) {
		scanf("%d",&arr[i]);
	}
	int u,v;
	for (int i = 0 ; i < n - 1 ; ++i) {
		scanf("%d %d",&u,&v);
		--u;--v;
		tree[u].pb(v);
		tree[v].pb(u);
	}
	dfs(0,1);
	int q;
	scanf("%d",&q);
	while(q--) {
		scanf("%d %d",&u,&v);
		--u;--v;
		if(!subtree(u,v)) {
			sum = dp[0][0];
			if(dep[pr[u]] % 2)
				sum ^= dp[u][1];
			else sum ^= dp[u][0];
			if(dep[v] % 2 == 1) sum ^= dp[u][1];
			else sum ^= dp[u][0];
			cerr << sum << "\n";
			if(sum) puts("YES");
			else puts("NO");
		} else puts("INVALID");
	}
}

