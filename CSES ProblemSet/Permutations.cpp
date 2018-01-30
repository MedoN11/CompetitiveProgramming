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
int main() {
	int n;
	scanf("%d",&n);
	if(n == 1) {
		printf("1\n");
		return 0;
	}
	if(n == 4) {
		printf("2 4 1 3\n");
		return 0;
	}
	if(n < 4) {
		printf("NO SOLUTION");
		return 0;
	}
	vector<int> v;
	for (int i = 1 ; i <= n ; i += 2) {
		v.pb(i);
	}
	for (int i = 2 ; i <= n; i += 2) {
		v.pb(i);
	}
	REP(i,v) printf("%d ",v[i]);

}
