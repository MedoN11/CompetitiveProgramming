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

// Two DP's. One is used as precomputation in another.
int dp[maxn][2];
string str;
int n,k;
pair<int,int> memo[maxn];
int sum[maxn];
int solve(int ind,int f) {
	if(ind == n)
		return 0;
	int &ret = dp[ind][f];
	if(ret != -1)
		return ret;
	char c = f? 'b' : 'a';
	ret = 0;
	if(str[ind] == '?') {
		ret = 1 + solve(ind + 1,!f);
	}
	else {
		if(str[ind] == c) return ret = 1 + solve(ind + 1,!f);
		else return ret = 0;
	}
	return ret;
}
int ok[maxn];
bool seen[maxn];

pair<int,int> combine(pair<int,int> p1, pair<int,int> p2) {
	if(p1.first > p2.first)
		return p1;
	if(p2.first > p1.first)
		return p2;
	if(p2.second < p1.second)
		return p2;
	return p1;
}
int get(int l,int r) {
	r = min(r,n - 1);
	if(l > r)
		return 0;
	if(l == 0)
		return sum[r];
	return sum[r] - sum[l - 1];
}
pii solve(int i){
	if(i >= n)
		return make_pair(0,0);
	if(seen[i])
		return memo[i];
	seen[i] = 1;
	pair<int,int> a;
	a.first = 0,a.second = 0;
	if(i + k - 1 < n && ok[i]) {
		a = solve(i + k);
		a.first++; a.second += get(i,i + k - 1);
	}
	pair<int,int> b = solve(i + 1);
	return memo[i] = combine(a,b);

}
int main() {
	memset(dp,-1,sizeof(dp));
	ios
	cin >> n >> str >> k;
	REP(i,str) {
		if(str[i] == '?')
			sum[i]++;
	}
	for(int i = 1 ; i < n ; ++i) {
		sum[i] += sum[i - 1];
	}
	for(int i = 0 ; i < n ; ++i) {
		if(solve(i,0) >= k) {
			//cerr << i << "\n";
			ok[i] = 1;
		}
	}
	pair<int,int> ans = solve(0);
	cout << ans.second << "\n";
}
