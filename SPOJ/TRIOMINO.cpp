#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <unordered_map>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define write(file) freopen (file,"w",stdout)
#define ll  long long
using namespace std;
typedef pair<int,int> ii;
#define MAXN 2000
int G[1024][2][2][2][2];

int solve(int n,int LL,int LU,int RL,int RU)
{
	if(n < 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 0;
	}
	// special case
	if(n == 2)
	{
		int sum = LL + LU + RL + RU;
		if(sum == 1 || sum == 0)
			return 1;
		return 0;
	}
	int &ret = G[n][LL][LU][RL][RU];
	if(ret != -1)
		return ret;
	set<int> grundy;

	if(!LL && !LU)
	{
		grundy.insert(solve(n - 1,1,0,RL,RU));
		grundy.insert(solve(n - 1,0,1,RL,RU));
	}
	if(!RL && !RU)
	{
		grundy.insert(solve(n - 1,LL,LU,1,0));
		grundy.insert(solve(n - 1,LL,LU,0,1));
	}


	grundy.insert(solve(n - 2,1,0,RL,RU));
	grundy.insert(solve(n - 2,0,1,RL,RU));

	grundy.insert(solve(n - 2,LL,LU,1,0));
	grundy.insert(solve(n - 2,LL,LU,0,1));

	grundy.insert(solve(n - 2,0,0,RL,RU));
	grundy.insert(solve(n - 2,LL,LU,0,0));


	// main case
	for(int i = 3 ; i <= n - 2 ; ++i)
	{
		int x = solve(i - 1,LL,LU,0,0);
		int y = solve(n - i,0,1,RL,RU);
		int z = solve(n - i,1,0,RL,RU);
		grundy.insert(x ^ y); grundy.insert(x ^ z);

		x = solve(n - i,0,0,RL,RU);
		y = solve(i - 1,LL,LU,1,0);
		z = solve(i - 1,LL,LU,0,1);
		grundy.insert(x ^ y); grundy.insert(x ^ z);
	}
	ret = 0;
	while(grundy.find(ret) != grundy.end())
		++ret;
	return  ret;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	int n;
	memset(G,-1,sizeof(G));
	while(tc--)
	{
		//memset(G,-1,sizeof(G));
		scanf("%d",&n);
		if(solve(n,0,0,0,0))
			puts("X");
		else puts("Y");
	}
}

