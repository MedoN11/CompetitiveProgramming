#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
using namespace std;
#define ll long long
typedef long double ld;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define clr(x) memset(x,0,sizeof(x));
typedef vector<int> vi;
#include <iostream>
#include <cmath>
#include <complex>
#include <cassert>
using namespace std;
int cut[16];
int n;
bool DP[1 << 15][101];
bool vis[1 << 15][101];
bool solve(int x,int y,int msk)
{

	if(x == 0 && y == 0)
		return msk == 0;
	if(msk == 0)
	{
		return x == 0 && y == 0;
	}
	if(__builtin_popcount(msk) == 1)
	{

		int ind = -1;
		for(int i = 0 ; i < n && ind == -1 ; ++i)
			if((msk & (1 << i)) != 0)
				ind = i;
		if(cut[ind] != x * y)
			return DP[msk][x] = false;
		return DP[msk][x] = true;
	}
	if(vis[msk][x])
		return DP[msk][x];
	vis[msk][x] = true;
	bool ret = false;
	for(int subMsk = msk ; subMsk > 0 && !ret; subMsk = (subMsk - 1) & msk)
	{

		int sumOther = 0;
		int sumSub = 0;
		int otherMsk = msk & ~(subMsk);
		for(int i = 0 ; i < n ; ++i)
		{
			if((msk & (1 << i)) > 0)
			{
				if((subMsk & (1 << i)) == 0)
				{
					sumOther += cut[i];
				}
				else sumSub += cut[i];
			}
		}


		if(msk == otherMsk || msk == subMsk)
			continue;
		for(int l = 0 ; l <= x && !ret ; ++l)
		{
			if(l * y == sumSub && sumOther == (x - l) * y)
				ret |= solve(l,y,subMsk) && solve(x - l,y,otherMsk);
		}
		for(int w = 0 ; w <= y && !ret ; ++w)
		{

			if(x * w == sumSub && x * (y - w) == sumOther)
				ret |= solve(x,w,subMsk) & solve(x,y - w,otherMsk);
		}
	}
	return DP[msk][x] = ret;

}
int main()
{

	int tc = 1;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		int x,y; scanf("%d %d",&x,&y);
		int area = x * y;
		int sum = 0;
		for(int i = 0 ; i < n ; ++i)
		{
			scanf("%d",&cut[i]); sum += cut[i];
		}
		printf("Case %d: ",tc++);
		memset(vis,0,sizeof(vis));
		if(sum == area && solve(x,y,(1 << n) - 1))
			printf("Yes");
		else printf("No");
		printf("\n");
	}

}

