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
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
typedef vector<int> vi;
/* Greedy + DP
 *  Using exchange arguments we can prove that problem p1 must be solved before problem p2
 *  if(p1.decay * p2.time > p2.decay * p1.time)
 *  So that becomes our comparator
 *  Then we use dp to choose the most optimal subset as a knapsack
 */
int n;
ll s = 0;

struct TheProgrammingContestDivOne {
	int find(int T,vi m,vi d,vi t);
};
struct Problem {
	ll m,d,t;
	Problem(int m_,int d_,int t_) {
		m = m_;
		d = d_;
		t = t_;
	}
	bool operator<(const Problem  &p) const {
		ll lhs = p.d * t;
		ll rhs = d * p.t;
		return lhs < rhs;
	}
};
vector<Problem> v;
int maxt;
ll dp[51][100001];
ll solve(int ind,int t) {
	if(t > maxt) return -(1LL << 52);
	if(ind == sz(v)) return 0;
	ll &ret = dp[ind][t];
	if(ret != -1)
		return ret;
	ret = solve(ind + 1,t);
	ret = max(ret,1LL*v[ind].m - 1LL*(t + v[ind].t) *1LL*v[ind].d + solve(ind + 1,t + v[ind].t));
	return ret;
}
int TheProgrammingContestDivOne::find(int T,vi m,vi d,vi t) {
	maxt = T;
	REP(i,m) {
		v.pb(Problem(m[i],d[i],t[i]));
	}
	sort(all(v));
	memset(dp,-1,sizeof(dp));
	return (int)(solve(0,0));
}
