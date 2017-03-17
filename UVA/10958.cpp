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
#include<cstdlib>
#include <set>
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
using namespace std;
ll n,m,p;


ll medo(ll x)
{
	ll tot = 1;
	for(int i = 2 ; i * i <= x ; ++i)
	{
		if(x % i == 0)
		{
			int p = 0;
			while(x % i == 0)
			{
				++p;
				x /= i;
			}
			tot *= 1LL*(p + 1);
		}
	}
	if(x != 1)
		tot <<= 1;

	return 1LL*(tot << 1) - 1;
}
int main()
{
	int tc = 1;
	while(scanf("%lld %lld %lld",&m,&n,&p) != EOF)
	{
		if(!(n + m + p))
			break;
		ll x = abs(1LL*n * m * (p * p));
		printf("Case %d: %lld\n",tc++,medo(x));

	}
}
