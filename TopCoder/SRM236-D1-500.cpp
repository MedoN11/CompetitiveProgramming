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
typedef vector<int> VI;
typedef vector<ll> VL;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;;
// Dijikstra greedy approach
// do some pruning if you get tle/mle
int n;
struct HammingNumbers {
	int getNumber(VI v,int n);
};
set<ll> s;
int HammingNumbers::getNumber(VI v,int n) {
	priority_queue<ll,VL,greater<ll> > pq;
	pq.push(1);
	ll big = 0;
	int in = 1;
	int rem = n - 1;
	set<ll> active;
	while(!pq.empty()) {
		ll u = pq.top(); pq.pop();
		if(u > INT_MAX)
			continue;
		if(s.count(u))
			continue;
		s.insert(u);
		if(rem == 0)
			return u;
		rem--;
		active.erase(u);
		REP(i,v) {
			ll nxt = 1LL*u * v[i];
			if(sz(active) > n && *(active.rbegin()) >= big)
				continue;

			pq.push(nxt);
			active.insert(nxt);
		}
	}
	return -1;
}
