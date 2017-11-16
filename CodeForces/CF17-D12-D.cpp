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
using namespace std;
typedef vector<ll> VI;
typedef pair<ll,ll> PII;

// reducing big mod using euler formula conseuqence ( dividing exponent by phi(m) if a and m are coprime)
// then combine value of mods using crt




#define lint ll
#define ulint ll
inline lint mulmod(lint a, lint b, lint mod) {
	a%=mod, b%=mod;
	ulint ans=0;
	while (b) {
		if (b&1) ans=(ans+a)%mod;
		a=((ulint)a+a)%mod;
		b>>=1;
	}
	return ans;
}

lint gcd(lint a, lint b) {
	return a?gcd(b%a, a):b;
}

ll egcd(ll a, ll b, ll &x, ll &y) {
	if (!a) {
		x=0;
		y=1;
		return b;
	} else {
		ll ret=egcd(b%a, a, y, x);
		x-=y*(b/a);
		return ret;
	}
}
ll inv(ll a, ll n) {
	ll x, y, g=egcd(a, n, x, y);
	assert(g==1);
	return (x%=n)>=0?x:x+n;
}


ll crt( vector<lint> &inmods,  vector<lint> &invals) {
	ll mod=1, result=0;
	for (int i=0; i<(int)inmods.size(); i++) mod*=inmods[i];
	for (int i=0; i<(int)inmods.size(); i++) {
		ll inmod=inmods[i];
		if (inmod==1) continue;
		ll unit=mod/inmod;
		unit*=inv(unit%inmod, (ll)inmod);
		result=(result+mulmod(unit, invals[i], mod))%mod;
	}
	return result;
}
ll modpow(ll a,ll p,ll mod) {
	if(p == 0) return 1;
	if(p == 1) return a;
	ll x = modpow(a,p>>1,mod);
	x *= 1LL*x; x %= mod;
	if(p & 1) x*=a;
	x %= mod;
	return x;
}
VI factors,phi,prime;
string n,bt;
ll c,b;

ll solve(int ind) {
	ll r = 0;
	REP(i,bt) {
		r *= 10;
		r += bt[i] - '0';
		r %= prime[ind];
	}
	if(r == 0)  {

//		/// coprime case ?!?!
//		r = 0;
//		REP(i,n) {
//			r *= 10;
//			r += n[i] - '0';
//			r %= factors[ind];
//		}
//		// p divides n
		if(r == 0)
			return 0;
		// p does not divide n
	}
	r = 0;
	REP(i,n) {
		r *= 10;
		r += n[i] - '0';
		r %= phi[ind];
	}

	return modpow(b,(r - 1 + phi[ind]) % phi[ind],factors[ind]);
}
int main() {
	ios
	cin >> bt >> n >> c;
	REP(i,bt) {
		b *= 10;
		b += bt[i] - '0';
		b %= c;
	}
	if(sz(n) < 15) {
		ll ans = (b - 1 + c) % c;
		stringstream ss(n); ll x; ss >> x;
		ans *= modpow(b,x - 1,c);
		ans %= c;
		if(ans == 0) ans = c;
		cout << ans << "\n";
		return 0;
	}
	//cerr << "here" << "\n";
	ll tmp = c;
	for(ll i = 2 ; i * i <= tmp ; ++i) {
		if(tmp % i == 0) {
			ll res = 1;
			while(tmp % i == 0) {
				tmp /= i;
				res *= i;
			}
			factors.pb(res);
			prime.pb(i);
			phi.pb(res - res / i);
		}
	}
	if (tmp != 1) {
		phi.pb(tmp - 1);
		prime.pb(tmp);
		factors.pb(tmp);
	}
	VI mods;
	REP(i,factors) {

		mods.pb(solve(i));

	}
	//cerr << "here" << "\n";
	ll ans = crt(factors,mods);
	//cerr << "here" << "\n";
	ans *= ((b - 1 + c) % c);
	ans %= c;
	if(ans == 0) ans = c;
	cout << ans << "\n";
}

