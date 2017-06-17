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

// BIT + Math
// Editorial is detailed :)
struct ProductOfPrices
{
	int product(int n,int l,int x0,int a,int b);
};
const int mod = 1000000007;
struct BIT
{
	vector<ll> v;
	int n;
	BIT(int n_)
	{
		this->n = n_;
		v.assign(n,0);
	}
	void add(int ind,ll delta)
	{
		//cerr << "ina" <<ind << " " << "\n";
		while(ind < n)
		{
			v[ind] += delta;
			ind += ind & -ind;
		}
	//	cerr << "outa" << "\n";

	}
	ll sum(int ind)
	{
		ll s = 0;

		while(ind > 0)
		{
			s += v[ind]; s %= mod;
			ind -= ind & -ind;
		}

		return s;
	}
	int query(int l,int r)
	{
		return sum(r) - sum(l - 1);
	}
};


int ProductOfPrices::product(int n,int l,int x0,int a,int b)
{
	BIT s(l + 1);
	BIT cnt(l + 1);
	vector<int> v; v.assign(n,0); a %= l, b %=l;
	v[0] = x0 % l;
	vector<int> ans; ans.assign(n,0);
	ans[0] = v[0];
	int z = 0;
	if(v[0] != 0)
	s.add(v[0],v[0]);
	if(v[0] != 0)
	cnt.add(v[0],1);
	if(v[0] == 0) ++z;


	for(int i = 1 ; i < n ; ++i)
	{


		v[i] = ((1LL*v[i - 1] * (a)) %l % l) % l;
		v[i] += b;
		v[i] %= l;

		ll afterSum = (s.query(v[i] + 1,l)) %mod;
		ll afterCnt = cnt.query(v[i] + 1,l);

		ll beforeSum = (1LL*s.query(1,v[i]%mod)) %mod;
		ll beforeCnt = (1LL*cnt.query(1,v[i]%mod)) %mod;

		ans[i] = 1LL*(afterSum%mod) - (1LL*afterCnt%mod * v[i]%mod)%mod;
		ans[i] %= mod;
		ans[i] += (1LL*((1LL*beforeCnt%mod + z%mod) * (v[i]%mod)%mod) %mod) %mod - beforeSum%mod;
		while(ans[i] < 0) ans[i] += mod;
		ans[i] %= mod;
		if(v[i] != 0)
		s.add(v[i],v[i]%mod);
		if(v[i] != 0)
		cnt.add(v[i],1);
		if(v[i] == 0) ++z;
	}
	ll res = 1;
	for(int i = 1 ; i < n ; ++i) ans[i] %= mod, res *= 1LL*ans[i],res %= mod;
	return (int)(res);
}

int main()
{
	ProductOfPrices p;
	cout << p.product(135035,200000,160896,188253,164579);
}
