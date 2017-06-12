#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
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
#include<map>
#include<complex>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef vector<int> vi;

struct GreenWarfare
{
	int minimumEnergyCost(vi canonX,vi canonY,vi baseX,vi baseY,vi plantX,vi plantY,int r);
};


#define maxn 5000
#define maxe 10000
#define LL long long
using namespace std;

// Dinic's code is from Standford ACM notebook
struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
  LL rcap() { return cap - flow; }
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<vector<Edge *> > Lf;
  vector<int> layer;
  vector<int> Q;

  Dinic(int N) : N(N), G(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    if (from == to) return;
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  LL BlockingFlow(int s, int t) {
    layer.clear(); layer.resize(N, -1);
    layer[s] = 0;
    Lf.clear(); Lf.resize(N);

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i]; if (e.rcap() <= 0) continue;
        if (layer[e.to] == -1) {
          layer[e.to] = layer[e.from] + 1;
          Q[tail++] = e.to;
        }
        if (layer[e.to] > layer[e.from]) {
          Lf[e.from].push_back(&e);
        }
      }
    }
    if (layer[t] == -1) return 0;

    LL totflow = 0;
    vector<Edge *> P;
    while (!Lf[s].empty()) {
      int curr = P.empty() ? s : P.back()->to;
      if (curr == t) { // Augment
        LL amt = P.front()->rcap();
        for (int i = 0; i < P.size(); ++i) {
          amt = min(amt, P[i]->rcap());
        }
        totflow += amt;
        for (int i = P.size() - 1; i >= 0; --i) {
          P[i]->flow += amt;
          G[P[i]->to][P[i]->index].flow -= amt;
          if (P[i]->rcap() <= 0) {
            Lf[P[i]->from].pop_back();
            P.resize(i);
          }
        }
      } else if (Lf[curr].empty()) { // Retreat
        P.pop_back();
        for (int i = 0; i < N; ++i)
          for (int j = 0; j < Lf[i].size(); ++j)
            if (Lf[i][j]->to == curr)
              Lf[i].erase(Lf[i].begin() + j);
      } else { // Advance
        P.push_back(Lf[curr].back());
      }
    }
    return totflow;
  }

  LL GetMaxFlow(int s, int t) {
    LL totflow = 0;
    while (LL flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

ll sqr(int x) { return 1LL*x * x; }
ll dis(int x1,int y1,int x2,int y2)
{
	return 1LL*sqr(x1 - x2) + sqr(y1 - y2);
}

int ind = 0;
const ll inf = 1LL << 30;
int bomberID[4999],baseID[4999],plantID[4999];
int GreenWarfare::minimumEnergyCost(vi bomberX,vi bomberY,vi baseX,vi baseY,vi plantX,vi plantY,int r)
{

	Dinic flowGraph(500);
	int src = ind++,sink = ind++;

	for(int i = 0 ; i < sz(baseX) ; ++i)
	{
		baseID[i] = ind++;
	}
	for(int i = 0 ; i < sz(plantX) ; ++i)
	{
		plantID[i] = ind++;
	}
	// construct first level

	for(int i = 0 ; i < sz(plantX) ; ++i)
	{
		ll mn = inf;
		for(int j = 0 ; j < sz(bomberX) ; ++j)
		{
			mn = min(mn,dis(plantX[i],plantY[i],bomberX[j],bomberY[j]));
		}
		//cerr << src << " " << plantID[i] << " " << mn << "\n";

		flowGraph.AddEdge(src,plantID[i],mn);
	}

	for(int i = 0 ; i < sz(baseX) ; ++i)
	{
		ll mn = inf;
		for(int j = 0 ; j < sz(bomberX) ; ++j)
		{
			mn = min(mn,dis(baseX[i],baseY[i],bomberX[j],bomberY[j]));
		}
		flowGraph.AddEdge(baseID[i],sink,mn);

	}
	for(int i = 0 ; i < sz(plantX) ; ++i)
	{

		for(int j = 0 ; j < sz(baseX) ; ++j)
		{
			int d  = dis(plantX[i],plantY[i],baseX[j],baseY[j]);
			if(d <= r * r)
				flowGraph.AddEdge(plantID[i],baseID[j], inf);
		}

	}


	return (int)flowGraph.GetMaxFlow(src,sink);
}


