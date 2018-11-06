#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include <deque>
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
using namespace std;
typedef pair<long long,long long> pii;
vector<pair<long long,long long> > v;
long long grid[1005][1005];
int n,m;
vector<pii> xcord,ycord;
long long f(long long z,vector<pii> &v) {
	long long res = 0;
	z *= 4;
	REP(i,v) {

		res += (v[i].first - z ) * (v[i].first -z) * v[i].second;

	}
	return res;
}
pii solve(vector<pii> &v) {
	long long l = 0, r = max(n,m) + 1;

	while (r - l > 3) {
		long long m1 =  (l + (r - l) / 3) ;
		long long m2 = (l + 2 * (r - l) / 3);
		if (f(m1,v) <= f(m2,v)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	ll ans = 1LL << 59;
	long long p = 0;
	cerr << l << " " << r << "\n";
	for (int i = l ; i <= r ; ++i) {
		long long tmp = f(i,v);
		if (tmp < ans) {
			ans = tmp;
			p = i;
		}
	}
	return make_pair(ans,p);
}
int main() {

	scanf("%d %d",&n,&m);
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < m ; ++j) {
			scanf("%lld",&grid[i][j]);
			xcord.pb(make_pair(i * 4 + 2,grid[i][j]));
			ycord.pb(make_pair(j * 4 + 2,grid[i][j]));
		}
	}

	//cerr << f(2,xcord) << " " << f(3,ycord) << "\n";
	long long x,y;
	long long ans = 0;
	pii p = solve(xcord);
	ans += p.first;
	x = p.second;
	p = solve(ycord);
	ans += p.first;
	y = p.second;
	cout << ans << "\n";
	cout << x  << " " << y  << "\n";

}
