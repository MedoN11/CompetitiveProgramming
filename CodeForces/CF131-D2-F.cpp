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
typedef pair<int,int> ii;
int DP[501][501];
char grid[501][501];
int n,m,k;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

// Bruteforce + DP Matrix Sum + Binary/2Pointers
// A rectangle is defined by (x1,y1) and (x2,y2)
// Let's fix x1 and x2
// we can then solve for y1 and y2 using binary search or 2 poitners.
inline bool ok(int i,int j)
{
	return i >= 0 && i < n && j >= 0  && j < m;
}
inline int query(int x1,int x2,int y1,int y2)
{
	if(x1 > x2)
		return 0;
	if(y2 < y1)
		return 0;
	int sum = DP[x2][y2];
	if(y1 > 0) sum -= DP[x2][y1 - 1];
	if(x1 > 0) sum -= DP[x1 - 1][y2];
	if(x1 > 0 && y1 > 0) sum += DP[x1 - 1][y1 - 1];

	return sum;
}



inline bool can(int up,int down,int colL,int colR)
{

	return query(up + 1,down - 1,colL + 1,colR - 1) >= k;
}


int main()
{

	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0 ; i  < n ; ++i)
	{
		scanf("%s",grid[i]);
	}

	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < m ;++j)
		{
			int stars = 0;
			if(grid[i][j] == '1')
			{
				for(int k = 0 ; k < 4 ; ++k)
				{
					int xc = dx[k] + i;
					int yc = dy[k] + j;
					if(ok(xc,yc) && grid[xc][yc] == '1')
					{
						++stars;
					}

				}
			}
			if(stars == 4)
			{
				DP[i][j] = 1;
			}
			if(i > 0)
				DP[i][j] += DP[i - 1][j];
			if(j > 0)
				DP[i][j] += DP[i][j - 1];
			if(i > 0 && j > 0)
				DP[i][j] -= DP[i - 1][j - 1];
		}
	}

	ll ans = 0;
	for(int i = 0 ; i < m ; ++i)
	{
		for(int j = i + 1; j < m ; ++j)
		{

			int lo = 0, hi = 0;

			while(lo < n && hi < n)
			{
				if(can(lo,hi,i,j))
				{
					ans += 1LL*n - hi;
					++lo;
				}
				else ++hi;
			}


		}
	}
	cout << ans;
}
