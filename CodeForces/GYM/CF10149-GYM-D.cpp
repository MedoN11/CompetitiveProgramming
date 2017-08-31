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
#include<string>
#include<vector>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
int n,p,k;
typedef pair<pii,int> state;
map<state,int> mp;
ll mod = 1000*1000*1000 + 7;
ll fact[300000 + 5];

int put(int x,int y)
{
	int p = 1;
	for(int i= 1 ; i <= y; i<<=1 )
	{
		if(y & i) p= (1LL*p*x) %mod;
		x = (1LL*x*x) %mod;
	}
	return p;
}

int nCk(int n,int m)
{
	if(m == 0)
		return 1;
	return (1LL * fact[n] * put( (1LL * fact[m] * fact[n-m] ) % mod, mod - 2 ))%mod;
}
ll fast(int n,int r)
{

	return ((nCk(n,r)%mod))%mod;
}


//int solve(int ind,int dir,int lst)
//{
//	if(ind < lst)
//		return 0;
//	if(ind == dir)
//		return 1;
//	if(ind == 0)
//	{
//		return 0;
//	}
//	int ret = 0;
//	if(mp.find(state(pii(ind,dir),lst)) != mp.end())
//		return mp[state(pii(ind,dir),lst)];
//	ret += solve(ind - 1,dir - 1,!lst);
//	ret %= mod;
//	ret += solve(ind - 1,dir,lst);
//	ret %= mod;
//	return mp[state(pii(ind,dir),lst)] = ret;
//}
int main()
{

	int t;
	scanf("%d",&t);
	int a,b;
	fact[0] = 1;
	for(int i=1;i < 300005;i++) fact[i] =( 1LL * fact[i-1] *i )%mod;

	while(t--)
	{
		scanf("%d %d",&a,&b);
		printf("%lld\n",(2LL*fast(a - 1,b)%mod));
	}



}
