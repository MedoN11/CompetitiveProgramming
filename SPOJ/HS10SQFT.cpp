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
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

using namespace std;


int main()
{

	//fast
	ll x;
	int tc;
	//cin >> tc;
	scanf("%d",&tc);

	int t =1;


	while(tc--)
	{

		scanf("%lld",&x);

		printf("Case #%d:\n",t++);
		bool f = 0;
		ll b = 0;
		for(ll a = 2; (long long)(1LL*a * a * a * a*1LL) <= x  ; ++a)
		{
		//	cerr << a << endl;
			ll z =  1LL*a * a - 1;
			if(x % z != 0)
				continue;
			b = 1LL*(x / z);
			b--;
			ll s = (long long)(sqrt(b));

			ll oth = 1LL*(s+1)*(s+1) - 1;
			if(1LL*z*oth == x)
				++s;
			oth = 1LL*s*s - 1;
			if(1LL*z *oth != x)
				continue;

		//	cerr << (1LL*s*s - 1) * (1LL*a * 1LL*a - 1) << endl;


			if(!f)
				printf("%lld",x);
			f = 1;
			printf("=(%lld^2-1)*(%lld^2-1)",a,s);
		}
		if(!f)
			printf("For n=%lld there is no almost square factorisation.\n",x);
		else printf("\n");

	}

}
