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
int n,s;
vector<int> v;
/*
 *  Key idea is built on Timus 1515, my solution & explanation here
 *  https://github.com/MedoN11/CompetitiveProgramming/blob/master/Timus/1515.cpp
 *  This DP uses the above idea, and bruteforces all combinations that can represent anything from 1 to N
 *  along those DP minimizes the number of coins used.
 *
 */
int dp[1001];
struct Shopping {
	int minNumber(int x, vector<int> q);
};
int solve(int sum) {
	if (sum >= s) return 0;
	int &ret = dp[sum];
	if(ret != -1)
		return ret;
	ret = 1 << 25;
	REP(i,v) {
		if(sum + 1 == v[i] || sum >= v[i]) ret = min(ret,1 + solve(sum + v[i]));
	}
	return ret;
}
int Shopping::minNumber(int x,vector<int> q) {
	v = q; s = x;

	memset(dp,-1,sizeof(dp));
	if(solve(0) == 1 << 25) return -1;
	return dp[0];
}
