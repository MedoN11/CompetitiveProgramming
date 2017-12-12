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
#include <unordered_map>
using namespace std;
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;;
const int maxn = 100005;

// Simple BIT Usage + Bruteforce
// other non BIT approaches exist
int bit[maxn];
void upd(int ind,int x) {
	while(ind < maxn) {
		bit[ind] += x;
		ind += ind & - ind;
	}
}
int sum(int ind) {
	int s = 0;
	while(ind > 0) {
		s += bit[ind];
		ind -= ind & - ind;
	}
	return s;
}
int dp[maxn];
int mark[maxn];
vector<int> v;
int main() {
	int n;
	scanf("%d",&n);
	v.resize(n);
	int bad = 0;
	for(int i = 0 ; i < n ; ++i) {
		scanf("%d",&v[i]);
		int bef = i;
		bef -= sum(v[i]);
		if(bef == 1)
			dp[bad]++;
		if(bef == 0) mark[v[i]] = 1;
		bad = max(bad,v[i]);
		upd(v[i],1);
	}

	int high = -5;
	int ans = 1;
	for(int i = 1; i <= n ;++i) {
		int del = dp[i] - mark[i];
		if(del > high) {
			high = del;
			ans = i;
		}
	}
	cout << ans << "\n";
}
