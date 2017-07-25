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

// MST

// ignore dijikstra' code
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

struct TimeTravellingSalesman
{
	ll determineCost(int n,vector<string> roads);
};
vector<int> token(string s,char delim)
{
	replace( s.begin(), s.end(), ' ', ',');
	string v;
	stringstream ss(s);
	vector<int> res;
	string a;
	while(getline(ss,a,delim))
	{
		res.pb(stoi(a));
	}
	return res;
}
vector<pii> g[1050];
ll dis[1050];
typedef pair<ll,pair<int,ll> > entry;
vector<entry> ee;
int getCost(int N)
{
	for(int i = 0 ; i < 1050 ; ++i) dis[i] = 1LL << 52;

	ll ret = 0;
	priority_queue<entry,vector<entry>,greater<entry > > pq;
	pq.push(entry(0,make_pair(0,0)));
	dis[0] = 0;
	int vis = 0;
	while(!pq.empty())
	{

		entry e = pq.top(); pq.pop();
		ll d = e.first, c = e.second.second, curr = e.second.first;
		if(d > dis[curr])
			continue;
		vis++;
		ret += 1LL*c;
		REP(i,g[curr])
		{
			int nxt = g[curr][i].first, cost = g[curr][i].second;
			if(dis[nxt] > cost + dis[curr])
			{
				dis[nxt] = cost + dis[curr];
				pq.push(make_pair(dis[nxt],make_pair(nxt,cost)));
			}
		}



	}
	if(vis != N)
		return -1;
	vector<entry> span;
	REP(i,ee)
	{
		int s = ee[i].second.first, t = ee[i].second.second; int c = ee[i].first;
		if(1LL*dis[s] + 1LL*c == dis[t] || 1LL*dis[t] + 1LL*c == dis[s])
			span.pb(ee[i]);

	}
	sort(all(span));
	ll res = 0;
	UnionFind dsu(N);
	REP(i,span)
	{
		int s = span[i].second.first, t = span[i].second.second; ll c = span[i].first;

		if(dsu.isSameSet(s,t))
			continue;
		dsu.unionSet(s,t); res += 1LL*c;
	}
	return res;

}
ll TimeTravellingSalesman::determineCost(int N,vector<string> roads)
{
	string str = ""; REP(i,roads) str += roads[i];
	  cout << str << "\n";
	vector<int> edges = token(str,',');
	for(int i = 0 ; i < sz(edges) ; i += 3)
	{
	   int u = edges[i],v = edges[i + 1],c = edges[i + 2];
	   //cout << u << " " << v << " " << c << "\n";
	   g[u].pb(pii(v,c));
	   g[v].pb(pii(u,c));
	   ee.pb(make_pair(c,make_pair(u,v)));
	}
	return getCost(N);
}
