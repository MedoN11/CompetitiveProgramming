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
typedef pair<ll,ll> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 100005;
string a,b;
int dp[maxn][4];
int PI[maxn];
int n,m;
bool mark[maxn];
vector<pii> buildPI(string &main,string &pat)
											{


	vector<pii> v;
	int m = pat.size();
	PI[0] = 0;
	for(int i = 1 ; i < m ; ++i)
	{
		int j = PI[i - 1];
		if(j > 0 && pat[j] != pat[i]) j = PI[j - 1];
		if(pat[j] == pat[i]) ++j;
		PI[i] = j;
	}

	int n = main.size();
	for(int i = 0, k  = 0 ; i < n ; i++)
	{

		while(k > 0 && pat[k] != main[i])
		{

			k = PI[k - 1];
		}
		if(pat[k] == main[i]) k++;
		if(k == m)
		{
			v.pb(pii(i - m + 1,i));
			mark[i - m + 1] = 1;
			k = PI[k - 1];
		}

	}

	return v;
}
int solve(int ind,int f) {
	if(ind == sz(a)) {
		return f == 2;
	}
	int &ret = dp[ind][f];
	if(ret != -1)
		return ret;
	ret = f == 2;
	// skip
	if(f == 3) {
		// continue skipping
		ret += solve(ind + 1,f);
		// start new
		ret += solve(ind,1);
	}
	// matched
	if(f == 2) {
		// keep going
		ret += solve(ind + 1,f);
		// skip
		ret += solve(ind,3);
	}
	if(f == 1) {
		if(mark[ind]) {
			ret += solve(ind + m,2);
		}
		else ret += solve(ind + 1,f);
	}
	return ret;
}
int main() {
	ios
	cin >> a >> b;
	n = sz(a),m=sz(b);
	buildPI(a,b);
	memset(dp,-1,sizeof(dp));
	cout << solve(0,3) << "\n";
}
