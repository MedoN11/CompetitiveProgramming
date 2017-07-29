#include <iostream>
#include <cstdio>
#include<complex>
#include<string>
#include<vector>
#include<numeric>
#include<list>
#include<iomanip>
#include<cmath>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
using namespace std;
typedef long long ll;
int n,m,k;
int grid[30001][1001];
ll sqr(ll x) { return x * x;}

// adhoc
int main()
{
	scanf("%d %d",&m,&n);

	scanf("%d",&k);
	while(k--)
	{
		int x,y,r,b;
		scanf("%d %d %d %d",&y,&x,&r,&b);
		y--;
		x = m - x;
		int L = max(0,x - r), R = min(m - 1,x + r);
		for(int j = L ; j <= R ; ++j)
		{
			int tak = abs(j - x);
			int diff = (ll)(sqrt(1LL*sqr(r) - 1LL*sqr(tak)));

			grid[j][max(0,y - diff)] += 1LL*b;
			grid[j][min(n,y + diff + 1)] -= 1LL*b;
		}

		//cerr << "----------" << "\n";

	}

	int best = 0;
	int cnt = 0;
	for(int i = 0 ; i < m ; ++i)
	{
		for(int j = 0 ; j < n ; ++j)
		{
		    if(j > 0) grid[i][j] += grid[i][j - 1];

		}
	}
	for(int i = 0 ; i < m ; ++i)
	{
		for(int j = 0 ; j < n ;++j)
		{
			if(grid[i][j] > best)
			{
				best = grid[i][j],cnt = 1;
			}
			else
			{
				if(grid[i][j] == best) ++cnt;
			}
		}
	}
	printf("%d\n%d\n",best,cnt);

}
