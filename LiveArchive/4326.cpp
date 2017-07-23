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
#include <complex>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)

/*
 Bruteforce + MST
 try all subsets of nodes, and connect them with MST.

 */
int n,m;
int w[20];
typedef pair<int,int> pii;
typedef pair<int,pii> edge;
vector<edge> edges;
vector<int> ans;
typedef vector<int> vi;
class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) { numSets--;
		int x = findSet(i), y = findSet(j);
		// rank is used to keep the tree short
		if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
		else                   { p[x] = y; setSize[y] += setSize[x];
		if (rank[x] == rank[y]) rank[y]++; } } }
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

double solve(int msk)
{
	double num = 0;
	double den = 0;
	for(int i = 0 ; i < n ; ++i) if(msk & (1 << i)) num += w[i];
	UnionFind dsu(n);
	REP(i,edges)
	{
		int c = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
		// both ok edges
		if((msk & (1 << u)) && (msk & (1 << v)))
		{
			if(!dsu.isSameSet(u,v))
			{
				den += c;
				dsu.unionSet(u,v);
			}
		}
	}
	return (den*1.0)/(num*1.0);
}
double EPS = 1e-9;
int main()
{
	while(scanf("%d %d",&n,&m) != EOF)
	{
		if(n + m == 0)
			break;
		edges.clear();
		ans.clear();
		for(int i = 0 ; i < n ;  ++i) scanf("%d",&w[i]);
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < n ; ++j)
			{
				int x;
				scanf("%d",&x);
				if(x)
					edges.pb(edge(x,pii(i,j)));
			}

		}

		sort(all(edges));
		double best = 1 << 30;
		for(int msk = 0 ; msk < (1 << n) ;  ++msk)
		{
			if(__builtin_popcount(msk) != m)
				continue;
			double curr = solve(msk);
			if(curr < best )
			{
				ans.clear();
				for(int j = 0 ; j < n ; ++j) if(msk & (1 << j)) ans.pb(j + 1);
				best = curr;
			}
		}

		printf("%d",ans[0]);
		for(int i= 1 ; i < sz(ans) ; ++i) printf(" %d",ans[i]);
		printf("\n");
	}

}



