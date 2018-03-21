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
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
int t;
const int maxn = 100005;
int main() {

	int n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		vector<ll> v,pre;
		v.resize(n);
		pre.resize(n);
		ll sum = 0;

		for (int i = 0 ; i < n ; ++i) {
			scanf("%lld",&v[i]);
			sum += 1LL*v[i];
		}
		sort(all(v));
		reverse(all(v));
		for (int i = 0 ; i < n ; ++i) {
			if(i > 0) pre[i] += pre[i - 1];
			pre[i] += v[i];
		}

		if(sum % 2 == 1) {
			puts("N");
			continue;
		}

		ll run = 0;
		bool skip = 0;
		for (ll i = 0 ; i < n ; ++i) {
			run += v[i];
			ll other = (i + 1) * i;
			int lo = i + 1, hi = n - 1;
			int ans = i;
			while(lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if(v[mid] >= (i + 1))
					lo = mid + 1,ans = mid;
				else hi = mid - 1;
			}

			other += (long long)(1LL*(ans - i) * (i + 1));
			other += (long long)(pre[n - 1]  - pre[ans]);
			//for (int j = i + 1 ; j < n ; ++j) other += min(v[j],1LL*i + 1);
			if(run > other) {
				skip = 1;
				break;
			}
		}
		if(skip) puts("N");
		else puts("Y");

	}
}
