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
typedef pair<int,int> pii;
typedef pair< long double,long double> pdd;
#define F first
#define S second
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
//#define mp make_pair
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define for1LL(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define fornLL(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define ld long double
ll a[50001];
typedef vector<ll> vi;
typedef vector<vi> vvi;
const ll mod = 98765431;
// Matrix Pow
// transition matrix
// Formula transition matrix^t * constant matrix
// [ n -1 0 ]   [sum]
// [ n -1 0 ] * [sum]
// [ 1 0 -1 ]   [a[i]]
// Value might be negative at the end so make sure you wrap up the modulo!
vvi matrixUnit(ll n) {
	vvi res(n, vi(n));
	for (int i = 0; i < n; i++)
		res[i][i] = 1;
	return res;
}

vvi matrixAdd(const vvi &a, const vvi &b) {
	int n = a.size();
	int m = a[0].size();
	vvi res(n, vi(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = 1LL*(a[i][j] + b[i][j]) % mod;
	return res;
}

vvi matrixMul(const vvi &a, const vvi &b) {
	int n = a.size();
	int m = a[0].size();
	int k = b[0].size();
	vvi res(n, vi(k));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			for (int p = 0; p < m; p++)
				res[i][j] = 1LL*(res[i][j] + (long long) a[i][p] * b[p][j]) % mod;
	return res;
}

vvi matrixPow(const vvi &a, ll p) {
	if (p == 0)
		return matrixUnit(a.size());
	if (p & 1)
		return matrixMul(a, matrixPow(a, p - 1));
	return matrixPow(matrixMul(a, a), p / 2);
}

vvi matrixPowSum(const vvi &a, ll p) {
	int n = a.size();
	if (p == 0)
		return vvi(n, vi(n));
	if (p % 2 == 0)
		return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n), matrixPow(a, p / 2)));
	return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
}

int main() {
	ios
	ll n,t;
	cin >> n >> t;
	ll sum = 0;
	for (int i = 0 ; i < n ; ++i) {
		cin >> a[i];
		sum += 1LL*a[i];
		sum %= mod;
	}
	vvi pat(3,vi(3));
	pat[0][0] = n % mod; pat[0][1] = -1, pat[0][2] = 0;
	pat[1][0] = n % mod; pat[1][1] = -1, pat[1][2] = 0;
	pat[2][0] = 1, pat[2][1] = 0, pat[2][2] = -1;
	pat = matrixPow(pat,t);

	for (int i = 0 ; i < n ; ++i) {
		vvi tab(3,vi(1));
		tab[0][0] = sum;
		tab[1][0] = sum;
		tab[2][0] = a[i] % mod;
		vvi res = matrixMul(pat,tab);
		ll x = res[2][0];
		while (x < 0) x += mod;
		cout << x%mod << "\n";
	}
//	while (t--) {
//		ll s = 0;
//
//	}

}


