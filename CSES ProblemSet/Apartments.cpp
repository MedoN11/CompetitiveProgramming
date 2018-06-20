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
int n,m,k;
vector<int> s1;
multiset<int> s2;
int main() {
	scanf("%d %d %d",&n,&m,&k);
	for (int i = 0 ; i < n ; ++i) {
		int x; scanf("%d",&x);
		s1.pb(x);
	}
	for (int i = 0 ; i < m ; ++i) {
		int x; scanf("%d",&x);
		s2.insert(x);
	}
	sort(all(s1));
	int ans = 0;
	REP(i,s1) {
		int x = s1[i] - k;
		multiset<int>::iterator it = s2.lower_bound(x);
		if (it != s2.end() && *it <= x + k) ++ans,s2.erase(it);
	}
	printf("%d\n",ans);

}
