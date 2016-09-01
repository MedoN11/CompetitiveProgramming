#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define dbg(a) cerr << #a << ": " << (a) << endl
#define ll long long
#define endl "\n"
#define getBit(num,idx) ((num >> idx) & 1)
#define setBit(num,idx) num|((1 << idx))
using namespace std;
typedef pair<int,pair<int,int> > PII;
using namespace std;

vector<vector<int> > G(10000+5);
int col[1000+5];

int N,E;
int left1[10000+5]; // matched to on right
int right1[10000+5]; // matched to on left
bool vis[10000+5];

// assume graph is bipartite colored
// 0 based
bool match(int i)
{
	// i is always a left node


	if(vis[i]) return false;
	vis[i] = 1;
	REP(k,G[i])
	{
		int next = G[i][k];


		if(left1[next] == -1 || (match(left1[next])))
		{
			left1[next] = i; right1[i] = next;
			return true;
		}

	}
	return false;

}
int BiaMaxMatching()
{
	memset(left1,-1,sizeof(left1));
	memset(right1,-1,sizeof(right1));

	int matches = 0;
	// iterate on left and try to assigned each node
	for(int i = 0 ; i < N ; i++)
	{
		if(col[i]) continue;
		memset(vis,0,sizeof(vis));
		if(match(i)) ++matches;
	}

	return matches;
}


void color(int idx)
{

	queue<int> Q;

	Q.push(idx);

	col[idx] = 0;

	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();

		REP(k,G[u])
		{
			int next = G[u][k];


			if(col[next] == -1)
			{
				col[next] = 1 - col[u];

				Q.push(next);
			}

			else if(col[u] == col[next]) return;
		}
	}

	return;

}


int main()
{
	// construct graph and color.
    // example of usage

	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i = 0 ; i < N ; i++) G[i].clear();
		scanf("%d %d",&N,&E);
		int u,v;
		memset(col,-1,sizeof(col));
		for(int i = 0 ; i < E ; i++)
		{
			scanf("%d %d",&u,&v);
			--u; --v;
			G[u].push_back(v);
			G[v].push_back(u);

		}
		color(0);
		int mat = BiaMaxMatching();
	}
}
