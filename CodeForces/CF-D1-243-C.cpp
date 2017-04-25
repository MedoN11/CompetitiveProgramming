#include<set>
#include<map>
#include<list>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<iomanip>
#include<cmath>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include<stack>
#define ll long long
using namespace std;
int n;
ll mx = 10e10 + 1;
ll x = 10e10 + 1;
ll y = 10e10 + 1;
map<ll,int> mpx,mpy;
vector<pair<ll,ll> > pts;
int sizeX = 0, sizeY = 0;
ll revx[8101],revy[8101];
bool seen[8101][8101];
bool grid[8101][8101];
pair<int,int> nxt;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

ll res = 0;
bool valid(int i,int j)
{
	return i >= 0 && j >= 0 && i < sizeX && j < sizeY;
}
void dfs(int i,int j)
{
	//cerr << i << " " << j << "\n";
	if(!valid(i,j))
		return;
	if(seen[i][j])
		return;
	if(grid[i][j])
		return;
	seen[i][j] = 1;
	for(int k = 0 ; k < 4 ; ++k)
	{
		int xc = i + dx[k], yc = j + dy[k];
		if(valid(xc,yc) && !grid[xc][yc] && !seen[xc][yc])
			dfs(xc,yc);
	}
}

void print()
{
	for(int i = 0 ; i < sizeX ; ++i)
	{
		for(int j = 0 ; j < sizeY ; ++j)
		{
			cout << grid[i][j];
		}
		cout << "\n";
	}
}
int main()
{

	scanf("%d",&n);
	x /= 2LL ; y /= 2LL;
	char c;
	ll d;
	pts.push_back(make_pair(x,y));
	mpx[0] = 0, mpy[0] = 0;
	mpx[1] = 1, mpy[1] = 1;
	mpx[mx] = 1, mpy[mx] = 1;

	for(int i = 0 ; i < n ; ++i)
	{
		cin >> c >> d;
		if(c == 'R')
			y += d;
		if(c == 'L')
			y -= d;
		if(c == 'D')
			x += d;
		if(c == 'U')
			x -= d;
		pts.push_back(make_pair(x,y));

	}
	n++;
	for(int i = 0 ; i < n - 1 ; ++i)
	{
		ll lx = pts[i].first, ly = pts[i].second, rx = pts[i + 1].first, ry = pts[i + 1].second;
		if(lx > rx)
			swap(lx,rx);
		if(ly > ry)
			swap(ly,ry);
		mpx[lx] = 1; mpx[lx - 1] = 1; mpx[rx] = 1; mpx[rx + 1] = 1;
		mpy[ly] = 1; mpy[ly - 1] = 1; mpy[ry] = 1; mpy[ry + 1] = 1;
	}
	for(map<ll,int>::iterator it = mpx.begin(); it != mpx.end() ;it++)
	{
		it->second = sizeX;
		revx[sizeX++] = it->first;
	}
	for(map<ll,int>::iterator it = mpy.begin(); it != mpy.end() ;it++)
	{
		it->second = sizeY;
		revy[sizeY++] = it->first;
	}

	for(int i = 0 ; i < n - 1 ; ++i)
	{

		ll lx = pts[i].first, ly = pts[i].second, rx = pts[i + 1].first, ry = pts[i + 1].second;
		if(lx > rx)
			swap(lx,rx);
		if(ly > ry)
			swap(ly,ry);
		if(ly == ry)
		{
			lx = mpx[lx]; rx = mpx[rx]; ry = mpy[ry];

			for(int k = lx ; k <= rx ; ++k)
			{

				grid[k][ry] = 1;
			}
		}
		else
		{
			ly = mpy[ly], ry = mpy[ry], rx = mpx[rx];
			for(int k = ly; k <= ry ; ++k)
			{

				grid[rx][k] = 1;
			}
		}

	}
	//print();

	for(int i = 0 ; i < sizeY ; ++i)
	{
		dfs(0,i);
		dfs(sizeX - 1,i);
	}
	for(int i = 0 ; i < sizeX ; ++i)
	{
		dfs(i,0);
		dfs(i,sizeY - 1);
	}
	dfs(0,0);

	for(int i = 1 ; i < sizeX ; ++i)
	{
		for(int j = 1 ; j < sizeY ; ++j)
		{

			if(!seen[i][j] || grid[i][j])
			{
				res += 1LL*(revx[i] - revx[i - 1]) * (revy[j] - revy[j - 1]);

			}
		}
	}
	cout << res;
	return 0;


}
