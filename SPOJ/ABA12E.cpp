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
int n,k;
vector<ll> v;
int arr[150001];
ll tot = 0;
ll sum[150001];
ll query(int l,int r)
{
	ll left = l == 0 ? 0 : sum[l - 1];
	ll right = sum[r];
	return right - left;
}
long long search(ll x)
{
	ll cnt = 0;
	for(int i = 0 ; i < n ; ++i)
	{
		int lo = i , hi = n - 1;
		int res = -1;
		while(lo <= hi)
		{

			int mid = lo + (hi - lo) / 2;

			if(query(i,mid) <= x)
				lo = mid + 1,res = mid;
			else hi = mid - 1;
		}

		if(res != -1) cnt += 1LL*res - i + 1;
	}

	return cnt;
}
int main()
{
	scanf("%d %d",&n,&k);

	ll need = k;
	ll lo = 0, hi = (ll)(1e15);
	//--need;
	scanf("%lld",&sum[0]);
	for(int i = 1; i < n ; ++i)
		scanf("%lld",&sum[i]),sum[i] += sum[i - 1];


	ll ans = -1;
	while(lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;
		if(search(mid) >= need)
			hi = mid - 1, ans = mid;
		else lo = mid + 1;
	}
	printf("%lld\n",ans);
}
