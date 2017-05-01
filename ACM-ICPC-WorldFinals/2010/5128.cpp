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

int n,m;
pair<int,int> v[3];
bool seen[8][8];
int d[3];
int cnt = 0;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

typedef vector<int> vi;
class UnionFind {                                              // OOP style
private:
	vi p, rank, setSize;                       // remember: vi is vector<int>
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
bool valid(int i,int j)
{
	return i >= 0 && j >= 0 && i < n && j < m;
}
bool dad[8][8];
bool ok()
{

	queue<int> q;
	memset(dad,0,sizeof(dad));

	int src = -1;
	for(int i = 0 ; i < n && src != -1; ++i)
	{
		for(int j = 0 ; j < m && src != -1 ; ++j)
		{
			if(!seen[i][j])
				src = i * m + j;
		}
	}

	if(src == -1)
		return 1;
	q.push(src);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		int i = x / m, j = x % m;
		if(dad[i][j])
			continue;
		dad[i][j] = 1;
		for(int k = 0 ; k < 4 ; ++k)
		{
			int xc = i + dx[k], yc = j + dy[k];
			if(valid(xc,yc) && !dad[xc][yc] && !seen[xc][yc])
				q.push(xc * m + yc);
		}

	}
	for(int i = 0 ; i < n; ++i)
	{
		for(int j = 0 ; j < m ; ++j)
		{
			if(!seen[i][j] && !dad[i][j])
				return 0;
		}
	}

	return 1;
}
void backtrack(int i,int j,int st,int vis)
{


	if(i == 0 && j == 1)
	{
		if(vis == n * m && st == 3)
		{
			++cnt;
			return;
		}
	}


	if(vis == n * m)
		return;

	seen[i][j] = 1;
	if(!ok())
	{
		seen[i][j] = 0;
		return;
	}

	// prune
	if(st < 3 && d[st] == vis && i == v[st].first && j == v[st].second)
		st++;
	if(st < 3)
	{

		int dis = abs(v[st].first - i) + abs(v[st].second - j);
		if(dis + vis > d[st])
		{

			seen[i][j] = 0;
			return;
		}
	}

	int must = 0;
	int ind = 0;
	for(int k = 0 ; k < 4 ; ++k)
	{
		int xc = dx[k] + i, yc = dy[k] + j;
		if( (xc == 0 && yc == 1) || !valid(xc,yc) || seen[xc][yc])
			continue;
		int nbs = 0;
		for(int z = 0 ; z < 4 ; ++z)
		{

			int xz = dx[z] + xc, yz = yc + dy[z];
			if(valid(xz,yz) && !seen[xz][yz])
			{
				++nbs;
			}
		}
		if(nbs == 0)
		{
			seen[i][j] = 0;
			return;
		}
		if(nbs == 1)
		{
			++must;
			ind = xc * m + yc;
		}
	}
	if(must > 1)
	{
		seen[i][j] = 0;
		return;
	}
	if(must == 1)
	{
		backtrack(ind / m,ind % m,st,vis + 1);
		seen[i][j] = 0;
		return;
	}

	for(int k = 0 ; k < 4 ; ++k)
	{
		int xc = dx[k] + i, yc = dy[k] + j;
		if(valid(xc,yc) && !seen[xc][yc])
		{
			backtrack(xc,yc,st,vis + 1);
		}
	}
	seen[i][j] = 0;
}

int main()
{
	int tc = 1;
	while(scanf("%d %d",&n,&m))
	{
		if(!(n + m))
			break;
		cnt = 0;
		memset(seen,0,sizeof(seen));
		scanf("%d %d %d %d %d %d",&v[0].first,&v[0].second,&v[1].first,&v[1].second,&v[2].first,&v[2].second);
		int tot = n * m;
		d[0] = tot / 4;
		d[1] = tot / 2;
		d[2] = 3 * tot / 4;
		backtrack(0,0,0,1);
		printf("Case %d: %d\n",tc++,cnt);

	}
}
