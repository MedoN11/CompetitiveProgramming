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
const int maxn = 1000*1000 + 1;
int dx[8] = {2,2,-2,-2,1,-1,1,-1};
int dy[8] = {1,-1,1,-1,2,2,-2,-2};
bool ok(int i,int j,int n) {
	return i >= 0 && i < n && j >= 0 && j < n;
}
// solve for a single row and exploit symmetry for short code
ll naive(int n) {
	ll ways = 0;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			ll cur = n * n - 1;
			for (int k = 0 ; k < 8 ; ++k) {
				int xc = i + dx[k], yc = j + dy[k];
				if (ok(xc,yc,n)) {
					--cur;
				}
			}
			ways += cur;
		}
	}
	return ways / 2;
}
ll solve (ll n) {
	ll ways = 0;
	if (n < 9) {
		return naive(n);
	}
	ll a = (n - 2) * (n - 2);
	ways += 1LL*a * (n * n - 9);
	ways += 4LL * (n * n - 3);
	ways += 8LL * (n * n - 4);
	ways += 4LL * (n - 4) * (n * n - 5);
	return 20LL + 1LL*(n - 7) * 4 + ways / 2;

}
int main() {
	int k; cin >> k;
	for(int i = 1 ; i <= k ; ++i) {
		printf("%lld\n",solve(i));

	}
}
