#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <unordered_map>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define ll  long long
using namespace std;
typedef vector<int> vi;
vector<pair<int,pair<int,int> > > edges;
vector<pair<int,int> > tree[3001];
int n,e;
class DSU {
private:
	vi p, rank, setSize;
	int numSets;
public:
	DSU(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) { numSets--;
		int x = findSet(i), y = findSet(j);

		if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
		else                   { p[x] = y; setSize[y] += setSize[x];
		if (rank[x] == rank[y]) rank[y]++; } } }
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int lvl[3001];
int K[3001];
int pr[3001];
int DP[3001][20];
int DP2[3001][20];

int solve(int i,int j)
{
	if(j == 0)
		return pr[i];
	int &ret = DP[i][j];
	if(ret != -1)
		return ret;
	return ret = solve(solve(i,j - 1),j - 1);
}


int minCost(int i,int j)
{
	if(j == 0)
		return K[i];
	int &ret = DP2[i][j];
	if(ret != -1)
		return ret;
	ret = ret = max(minCost(i,j - 1),minCost(solve(i, j -1),j - 1));
	return ret;
}
void dfs(int u,int dep)
{
	lvl[u] = dep;

	REP(j,tree[u])
	{
		int v = tree[u][j].first; int cost = tree[u][j].second;
		if(pr[u] == v)
			continue;
		pr[v] = u;
		K[v] = cost;
		dfs(v,dep + 1);
	}
}

int lca(int i,int j)
{
	int mx = 0;
	int log = 20;
	if(lvl[i] < lvl[j])
		swap(i,j);
	for(int k = log ; k >= 0 ; --k)
	{
		int next = solve(i,k);
		if(lvl[next] >= lvl[j])
		{
			mx = max(mx,minCost(i,k));
			i = next;

		}
	}
	if(i == j)
		return mx;
	for(int k = log ; k >= 0 ; --k)
	{
		int nexti = solve(i,k);
		int nextj = solve(j,k);
		if(nexti != nextj)
		{
			mx = max(mx,minCost(i,k));
			mx = max(mx,minCost(j,k));
			i = nexti, j = nextj;

		}
	}
	mx = max(mx,max(K[i],K[j]));
	return mx;

}

int main()
{
	int tc;
	scanf("%d",&tc);
	int t = 1;
	while(tc--)
	{
		scanf("%d %d",&n,&e);
		int u,v,d;
		edges.clear();
		for(int i = 0 ; i < n ; ++i)
			tree[i].clear();
		for(int i = 0 ; i < e ; ++i)
		{
			scanf("%d %d %d",&u,&v,&d);
			--u; --v;
			edges.push_back(make_pair(d,make_pair(u,v)));
		}
		DSU dsu(n);
		sort(edges.begin(),edges.end());
		REP(i,edges)
		{
			d = edges[i].first;
			int u = edges[i].second.first; int v = edges[i].second.second;
			if(!dsu.isSameSet(u,v))
			{
			dsu.unionSet(u,v);
			tree[u].push_back(make_pair(v,d));
			tree[v].push_back(make_pair(u,d));
			}
		}
		memset(DP,-1,sizeof(DP));
		memset(DP2,-1,sizeof(DP2));
		memset(pr,0,sizeof(pr));
		int q;
		scanf("%d",&q);
		K[0] = 0;
		pr[0] = 0;
		dfs(0,0);
		printf("Case %d\n",t++);
		while(q--)
		{
			scanf("%d %d",&u,&v);
			--u; --v;
			cout << lca(u,v) << "\n";
		}
		cout << "\n";
	}
}

