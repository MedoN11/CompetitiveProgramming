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
const int maxn = 1000*1000;
ll arr[maxn];
ll n;
int main() {
	cin >> n;
	ll sum = n * (n + 1) / 2;
	if(sum & 1) {
		puts("NO");
		return 0;
	}
	sum >>= 1;
	vector<int> v,q;
	for (int i = n ; i >= 1 ; --i) {
		if(sum >= i) {
			sum -= i;
			v.pb(i);
		} else {
			q.pb(i);
		}
	}
	printf("YES\n");
	printf("%d\n",sz(v));
	REP(i,v) printf("%d ",v[i]);

	printf("%d\n",sz(q));
	REP(i,q) printf("%d ",q[i]);

}
