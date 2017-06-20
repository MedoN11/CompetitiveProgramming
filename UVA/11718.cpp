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
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define pb push_back
ll n,k,mod;

// Problem can be restated as
// count how many times an element appears in a sequence of length k using n distinct elements where repetitions are allowed
// so we can count that as follows
// Formula is Sigma i from (0 to k) { i * C(k,i) * pow(n - 1,k - i)}
// basically let's pick i position and fix them for the current element, and fill the rest with something different in (n-1)^k ways
// multiply that by i for occurences
// this summation has a closed formula of k*(n-1)^k
// so multiply that by sum of elements

ll modPow(ll n,ll k,ll mod)
{
	if(k == 0)
		return 1LL;

	if(k & 1)
	{
		ll x = modPow(n,k / 2,mod);
		x *= x;
		x %= mod;
		x *= n;
		x %= mod;
		return x;
	}
	else
	{
		ll x = modPow(n,k / 2,mod);
		x *= x;
		x %= mod;
		return x;
	}
}
int main()
{
	int tc;

	scanf("%d",&tc);
	int c = 1;
	while(tc--)
	{

		scanf("%lld %lld %lld",&n,&k,&mod);
		ll t = modPow(n,k - 1,mod);

		t  *= k; t %= mod;
		ll sum = 0;
		ll x;
		for(int i = 0 ; i < n ; ++i)
		{
			scanf("%lld",&x); x %= mod;
			sum += (1LL*t * x) % mod;
			sum %= mod;
		}
		printf("Case %d: %lld\n",c++,sum);

	}
}
