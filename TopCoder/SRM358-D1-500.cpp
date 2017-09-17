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

struct BalanceScale
{
	int takeWeights(vector<int> weight);
};
typedef pair<int,int> state;

map<state,int> mp;
int goal_gcd;

int gcd(int a,int b)
{
	if(a + b == 0)
		return a + b;
	return __gcd(a,b);
}
int n;
int solve(int ind,int g)
{
	if(ind == n)
		return goal_gcd == g ? 0 : 1 << 30;
	state curr = state(ind,g);
	if(mp.find(state(curr)) != mp.end())
		return mp[curr];
}
