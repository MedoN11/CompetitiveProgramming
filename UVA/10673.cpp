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
int n;
const int maxn = 100005;
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
int main()
{
	ios
	int t;
	cin >> t;
	while(t--) {
		ll n,k;
		cin >> n >> k;
		ll d1 = n / k;
		ll d2 = d1; if(n % k) ++d2;
		//cerr << d1 << " " << d2 << "\n";
		ll p,q;
		ll gc = gcd(d1,d2,p,q);
		//cerr << p << " " << q << "\n";
		cout << 1LL*p * n / gc << " " << 1LL*q * n / gc << "\n";
	}




}
