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
#define time __time
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
ll n,b;
const int maxn = 4005;
int dp2[maxn][maxn];
int dp1[maxn];
int arrive[maxn];
int main() {
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d",&arrive[i]);
	}
	for (int i = 0 ; i < n ; ++i) {
		for (int j = i ; j < n ; ++j) {
			dp2[i][j] = max(120 + (j - i + 1) * 20,140 + arrive[j] - arrive[i] - 1800);
		}
	}
	for (int i = 0 ; i < n ; ++i) {
		dp1[i] = dp2[0][i];
		for (int j = 1 ; j <= i ; ++j) {
			dp1[i] = min(dp1[i],dp2[j][i] + dp1[j - 1]);
		}
	}
	cout << dp1[n - 1] << "\n";

}
