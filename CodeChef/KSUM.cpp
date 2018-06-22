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
typedef pair<ll,ll> pii;
int n,k;
vector<ll> v;
typedef pair<ll,pii> tttuple;
int main() {
	ios
	cin >> n >> k;
	ll ss = 0;
	for (int i = 0 ; i < n ; ++i) {
		ll x; cin >> x;
		v.pb(x);
		ss += x;
	}
	set<tttuple> s;
	s.insert(tttuple(ss,pii(0,n - 1)));
	while (k--) {
		//cerr << "here\n";
		tttuple t = *s.rbegin();
		s.erase(*s.rbegin());
		int l = t.second.first, r = t.second.second;
		cout << t.first <<" ";
		if (l != r) {
			s.insert(tttuple(t.first - v[l],pii(l + 1,r)));
		}
		if (l != r) {
			s.insert(tttuple(t.first - v[r],pii(l,r - 1)));
		}
	}
	return 0;
}
