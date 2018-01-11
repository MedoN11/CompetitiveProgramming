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
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define time __time
typedef pair<ll,ll> pii;
#define fst first.first
#define snd first.second
#define trd second.first
ll dp[3][2001][2001];
ll mod = 1e9 + 7;
ll modPow(ll n,ll p) {
	if(p == 0)
		return 1;
	if(p == 1)
		return n;
	ll sol = modPow(n, p / 2);
	if(p % 2 == 1) {
		sol *= 1LL*sol;
		sol %= mod;
		sol *= 1LL*n;
		sol %= mod;
		return sol;
	} else {
		return 1LL*((sol)*(sol))%mod;
	}
}
ll inv(ll p) {
	return modPow(p, mod - 2);
}
ll inv_c[7000];
ll fin;
ll solve(int y,int b,int h) {
	if(b < 0 || h < 0)
		return 0;
	if ( (2 * b + h) == fin)
		return (b + h);
	ll &ret = dp[y][b][h];
	if(ret != -1)
		return ret;
	ret = 0;
	ll p = inv_c[b + h]%mod;
	ll h_coef = h - 1;
	ll b_coef = b;
	if(!y)--b_coef;
	else --h_coef;
	ll add = 0;
	if(h_coef > 0) {
	    add = 1LL*p;
		add *= 1LL*h_coef;
		add %= mod;
		add *= 1LL*solve(y,b,h - 1);
		add %= mod;
		ret += 1LL*add;
		ret %= mod;
	}
	if(b_coef > 0) {
		add = p;
		add *= 1LL*b_coef;
		add %= mod;
		add *= 1LL*solve(y,b - 1,h + 1);
		add %= mod;
		ret += 1LL*add;
		ret %= mod;

	}
	if(!y) {
			add = p;
			add *= 1LL*solve(1,b - 1,h + 1);
			add %= mod;
			ret += 1LL*add;
			ret %= mod;
		}
	return ret;
}

int findEV(int B,int H,int T) {
	fin = (2 * B + H);
	fin -= T;
	for(int i = 0 ; i < 7000 ; ++i) {
		inv_c[i] = modPow(1ll*i,mod - 2);
	}
	memset(dp,-1,sizeof(dp));
	ll tot = B;
	tot *= H;
	tot %= mod;
	tot *= solve(0,B,H);
	tot %= mod;
	return tot;

}
int main() {
	int B,H,T; cin >> B >> H >> T;
	cout << findEV(B,H,T)<<"\n";
}
