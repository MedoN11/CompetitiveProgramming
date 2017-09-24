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
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
// Exercise for HLD
// Solvable with Euler tour
int n;
const int isValueOnEdge = 0;
const int maxn = 100005;
const int hld_maxn = 100005;
vector<int> tree[maxn];
vector<int> treeEdgeInd[maxn];
vector<int> edge_to;
pii interval[maxn*4];
int mxV;
struct SegmentTree
{
	int idx, val, from, to;

	void init(int n)
	{
		mxV = n;
		memset(interval, 0, sizeof(interval));
	}
	void upd(int ind)
	{
		pii a = interval[ind << 1], b = interval[(ind << 1) | 1];
		interval[ind] = pii(0,ind);
		if(a.first == 1)
			interval[ind] = pii(1,a.second);
		else
		{
			if(b.first == 1) interval[ind] = pii(1,b.second);
		}
	}
	pii update(int s = 0, int e = mxV, int ind = 1)
	{
		if (s == e)
		{
			return interval[ind] = make_pair(val,idx);
		}
		int mid = (s + e) / 2;
		if (idx <= mid)
		{
			update(s, (s + e) / 2, 2 * ind);
		}
		else
		{
			if (idx > mid)
			{
				update((s + e) / 2 + 1, e, 2 * ind + 1);
			}
		}
		upd(ind);
		return interval[ind];
	}
	pii query(int s = 0, int e = mxV, int p = 1)
	{
		if (from <= s && to >= e)
			return interval[p];
		int mid = (s + e) / 2;
		if (to <= mid)
			return query(s, (s + e) / 2, 2 * p);
		if (from > mid)
			return query((s + e) / 2 + 1, e, 2 * p + 1);
		pii a = query(s, (s + e) / 2, 2 * p);
		pii b = query((s + e) / 2 + 1, e, 2 * p + 1);
		if(a.first)
			return a;
		return b;
	}
};

struct HLD
{
	int pr[hld_maxn],dep[hld_maxn],heavy[hld_maxn],segTreePos[hld_maxn],root[hld_maxn],segTreePosToNode[hld_maxn];
	int queryAns;
	SegmentTree segTree;

	int dfs_hld(int u)
	{
		int sz = 1, maxSubTree = 0;
		for(int k = 0 ; k < sz(tree[u]) ; ++k)
		{

			int v = tree[u][k];
			//int edgeInd = treeEdgeInd[u][k];
			if(pr[u] == v)
				continue;
			//edge_to[edgeInd] = v;
			pr[v] = u; dep[v] = dep[u] + 1;
			int ch_sz = dfs_hld(v);
			if(ch_sz > maxSubTree)
			{
				heavy[u] = v; maxSubTree = ch_sz;
			}
			sz += ch_sz;
		}
		return sz;
	}
	void buildChains()
	{

		// or size of heavy..just being more efficient
		memset(heavy,-1 , sizeof(heavy));
		pr[0] = -1,dep[0] = 0;
		dfs_hld(0);
		for(int chainRoot = 0 , pos = 0 ; chainRoot < n ; ++chainRoot)
		{
			if(pr[chainRoot] == -1 || heavy[pr[chainRoot]] != chainRoot)
			{
				for(int j = chainRoot; j != -1; j = heavy[j])
					root[j] = chainRoot,segTreePosToNode[pos] = j,segTreePos[j] = pos++;
			}
		}
		// init of segTree
		segTree.init(n);

	}

	void queryChain(int l,int r)
	{
		// assumes l and r are segTreePos
		segTree.from = l, segTree.to = r;
		pii ans = segTree.query();
		if(ans.first == 1)
			queryAns = segTreePosToNode[ans.second];
	}
	int queryPath(int u,int v)
	{
		queryAns = -1;
		while(root[u] != root[v])
		{
			if(dep[root[u]] > dep[root[v]])
				swap(u,v);
			queryChain(segTreePos[root[v]],segTreePos[v]);
			v = pr[root[v]];
		}
		if(dep[u] > dep[v])
			swap(u,v);
		if(!isValueOnEdge || u != v)
			queryChain(segTreePos[u] + isValueOnEdge,segTreePos[v]);
		if(queryAns != -1)
			queryAns++;
		return queryAns;
	}
	void updatePos(int treeNode, int value)
	{
		segTree.idx = segTreePos[treeNode], segTree.val = value;
		segTree.update();
	}

};
int q,u,v;
int lst[maxn];
int main()
{
	HLD hld;
	scanf("%d %d", &n,&q);

	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d %d", &u, &v);
		--u; --v;
		tree[u].pb(v), tree[v].pb(u);
		treeEdgeInd[v].pb(i), treeEdgeInd[u].pb(i);
	}
	hld.buildChains();

	for(int i = 0 ; i < n ; ++i)
		hld.updatePos(i,0),lst[i] = 0;
	int tp;
	while(q--)
	{
		scanf("%d %d",&tp,&u);
		--u;
		if(!tp)
		{
			hld.updatePos(u,1 ^ lst[u]);
			lst[u] ^= 1;
		}
		else
		{
			hld.queryPath(0,u);
			printf("%d\n",hld.queryAns);
		}
	}


}
