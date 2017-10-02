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

// HLD + SegTree for gcd range and query updates
int n;
const int isValueOnEdge = 0;
const int maxn = 50001;
const int hld_maxn = 50001;
vector<int> tree[maxn];
int ans_diff[4*maxn];
int node_val[maxn];
int arr[maxn];

int gcd(int a,int b) {

	if(a == 0 || b == 0) {
		return a + b;
	}
	return __gcd(a,b);
}
struct Segment {
	int fst,lst,gcd_diff,lazy;
	Segment() {fst = 0,lst = 0, gcd_diff = 0,lazy = 0;}
	Segment(int f,int s,int gg,int k){
		fst = f,lst = s,gcd_diff = gg;
		lazy = k;
	}
	void merge(Segment &o,Segment &ret) {
		ret.lazy = 0;
		ret.fst = fst + lazy;
		ret.lst = o.lst + o.lazy;
		ret.gcd_diff = abs((o.fst + o.lazy) - (this->lst + lazy));
		ret.gcd_diff = gcd(this->gcd_diff,ret.gcd_diff);
		ret.gcd_diff = gcd(ret.gcd_diff,o.gcd_diff);

	}
};
Segment interval[4*maxn];
struct SegmentTree {

	void init(int n) {
		memset(interval,0,sizeof(interval));
		build(1,0, n - 1);
	}

	void build(int ind,int l,int r) {

		if(l == r) {
			interval[ind] = Segment(arr[l],arr[l],0,0);
			return;
		}
		int m = l + (r - l) / 2;
		build(ind << 1,l,m);
		build((ind << 1) | 1,m + 1,r);
		interval[ind << 1].merge(interval[(ind << 1) | 1],interval[ind]);

	}

	void prop(int ind) {
		int s = interval[ind].lazy;
		interval[ind].fst += s;
		interval[ind].lst += s;
		interval[ind].lazy = 0;
		interval[ind << 1].lazy += s;
		interval[(ind << 1) | 1].lazy += s;
	}

	void update(int ind,int lo,int hi,int l,int r,int val)
	{

		if(l > r || hi < 0)
			return ;
		// l and r are range I query
		if(l > hi || r < lo)
			return ;
		if(l <= lo && hi <= r)
		{
			interval[ind].lazy += val;
			return;
		}
		int mid = lo + (hi - lo) / 2;
		prop(ind);
		update(ind << 1,lo,mid,l,r,val);
		update((ind << 1) | 1,mid + 1,hi,l,r,val);
		interval[ind << 1].merge(interval[(ind << 1) | 1],interval[ind]);

	}
	int query(int ind,int lo,int hi,int l,int r)
	{

		if(l > r || hi < 0)
			return 0;
		// l and r are range I query
		if(l > hi || r < lo)
			return 0;
		if(l <= lo && hi <= r)
		{
			//cerr << interval[ind].lazy << " " << interval[ind].fst << " " << interval[ind].gcd_diff << "\n";
			return gcd(interval[ind].lazy + interval[ind].fst,interval[ind].gcd_diff);
		}
		int mid = lo + (hi - lo) / 2;
		prop(ind);
		int a = query(ind << 1,lo,mid,l,r);
		int b = query((ind << 1) | 1,mid + 1,hi,l,r);
		return gcd(a,b);
	}
};
struct HLD
{
	int pr[hld_maxn],dep[hld_maxn],heavy[hld_maxn],segTreePos[hld_maxn],root[hld_maxn],segTreePosToNode[hld_maxn];
	int queryAns;
	SegmentTree segTree;

	int gcd(int a,int b)
	{
		if(a == 0 || b == 0)
			return a + b;
		return __gcd(a,b);
	}

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
		for(int i = 0 ; i < n ; ++i)
		{
			arr[i] = node_val[segTreePosToNode[i]];
		}

		segTree.init(n);

		//sumTree.init(n);

	}

	void queryChain(int l,int r)
	{
		queryAns = gcd(queryAns,segTree.query(1,0, n - 1,l,r));
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
	void updatePath(int u,int v,int k)
	{

		while(root[u] != root[v])
		{
			if(dep[root[u]] > dep[root[v]])
				swap(u,v);
			updatePos(segTreePos[root[v]],segTreePos[v],k);
			v = pr[root[v]];
		}
		if(dep[u] > dep[v])
			swap(u,v);
		if(!isValueOnEdge || u != v)
			updatePos(segTreePos[u] + isValueOnEdge,segTreePos[v],k);

	}
	void updatePos(int a, int b,int value)
	{

		segTree.update(1,0, n - 1,a,b,value);
	}

};

int q,u,v;
int main()
{
	//ios
	HLD hld;
	scanf("%d",&n);

	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d %d",&u,&v);
		tree[u].pb(v), tree[v].pb(u);

	}

	for(int i = 0 ; i < n ; ++i)
	{
		int x;
		scanf("%d",&x);
		node_val[i] = x;
	}
	hld.buildChains();

	scanf("%d",&q);
	char k;
	int d;
//	cerr << q << "\n";
	while(q--)
	{

		scanf(" %c",&k);
		//cerr << k << "\n";
		//cin >> k;
		if(k == 'F')
		{


			scanf(" %d %d",&u,&v);
			cout << hld.queryPath(u,v) << "\n";

		}
		else
		{
			scanf(" %d %d %d",&u,&v,&d);
			// cerr << u << " " << v << " " << d << "\n";
			hld.updatePath(u,v,d);

		}
		//cin.ignore();
	}


}
