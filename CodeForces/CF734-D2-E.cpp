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
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
const int maxn = 2000*1005;
vector<int> tree[maxn];
vector<int> comp[maxn];
int dad[maxn];

// Tree compression + Diameter
// Compress the tree based on colors by DSU
// the answer is (diameter + 1) / 2
// proof is in the CF Editorial
pair<int,int> bfs(int u)
																		{

	queue<pair<int,pair<int,int> > > Q; Q.push(make_pair(u,make_pair(0,-1)));
	int max_distance = 0; int t = u;
	while(!Q.empty())
	{
		pair<int,pair<int,int> > out = Q.front(); Q.pop();
		int idx = out.first; int dis = out.second.first; int p = out.second.second;

		if(max_distance <= dis){
			t = idx;
			max_distance  = dis;
		}
		REP(k,tree[idx])
		{
			int next = tree[idx][k]; if(next==p)continue;
			if(p==next) continue;
			Q.push(make_pair(next,make_pair(dis+1,idx)));
		}


	}
	return make_pair(t,max_distance);
																		}

int getDiameter(int idx)
{

	int path = 0;


	pair<int,int> u = bfs(idx);
	pair<int,int> v = bfs(u.first);
	path = max(v.second,path);

	return path;
}

void merge(int x,int y)
{
	if(dad[x] == dad[y])
		return;
	int u = dad[x], v = dad[y];
	if(sz(comp[u]) < sz(comp[v]))
		swap(u,v);
	REP(i,comp[v]) comp[u].push_back(comp[v][i]),dad[comp[v][i]] = u;
}
int n;
int col[maxn];
vector<pair<int,int> > edges;
int main()
{
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i) comp[i].push_back(i),dad[i] = i;
	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%d",&col[i]);
	}
	for(int i = 0 ; i < (n - 1) ; ++i)
	{
		int x,y; scanf("%d %d",&x,&y);
		--x; --y;
		if(col[x] == col[y])
		{
			//cerr << x << " " << y << "\n";
			merge(x,y);
		}
		edges.push_back(make_pair(x,y));
	}
	REP(i,edges)
	{
		pair<int,int> e = edges[i];
		int u = dad[e.first], v = dad[e.second];
		if(u != v)
		{
			tree[u].push_back(v), tree[v].push_back(u);
		}
	}
	int d = getDiameter(dad[0]);
	printf("%d\n",(d + 1) / 2);
}
