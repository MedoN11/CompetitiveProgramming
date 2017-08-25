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
typedef pair<int,ll> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
const int maxn = 1000005;
vector<int> v;
int n,k;
int nxt[maxn];
int dp[maxn];

// DP + Binary search

// sort all the elements, then for each element if we choose the current element we calculate first allowed element to take
// then enumerate all possible groups in ascending order and take max using dp
int solve(int ind)
{
	if(ind == n)
		return 0;
	int &ret = dp[ind];
	if(ret != -1)
		return ret;
	ret = solve(ind + 1);
	ret = max(ret,solve(nxt[ind]) + 1);
	return ret;
}
int main()
{
	scanf("%d %d",&n,&k);
	int a;
	for(int i = 0 ; i < n;  ++i )
	{
		scanf("%d",&a);
		v.pb(a);
		nxt[i] = n; dp[i] = -1;
	}
	sort(all(v));
	for(int i = 0 ; i < n ; ++i)
	{
		vector<int>::iterator it = lower_bound(all(v),v[i] + k);
		if(it == v.end())
			continue;
		nxt[i] = it - v.begin(); if(nxt[i] == i) ++nxt[i];
	}
	printf("%d\n",solve(0));




}

