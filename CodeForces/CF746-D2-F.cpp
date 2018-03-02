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
const int maxn = 200005;
// 2 ptrs + set
ll arr[maxn],t[maxn];
int n,k,w;
set<pii> active;
set<pii> unused;
ll sum = 0;
ll tot = 0;
void add(int ind) {
	tot += arr[ind];
	if(sz(active) == w) {
		if (active.begin()->first < t[ind]) {
			unused.insert(pii(active.begin()->first,active.begin()->second));
			sum -= (active.begin()->first)/2;
			if(active.begin()->first % 2 == 1) --sum;
			sum += active.begin()->first;
			active.erase(active.begin());
			sum += t[ind]/2;
			if(t[ind] % 2) ++sum;
			active.insert(pii(t[ind],ind));

		} else {
			sum += t[ind];
			unused.insert(pii(t[ind],ind));
		}
	} else {
		active.insert(pii(t[ind],ind));
		sum += t[ind] / 2;
		if(t[ind] % 2) ++sum;
	}
}

void remove(int ind) {
	tot -= arr[ind];
	if(active.find(pii(t[ind],ind)) != active.end()) {
		sum -= t[ind] / 2;
		if(t[ind] % 2) -- sum;
		active.erase(pii(t[ind],ind));
		if(sz(unused) > 0) {
			pii b = *unused.rbegin();
			sum -= b.first;
			sum += b.first/2;
			if(b.first % 2) ++sum;
			active.insert(b);
			unused.erase(b);
		}
	} else {
		sum -= t[ind];
		unused.erase(pii(t[ind],ind));
		active.erase(pii(t[ind],ind));
	}
}
ll getAns() {
	int l = 0,r = 0;
	ll ans = 0;
	while(r < n) {
		add(r);
		while(sum > k && l <= r) {
			remove(l);
			++l;
		}
		ans = max(ans,tot);
		++r;
	}
	return ans;
}
int main() {
	scanf("%d %d %d",&n,&w,&k);
	for (int i = 0 ; i  < n ; ++i) {
		scanf("%lld",&arr[i]);
	}
	for (int i = 0 ; i < n ; ++i) {
		scanf("%lld",&t[i]);
	}
	cout << getAns() << "\n";


}
