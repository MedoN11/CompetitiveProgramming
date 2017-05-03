#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<set>
#include<map>
#include<list>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<memory.h>
#include<iomanip>
#include<cmath>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#define ll long long
using namespace std;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
typedef pair<int,int> ii;
typedef pair<ii,int> point;
typedef pair<int, int> pii;
#define clr(x) memset(x,0,sizeof(x))
const int maxnodes = 200000;
const int inf = 1 << 30;
int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
	int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s, int t, int cap, int cost) {
	//Edge a = {t, 0, cap, cost, graph[t].size()};
	Edge a;
	a.to = t, a.f = 0, a.cap = cap, a.cost = cost,a.rev = graph[t].size();
	Edge b;
	b.to = s, b.f = 0,b.cap = 0,b.cost = -cost,b.rev = graph[s].size();
	graph[s].push_back(a);
	graph[t].push_back(b);
}

void bellmanFord(int s, int dist[]) {
	//fill(dist, dist + nodes, INT_MAX);
	for(int i = 0 ; i < maxnodes ; ++i)
		dist[i] = inf;
	dist[s] = 0;
	int qt = 0;
	q[qt++] = s;
	for (int qh = 0; (qh - qt) % nodes != 0; qh++) {
		int u = q[qh % nodes];
		inqueue[u] = false;
		for (int i = 0; i < (int) graph[u].size(); i++) {
			Edge &e = graph[u][i];
			if (e.cap <= e.f) continue;
			int v = e.to;
			int ndist = dist[u] + e.cost;
			if (dist[v] > ndist) {
				dist[v] = ndist;
				if (!inqueue[v]) {
					inqueue[v] = true;
					q[qt++ % nodes] = v;
				}
			}
		}
	}
}

pii minCostFlow(int s, int t, int maxf) {
	// bellmanFord can be safely commented if edges costs are non-negative
	bellmanFord(s, pot);
	int flow = 0;
	int flowCost = 0;
	while (flow < maxf) {
		priority_queue<ll, vector<ll>, greater<ll> > q;
		q.push(s);
		//fill(prio, prio + nodes, INT_MAX);
		for(int j = 0 ; j < maxnodes ; ++j)
			prio[j] = inf;
		prio[s] = 0;
		curflow[s] = inf;
		while (!q.empty()) {
			ll cur = q.top();
			int d = cur >> 32;
			int u = cur;
			q.pop();
			if (d != prio[u])
				continue;
			for (int i = 0; i < (int) graph[u].size(); i++) {
				Edge &e = graph[u][i];
				int v = e.to;
				if (e.cap <= e.f) continue;
				int nprio = prio[u] + e.cost + pot[u] - pot[v];
				if (prio[v] > nprio) {
					prio[v] = nprio;
					q.push(((ll) nprio << 32) + v);
					prevnode[v] = u;
					prevedge[v] = i;
					curflow[v] = min(curflow[u], e.cap - e.f);
				}
			}
		}
		if (prio[t] == inf)
			break;
		for (int i = 0; i < nodes; i++)
			pot[i] += prio[i];
		int df = min(curflow[t], maxf - flow);
		flow += df;
		for (int v = t; v != s; v = prevnode[v]) {
			Edge &e = graph[prevnode[v]][prevedge[v]];
			e.f += df;
			graph[v][e.rev].f -= df;
			flowCost += df * e.cost;
		}
	}
	return make_pair(flow, flowCost);
}

int n;
int main()
{
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0 ; i < maxnodes ; ++i)
			graph[i].clear();
		vector<int> curr,exp;
		int x;
		for(int i = 0 ; i < n ; ++i)
		{
			scanf("%d",&x);
			curr.push_back(x);
		}
		for(int i = 0 ; i < n ; ++i)
		{
			scanf("%d",&x);
			exp.push_back(x);
		}
		vector<ii> zeros,ones;
		REP(ind,curr)
		{
			int f = curr[ind], t = exp[ind];
			for(int i = 0 ; i < 12 ; ++i)
			{
				int bitf = (1 << i) & f;
				int bitt = (1 << i) & t;
				if(bitf)
					bitf = 1;
				if(bitt)
					bitt = 1;
				if(bitf == bitt)
					continue;
				if(!bitf)
					zeros.push_back(ii(ind,i));
				else ones.push_back(ii(ind,i));
			}
		}
		if(sz(zeros) != sz(ones))
		{
			puts("Impossible");
			continue;
		}
		int l = sz(zeros), r =  sz(ones);

		int src = l * r + 1, sink = l * r + 2;
		REP(j,ones) addEdge(l + j,sink,1,0);
		REP(i,zeros)
		{
			addEdge(src,i,1,0);
			REP(j,ones)
			{
				int dis = abs(zeros[i].first - ones[j].first) + abs(zeros[i].second - ones[j].second);
				addEdge(i,l + j,1,dis);
			}
		}
		pii res = minCostFlow(src,sink,1000000);
		cout << res.second << "\n";
	}
}
