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
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include <set>
#include <iostream>
#include <cstdio>
#include<map>
#define ll  long long
#define EPS (1e-8);
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define neg(x) memset(x,-1,sizeof(x));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define endl "\n"
using namespace std;
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
typedef pair<int,int> ii;
#define maxn 500
#define maxe 10000
#define LL long long
using namespace std;

int h,w,k;
int DP[40][40];


int query(int i1,int i2,int j1,int j2)
{
	int rem = DP[i2][j2];
	if(i1 > 0)
		rem -= DP[i1 - 1][j2];
	if(j1 > 0)
		rem -= DP[i2][j1 - 1];
	if(i1 > 0 && j1 > 0)
		rem += DP[i1 -1][j1 - 1];
	return rem;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{

		scanf("%d %d %d",&h,&w,&k);
		if(!k)
		{
			puts("0");
			continue;
		}
		string str;
		for(int i = 0 ; i < h ; ++i)
		{
			cin >> str;
			for(int j = 0 ; j < w ; ++j)
			{

				if(str[j] == 'C')
					DP[i][j] = 1;
				else DP[i][j] = 0;
				if(i > 0)
					DP[i][j] += DP[i - 1][j];
				if(j > 0)
					DP[i][j] += DP[i][j - 1];
				if(i > 0 && j > 0)
					DP[i][j] -= DP[i - 1][j - 1];
			}
		}
		int sol = 1 << 30;
		for(int i1 = 0 ; i1 < h ; ++i1)
		{
			for(int i2 = i1 ; i2 < h ; ++i2)
			{
				for(int j1 = 0; j1 < w ; ++j1)
				{
					for(int j2 = j1; j2 < w ; j2++)
					{
						if(query(i1,i2,j1,j2) == k)
							sol = min(sol,(i2 - i1 + 1) * (j2 -j1 + 1));
					}
				}
			}
		}
		if(sol == 1 << 30)
			sol = -1;
		printf("%d\n",sol);

	}

}

