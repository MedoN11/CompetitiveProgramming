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
#define read(f) freopen (f,"r",stdin)
#define write(f) freopen (f,"w",stdout)
typedef pair<int,int> ii;
// 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8



int main()
{

	ll n,k; cin >> n >> k;
	if(k > 1e9)
		return puts("-1");
	ll lim = 1LL*k*(k + 1); lim >>= 1;
	ll ans = -1;
	for(ll i = 1 ; 1LL*i * i <= n ; ++i)
	{
		if(n % i == 0)
		{
			ll d1 = i, d2 = n / i;
			if(d1 >= lim)
				ans = max(ans,d2);
			if(d2 >= lim)
				ans = max(ans,d1);
		}
	}
	if(ans < 0 || lim < 0)
		return puts("-1");
	ll sum = n / ans;
	for(int i = 1 ; i <= k - 1; ++i)
	{
		printf("%lld ",1LL*i*ans); sum -= i;
	}

	printf("%lld ",1LL*ans*sum);


}
