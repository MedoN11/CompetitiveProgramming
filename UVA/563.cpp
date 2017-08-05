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
#include<complex>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
using namespace std;
#define ll  long long
typedef pair<int,int> pii;
#define pb push_back


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
const int MAXN = 40000+70;
const int INF = 1000000000;

struct Dinic{

	Dinic() {}
        struct edge {
                int a, b, cap, flow;
        };

        int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
        edge e[1000000];
        int edge_size;
        vector<int> g[MAXN];

        /**
        1. init()
        2. 'n' should be greater then the number of node
        3. 's' is source 't' is sink
        4. call dinic to get flow
        */

        void init( int src, int sink , int totalNode ) {
                for(int i=0; i<MAXN; i++) g[i].clear();
                memset(q,0,sizeof(q));
                memset(ptr,0,sizeof(ptr));
                s = src , t = sink , n = totalNode + 3;
                edge_size = 0;
        }

        void add_edge (int a, int b, int cap) {
                edge e1 = { a, b, cap, 0 };
                edge e2 = { b, a, 0, 0 };
                g[a].push_back (edge_size);
                e[edge_size++] = e1;
                g[b].push_back (edge_size);
                e[edge_size++] = e2;
        }

        bool bfs() {
                int qh=0, qt=0;
                q[qt++] = s;
                memset (d, -1, n * sizeof d[0]);
                d[s] = 0;
                while (qh < qt && d[t] == -1) {
                        int v = q[qh++];
                        int gvSZ = g[v].size();
                        for (size_t i=0; i<gvSZ; ++i) {
                                int id = g[v][i],
                                to = e[id].b;
                                if (d[to] == -1 && e[id].flow < e[id].cap) {
                                        q[qt++] = to;
                                        d[to] = d[v] + 1;
                                }
                        }
                }
                return d[t] != -1;
        }

        int dfs (int v, int flow) {
                if (!flow)  return 0;
                if (v == t)  return flow;
                int gvSZ = g[v].size();
                for (; ptr[v]<gvSZ; ++ptr[v]) {
                        int id = g[v][ptr[v]],
                        to = e[id].b;
                        if (d[to] != d[v] + 1)  continue;
                        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
                        if ( pushed ) {
                                e[id].flow += pushed;
                                e[id^1].flow -= pushed;
                                return pushed;
                        }
                }
                return 0;
        }

        int dinic() {
                int flow = 0;
                for (;;) {
                        if (!bfs())  break;
                        memset (ptr, 0, n * sizeof ptr[0]);
                        while (int pushed = dfs (s, INF)) {
                                flow += pushed;
                        }
                }
                return flow;
        }
};
int n,m,b;

bool mark[52][52];
int in[2501],out[2501];
int ind[3000];

bool valid(int i,int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}
int main()
{
	int tc;
	scanf("%d",&tc);


	while(tc--)
	{
		scanf("%d %d %d",&n,&m,&b);

memset(mark,0,sizeof(mark));
		for(int i = 0 ; i < b ; ++i)
		{
			int x,y; scanf("%d %d",&x,&y);
			--x; --y;
			mark[x][y] = 1;
		}
		int id = 0;
		int s = id++, t = id++;
		Dinic d;

		d.init(s,t,6000);
		for(int i = 0 ; i < n ;  ++i)
		{
			for(int j = 0 ; j < m ; ++j)
			{
				in[i * n + j] = id++;
				out[i * n + j] = id++;
				d.add_edge(in[i * n + j],out[i * n + j],1);

			}
		}

		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < m ; ++j)
			{
				if(mark[i][j])
				{
					d.add_edge(s,in[i * n + j],1);
				}
				for(int k = 0 ; k < 4 ; ++k)
				{
					int xc = i + dx[k], yc = j + dy[k];
					if(valid(xc,yc))
					{
						int from = i * n + j, to = xc * n + yc;
						d.add_edge(out[from],in[to],1);
					}
					else
					{
						cerr << "here" << "\n";
						d.add_edge(out[i * n + j],t,1);
					}
				}
			}
		}

		int flow = d.dinic();
		if(flow < b)
			puts("not possible");
		else puts("possible");
	}

}
