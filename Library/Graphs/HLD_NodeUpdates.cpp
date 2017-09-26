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
int n;
const int isValueOnEdge = 0;
const int maxn = 100005;
const int hld_maxn = 100005;
vector<int> tree[maxn];
int ans[4*maxn];

// Heavy Light decomposition Template
// Solves Timus 1553 to illustrate idea
// Updates here are assumed on NODE not edge.
struct SegmentTree
{

	int SIZE;
	void init(int SIZE)
	{
		this->SIZE = SIZE;
		memset(ans, 0, sizeof(ans));
	}
	void upd(int ind)
	{
		ans[ind] = max(ans[ind << 1],ans[(ind << 1) | 1]);
	}

	void update(int ind,int lo,int hi,int pt,int val)
	{
		if(pt < lo || pt > hi)
			return;
		if(pt == lo && pt == hi)
		{
			ans[ind] += val;
			return;
		}
		int mid = lo + (hi - lo) / 2;
		update(ind << 1,lo,mid,pt,val);
		update((ind << 1) | 1,mid + 1,hi,pt,val);
		upd(ind);
	}
	int query(int ind,int lo,int hi,int l,int r)
	{
		// l and r are range I query
		if(l > hi || r < lo)
			return 0;
		if(l <= lo && hi <= r)
		{
			return ans[ind];
		}
		int mid = lo + (hi - lo) / 2;
		int a = query(ind << 1,lo,mid,l,r);
		int b = query((ind << 1) | 1,mid + 1,hi,l,r);
		return max(a,b);
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
			if(pr[u] == v)
				continue;
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

		segTree.init(n);

	}

	void queryChain(int l,int r)
	{
		// assumes l and r are segTreePos
		queryAns = max(queryAns,segTree.query(1,0,n - 1,l,r));

	}
	int queryPath(int u,int v)
	{
		queryAns = 0;
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

		return queryAns;
	}
	void updatePos(int treeNode, int value)
	{
		int ind = segTreePos[treeNode];
		segTree.update(1,0,n - 1,ind,value);
	}

};
int q,u,v;
int main()
{
	ios
	HLD hld;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> u >> v;
		--u; --v;
		tree[u].pb(v), tree[v].pb(u);

	}

	hld.buildChains();

	for(int i = 0 ; i < n ; ++i)
		hld.updatePos(i,0);
	cin >> q;
	char k;
	int a,b;
	while(q--)
	{
		//scanf("%c %d %d",&k,&a,&b);
		cin >> k >> a >> b;

		if(k == 'I')
		{
			--a;
		hld.updatePos(a,b);

		}
		else
		{
			--a,--b;
			cout << hld.queryPath(a,b) << "\n";
		}
	}


}
