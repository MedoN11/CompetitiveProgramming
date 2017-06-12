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
typedef vector<int> vi;
#define ln log
#define e exp
double EPS = 1e-9;
ll n;
void naive(int x)
{
	for(int L = 0 ;  ; ++L)
	{
		double y = ln(n) - L;
		double x = 1 - e(y);
		if(fabs(x) - 1 >= EPS)
			continue;
		printf("%lld %.8f\n",L,x);
		return;
	}
}
int main()
{

	while(scanf("%lld",&n) != EOF)
	{
		//naive(n);
		if(!n)
			break;
		ll lo = 0, hi = n;
		ll ans = -1;
		double ansx = -1;
		while(lo <= hi)
		{
			ll mid  = 1LL*lo + (hi - lo) / 2LL;
			long double y = ln(n) - mid;
			long double x = 1 - e(y);
			if(fabs(x) - 1 >= EPS)
				lo = mid + 1;
			else ans = mid,hi = mid - 1,ansx = x;
		}
		printf("%lld %.8f\n",ans,ansx);
	}

}


