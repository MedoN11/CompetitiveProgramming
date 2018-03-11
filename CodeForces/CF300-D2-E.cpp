#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include <random>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include <unordered_map>
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
#define ios std::ios_base::sync_with_stdio(false);
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
typedef pair<ll,ll> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 1000*1000*10 + 7;
// Prime in factorial + Binary search
ll pfac(ll n, ll k) {
	ll sum = 0;
	ll pow = k;
	while (1) {
		sum += n / pow;
		if (pow > n / k) break;
		pow *= k;
	}
	return sum;
}

unordered_map<ll,ll> mp(10000000/3);
int arr[maxn];
int sp[maxn];
bool prime[maxn];
inline void add(ll x,ll cnt) {
	while(x != 1) {
		int p = sp[x];
		int f = 0;
		while(x % p == 0) ++f, x /= p;
		mp[p] += 1LL*f*cnt;
	}
}
int main() {
	memset(prime,1,sizeof(prime));
	memset(sp,-1,sizeof(sp));
	for(int i = 2 ; i < maxn ; ++i) {
		if(prime[i]) {
			sp[i] = i;
			for(int j =  i << 1 ; j < maxn ; j += i) {
				prime[j] = 0;
				if(sp[j] == -1) sp[j] = i;
			}
		}
	}
	int n;
	scanf("%d",&n);
	for (int i = 0 ; i < n ; ++i) {
		int x;
		scanf("%d",&x);
		arr[x]++;
	}
	for (int i = maxn - 2; i >= 2 ; --i) {
		arr[i] += arr[i + 1];
		if(arr[i] != 0) {
			int x = i;
			int cnt = arr[i];
			while(x != 1) {
				int p = sp[x];
				int f = 0;
				while(x % p == 0) ++f, x /= p;
				mp[p] += 1LL*f*cnt;
			}
		}
	}

	ll lo = 1,hi = 1LL << 48;
	ll ans = 0;
	while(lo <= hi) {
		ll mid = 1LL*lo + (hi - lo) / 2LL;
		bool ok = 1;
		for(unordered_map<ll,ll>::iterator it = mp.begin() ;it != mp.end() ;it++) {
			if(pfac(mid,it->first) < it->second)
				ok = 0;
		}

		if(ok) {
			hi = mid - 1;
			ans = mid;
		}
		else lo = mid + 1;
	}
	cout << ans << "\n";
}
