#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<numeric>
#include<utility>
#include<memory.h>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>

#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
using namespace std;
#define ll long long
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}


typedef pair<ll, ll> pii;

const int maxnodes = 200000;

int nodes = maxnodes;
ll prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
  ll to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s, int t, int cap, int cost) {
  Edge a = {t, 0, cap, cost, graph[t].size()};
  Edge b = {s, 0, 0, -cost, graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}

void bellmanFord(int s, ll dist[]) {
  fill(dist, dist + nodes, LONG_MAX);
  dist[s] = 0;
  ll qt = 0;
  q[qt++] = s;
  for (int qh = 0; (qh - qt) % nodes != 0; qh++) {
    int u = q[qh % nodes];
    inqueue[u] = false;
    for (int i = 0; i < (int) graph[u].size(); i++) {
      Edge &e = graph[u][i];
      if (e.cap <= e.f) continue;
      int v = e.to;
      ll ndist = dist[u] + e.cost;
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
  ll flow = 0;
  ll flowCost = 0;
  while (flow < maxf) {
    priority_queue<ll, vector<ll>, greater<ll> > q;
    q.push(s);
    fill(prio, prio + nodes, LONG_MAX);
    prio[s] = 0;
    curflow[s] = LONG_MAX;
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
        ll nprio = prio[u] + e.cost + pot[u] - pot[v];
        if (prio[v] > nprio) {
          prio[v] = nprio;
          q.push(((ll) nprio << 32) + v);
          prevnode[v] = u;
          prevedge[v] = i;
          curflow[v] = min(curflow[u], e.cap - e.f);
        }
      }
    }
    if (prio[t] == LONG_MAX)
      break;
    for (int i = 0; i < nodes; i++)
      pot[i] += prio[i];
    ll df = min(curflow[t], maxf - flow);
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


int n,k;
int a[2201],b[2201];
int main()
{
	scanf("%d %d",&n,&k);
	int src = 2 * n, sink = 2 * n + 1;
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&a[i]),addEdge(src,i,1,a[i]),addEdge(i, i + n,1 << 25,0);
	for(int j = 0 ; j < n ; ++j)
	{
		scanf("%d",&b[j]),addEdge(n + j,sink,1,b[j]);
		if(j + 1 < n) addEdge(n + j , n + j + 1,1 << 25,0);
	}
//	for(int j = 0 ; j < n ; ++j)
//	{
//		for(int i = 0 ; i <= j ; ++i)
//		{
//
//			addEdge(i, n + j,1,a[i] + b[j]);
//		}
//	}
	printf("%lld\n",minCostFlow(src,sink,k).second);

}
