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
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
struct HexagonalSums {
    int minLength(int N);
};
// DP for values below 2000
// Meet in the middle for the rest
int dp[2000];
int solve(int s,vector<int> &v){
    if(s < 0)
    return (1 << 29);
    if(s == 0)
    return 0;
    int &ret = dp[s];
    if(ret != -1)
    return ret;
    ret  = 1 << 29;
    REP(i,v) ret = min(ret,1 + solve(s - v[i],v));
    return ret;
}
int HexagonalSums::minLength(int n ){
    
    int h = 5;
    int curr = 1;
    vector<int> v;
    while(curr <= 1000000) {
        v.pb(curr);
        if(curr == n)
        return 1;
        curr += h;
        h += 4;
    }
    if(n < 2000) {
        memset(dp,-1,sizeof(dp));
        return solve(n,v);
    }
    vector<int> s;
    REP(i,v) REP(j,v) {
        if(v[i] + v[j] == n)
        return 2;
        s.pb(v[i] + v[j]);
    }
    sort(all(s));
    REP(i,s) {
        if(n < s[i])
        break;
        vector<int>::iterator it = lower_bound(all(v),n - s[i]);
        if(it == v.end())
        continue;
        if(*it == n - s[i])
        return 3;
    }
    return 4;
    
}

