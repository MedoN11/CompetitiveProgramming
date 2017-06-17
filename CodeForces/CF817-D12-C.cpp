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
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
ll n,s;

// Math + Binary Search
// if x is a really big number then so is x + 1
// so we just binary search for least number, and subtract n from that
int main()
{
	scanf("%lld %lld",&n,&s);
	ll lo = 1, hi = n;
	ll ans = -1;
	while(lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;
		ll tmp = mid;
		ll sum = 0;
		while(tmp > 0) sum += tmp % 10, tmp /= 10LL;
		if(mid - sum >= s)
			hi = mid - 1,ans = mid;
		else lo = mid + 1;
	}
	if(ans == -1)
		return puts("0");
	printf("%lld\n",n - ans + 1);

}
