
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
const int maxn = 1e7 + 1;

// Dynamic Programming
// Segment Erasing
struct MailArchiving {
	int minSelections(vector<string> v);
};
map<string,int> mp;
vector<int> v;
int dp[51][51];
int solve(int l,int r) {
	if(r > l)
		return 0;
	if(l == r) return 1;
	int &ret = dp[l][r];
	if(ret != -1)
		return ret;
	ret = 1 << 30;
	ret = min(ret,1 + solve(l + 1,r));
	for (int i = l + 1 ; i <= r ; ++i) {
		if(v[l] == v[i]) {
			ret = min(ret,solve(i,r) + solve(l + 1,i - 1));
		}
	}
	return ret;

}
int MailArchiving::minSelections(vector<string> q) {
	memset(dp,-1,sizeof(dp));
	int ind = 0;
	REP(i,q) {
		string s = q[i];
		if(mp.find(s) == mp.end())
			mp[s] = ind++;
		v[i] = mp[s];

	}
	return solve(0,sz(v) - 1);
}
