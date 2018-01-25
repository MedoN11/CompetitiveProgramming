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
#define time __time
const ll m = 100001;
const ll maxn = 1LL*m * m * m;
vector<ll> v;
typedef pair<ll,ll> pii;
map<ll,ll> dp;

ll solve(ll rem) {
	if(rem == 0)
		return 0;
	if(dp.find(rem) != dp.end())
		return dp[rem];
	vector<ll>::iterator it = upper_bound(all(v),rem);
	--it;
	ll num = *it;
	return dp[rem] = rem / num + solve(rem % num);
}
pii bruteLen(ll m) {
	ll ans = 0;
	for(int j = m ; j >= 0 ; --j) {
		ans = max(ans,solve(j));
	}
	pii p = pii(0,ans);
	for (int j = m ; j >= 0 ; --j) {
		if(solve(j) == ans) {
			p.first = j;
			break;
		}
	}
	cout << "ANSWER BRUTE : " << p.first << " " << p.second << "\n";
	return p;
}
pii merge(pii &a,pii &b) {
//	if(a.first > m && b.first > m) return pii(0,0);
//	if(a.first > m) return b;
//	if(b.first > m) return a;
	if(a.second < b.second)
		return b;
	if(a.second > b.second)
		return a;
	if(b.first > a.first)
		return b;
	if(a.first > b.first)
		return a;
	return a;
}
map<ll,pii> memo;
pii rec(ll rem) {
	//if(rem < 0) return pii(0,0);
	//cerr << rem << "\n";
	/// min?
	if(rem == 0) {
		return pii(0,0);
	}
	if(memo.find(rem) != memo.end())
		return memo[rem];
	vector<ll>::iterator it = lower_bound(all(v),rem);
	if(*it > rem) --it;
	pii ans = rec(rem - *it);
	ans.second++,ans.first+=*it;
	if(it != v.begin()) {
		it--;
		vector<ll>::iterator it2 = lower_bound(all(v),rem);
		if(*it2 > rem) --it2;
		//cerr << (*it2) -1 << " " << *it << "\n";
		pii tmp = rec( ((*it2) - 1) - *it);
		tmp.second++,tmp.first+=*it;
		ans = merge(ans,tmp);
	}
	return memo[rem] = ans;

}
int main() {
	ll m;
	cin >> m;

	for (int ll i = 1 ; i * i * i < maxn; ++i ) {
		v.pb(1LL*i*i*i);

	}
	pii ans = rec(m);
	cout << ans.second << " " << ans.first << "\n";

}

