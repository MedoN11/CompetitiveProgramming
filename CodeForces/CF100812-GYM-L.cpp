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
// Math
// Extended Euclid + LCM
//Non standard Euclid problem.
//Basically problem can be simplfied to solving diophantine equation ax + by = 1 where a and b are given. This is only possible ofc if gcd(a,b) == 1, if so we solve by euclid to get coefs..otherwise answer is lcm(a,b) in this problem.

ll gcd(ll a, ll b)
{
	if(a == 0 || b == 0)
		return  a + b;
	return __gcd(a,b);
}
ll lcm(ll a , ll b)
{
	return a * (b/gcd(a,b));
}

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll solve(ll n, ll m)
{
	ll x,y;
	ll g = gcd(n,m,x,y);
	if(x == 0 || y == 0)
		return 2;
	return 1LL*max(1LL*abs(x) * n,1LL*abs(y) * m);
}
int main()
{
	ios
	ll n,m;
	cin >> n >> m;
	if(n < m) swap(n,m);
	ll bound = lcm(n,m);
	if(gcd(n,m) == 1)
	{
		bound = min(bound,solve(n,m));
		bound = min(bound,solve(m,n));
	}
	cout << bound << "\n";
}
