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
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)

// Math
// Grid rotation by 45 degrees (x,y) -> (x + y, x - y)
// Check editorial for more details.
long long f(int x, int y) {
	return abs((x) / y);
}

long long solve(ll x1, ll x2, ll b) {
	if (x1 > x2)
		swap(x1, x2);
	// x2 > x1
	ll ans = 0;
	ans += x2 / b;
	if (x1 <= 0)
		ans += abs(x1) / b;
	else
		ans -= (x1 - 1) / b;
	if (x2 >= 0 && x1 <= 0) ans++;
	return ans;

}

int main() {
	long long a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	a <<= 1, b <<= 1;
	long long xr = (x1 + y1), yr = (x1 - y1);
	long long xp = (x2 + y2), yp = (x2 - y2);
	cout << max(solve(xr, xp, a), solve(yr, yp, b)) << endl;

}
