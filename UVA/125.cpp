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
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<complex>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<double,double> pii;
using namespace std;

// floyd
// make sure you check that no intermediate node lies in a cycle

ll floyd[1000][1000];
int cyc[1000];
int n ;
void work()
{
	for(int k = 0 ; k < n ; ++k)
	{
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < n ; ++j)
			{
				floyd[i][j] += 1LL*floyd[i][k] * floyd[k][j];

			}
		}
	}

	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ; ++j)
		{
			if(floyd[i][j] && floyd[j][i])
			{
				cyc[i] = cyc[j] = 1;
			}
		}
	}
	for(int k = 0 ; k < n ; ++k)
	{
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < n ; ++j)
			{
				if(floyd[i][k] && floyd[k][j] && cyc[k])
					floyd[i][j] = -1;

			}
		}
	}

}

int main()
{


	int tc = 0;
	int m;
	while(scanf("%d",&m) != EOF)
	{
		memset(floyd,0,sizeof(floyd));
		memset(cyc,0,sizeof(cyc));
		int u,v;
		n = 0;
		// clear
		while(m--)
		{
			scanf("%d %d",&u,&v);
			n = max(n,max(u,v) + 1);
			floyd[u][v]++;

		}
		printf("matrix for city %d\n",tc++);
		work();
		for(int i = 0 ; i < n ;++i)
		{

			for(int j = 0 ; j < n ; ++j)
			{

				if((floyd[i][j]) && (cyc[i] || cyc[j])) floyd[i][j] = -1;


			}

		}
		for(int i = 0 ; i < n ;++i)
		{

			printf("%lld",floyd[i][0]);
			for(int j = 1 ; j < n ; ++j)
			{
				printf(" %lld",floyd[i][j]);
			}
			puts("");
		}
	}

}

