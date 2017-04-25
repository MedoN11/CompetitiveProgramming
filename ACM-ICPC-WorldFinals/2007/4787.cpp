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

bool grid[2105][2105];
int n,m,w;
bool dp[2105][2105],vis[2105][2105];
int revx[4100],revy[4100];
int leftx[4101],rightx[4101],righty[4101];
int lx,ly,rx,ry;
int sizeX,sizeY;
bool solve(int i,int j)
{
	if(i > sizeX || j > sizeY || i < 0 || j < 0)
		return 0;

	if(grid[i][j])
		return dp[i][j] = 0;
	if(i == sizeX - 1 && j == sizeY - 1)
		return 1;
	if(vis[i][j])
		return dp[i][j];
	vis[i][j] = 1;
	return dp[i][j] = solve(i + 1,j) || solve(i,j + 1);

}
int main()
{

	int tc = 1;
	while(scanf("%d %d %d",&m,&n,&w) == 3 && n + m)
	{


		map<int,int> mpx,mpy;
		mpx[0] = 1; mpy[0] = 1;
		mpx[n] = 1; mpy[m] = 1;
		memset(grid,0,sizeof(grid));
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		int ly,ry;
		for(int  i = 0 ; i < w ; ++i)
		{
			scanf("%d %d %d %d",&lx,&ly,&rx,&ry);
			mpx[lx] = 1; mpy[ly] = 1;
			++lx; ++ ly; ++rx; ++ry;
			mpx[lx] = 1; mpx[rx] = 1; mpy[ly] = 1; mpy[ry] = 1;
			leftx[i] = lx; rightx[i] = rx; righty[i] = ry;

		}



		sizeX = 0, sizeY = 0;
		for(map<int,int>::iterator it = mpx.begin(); it != mpx.end() ; it++)
		{
			it->second = sizeX;
			revx[sizeX++] = it->first;

		}

		for(map<int,int>::iterator it = mpy.begin(); it != mpy.end() ; it++)
		{
			it->second = sizeY;
			revy[sizeY++] = it->first;

		}


		for(int i = 0 ; i < w ; ++i)
		{
			int l = mpx[leftx[i]]; int r = mpx[rightx[i]]; int y = mpy[righty[i]];
			for(int j = l ; j <= r ;++j)
				grid[j][y] = 1;
		}
		ll ret = 0;

		for(int i = 1 ; i < sizeX ; ++i)
		{
			for(int j = 1 ; j < sizeY ; ++j)
			{
				if(grid[i][j] || solve(i,j))
					continue;
				ret += 1LL*(revx[i] - revx[i - 1])*1LL*(1LL*revy[j] - revy[j - 1]);
			}
		}
		printf("Case %d: %lld\n",tc++,ret);
	}

	//cout << "Case " <<(tc++) <<": "; cout << ret << "\n";

}

