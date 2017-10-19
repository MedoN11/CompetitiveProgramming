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

// Before solving the problem the following holds:

// Fermat's little theorm states that a ^ b % p = (a ^ (b % (p - 1)) % mod)
// exp(n) = nCk(2n,n)


// 1000*1000*1000 + 9 / 2 is a prime

// solve for that prime and 2 then apply crt
ll a,b,n;
ll mod = 1000*1000*1000 + 7;
ll mod3 = mod - 1;
ll mod2 = (mod - 1)/2;
ll two = 2;

const int maxn = 3e5 + 5;
ll fact[maxn + 5];
ll fact2[maxn + 5];
ll put(ll x,ll y) {
	ll p = 1;
	for (ll i= 1 ; i <= y; i<<=1 ) {

		if(y & i) p = (1LL*p*x) %mod2;
		x = (1LL*x*x) %mod2;
	}
	return p;
}
ll put2(ll x,ll y) {
	ll p = 1;
	for (ll i= 1 ; i <= y; i<<=1 ) {

		if(y & i) p = (1LL*p*x) %2;
		x = (1LL*x*x) %2;
	}
	return p;
}

ll nCk(ll n,ll m)
{
	if(n < 0 || m < 0) return 0;
	return (1LL * fact[n] * put( (1LL * fact[m] * fact[n-m] ) % mod2, mod2 - 2 ))%mod2;
}

ll nCk2(ll n,ll m)
{
	if(n < 0 || m < 0) return 0;
	return (1LL * fact2[n] * put2( (1LL * fact2[m] * fact2[n-m] ) % 2, 2 - 2 ))%2;
}
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

    lint egcd(lint a, lint b, lint &x, lint &y) {
    	if (!a) {
    		x=0;
    		y=1;
    		return b;
    	} else {
    		lint ret=egcd(b%a, a, y, x);
    		x-=y*(b/a);
    		return ret;
    	}
    }
lint inv(lint a, lint n) {
   	lint x, y, g=egcd(a, n, x, y);
   	assert(g==1);
   	return (x%=n)>=0?x:x+n;
   }

   lint pow(lint x, ulint y, lint mod) {
   	lint ret=1%mod, x2p=x%mod;
   	while (y) {
   		if (y%2) ret=mulmod(ret, x2p, mod);
   		y/=2;
   		x2p=mulmod(x2p, x2p, mod);
   	}
   	return ret;
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
ll modPow(ll a,ll b,ll mod) {
	if(b == 0)
		return 1;
	if(b == 1)
		return a % mod;
	ll x = modPow(a,b/2,mod)%mod;
	x *= 1LL*(x);
	x %= mod;
	if(b & 1) x *= a,x %= mod;
	return x%mod;
}

int main() {
	// process nCk
	fact[0] = 1;
	for(int i=1;i < maxn ;i++) fact[i] =( 1LL * fact[i-1] *i )%mod2,fact2[i] = (fact2[i - 1] * i)%2;
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld %lld %lld",&a,&b,&n);
		ll n2 = (nCk(2*n,n));
		// fermat little theorm
		vector<ll> v,p;
		v.pb(n2); p.pb(mod2);
		v.pb(nCk2(2*n,n)); p.pb(2);
		//cout << nCk2(2*n,n) << "\n";
		ll up = crt(p,v);
		up = modPow(up,b,mod - 1);
		ll res = (modPow(a,up,mod) + mod)%mod;
		res %= mod;
		printf("%lld\n",res);

	}

}
