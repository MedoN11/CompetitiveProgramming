#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include <random>
#include<queue>
#include <bitset>
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
#include <unordered_map>
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
#define f first
#define s second
typedef pair<ll,ll> pii;
typedef pair<ll,pii> tttuple;

// Binary Search
// Editorial is good!
const int maxn = 500005;
ll arr[maxn];
int ptr = 0;
int n,k;
map<ll,ll> mp;
vector<pii> v;
bool can(ll mn) {
	ll has = 0;
	for (int i = 0 ; i < n ; ++i) {
		if (arr[i] > mn) {
			has += arr[i] - mn;
		}
	}
	has = min(has, 1LL*k);
	REP(i,v) {
		ll num = v[i].f;
		int freq = v[i].s;
		if (num > mn) {
			break;
		}
		has -= 1LL*(mn - num) * freq;
	}

	return has >= 0;
}

bool canMax(int maxxx) {
	ll has = 0;
	ll cur = 0;
	for (int i = 0 ; i < n ; ++i) {
		if (arr[i] > maxxx) {
			has += arr[i] - maxxx;
		}
	}
	has = min(has, 1LL*k);
	cur = has;

	REP(i,v) {
		ll num = v[i].f;
		ll freq = v[i].s;
		if (num < maxxx) {
			continue;
		}
		has -= 1LL*(num - maxxx) * 1LL*freq;
	}
	if (has < 0) {
		return false;
	}
	ll used = cur - has;
	REP(i,v)  {
		ll num = v[i].f;
		ll freq = v[i].s;
		if (num > maxxx) {
			continue;
		}
		used -= 1LL*(maxxx - num) * 1LL*freq;
	}
	return used <= 0;

}
int main() {
	scanf("%d",&n);
	scanf("%d",&k);

	for (int i = 0 ; i < n ; ++i) {
		scanf("%lld",&arr[i]);
		mp[arr[i]]++;
	}

	for(map<ll,ll>::iterator it = mp.begin() ; it != mp.end() ; it++) {
			v.pb(pii(it->first,it->second));
		}


	ll lo = 0, hi = (int)(1e9) + 1;
	int ans = 0;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (can(mid)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}


	lo = 0;
	hi = (int)(1e9) + 1;
	int max = 0;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (canMax(mid)) {
			max = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}


	cout << (max - ans);



}
