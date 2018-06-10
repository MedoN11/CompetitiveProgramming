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
const int maxn = 200005;

// Break into independent ranges
// for each range it is optimal to tile zeros from i + b - 1 till end of range with increment of b
// greedy
int n,a,b,k;
char s[maxn];
vector<pair<int,pii> > segs;
vector<int> ans;
int main() {


	cin >> n >> a >> b >> k;
	scanf("%s",s);


	int tot = 0;
	for (int i = 0 ; i < n ; ++i) {
		while (i < n && s[i] == '1') ++i;

		int j = i;
		while (j < n && s[j] == '0') ++j;
		if (j  > i) {
			segs.pb(make_pair(j - i,pii(i,j - 1)));
			tot += (j - i) / b;
		}
		i = j - 1;
	}

	for (int f = 0 ; f < sz(segs) ; ++f) {
		int i = segs[f].second.first,j = segs[f].second.second;
	//	cerr << i << " " << j << "\n";

		for (int k = i + b - 1 ; k <= j && tot >= a ; k += b) {
			//cerr <<"here";
			--tot;
			ans.pb(k + 1);
		}
	}

	printf("%d\n",sz(ans));
	REP(i,ans) printf("%d ",ans[i]);
}

