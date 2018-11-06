#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include <deque>
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
using namespace std;
typedef pair<long long,long long> pii;
long double a;
int n;
long double arr[1005];

/*
  Equation is H(i) = 2 * h(i-1) + 2 - h(i)
  We are given H(0), we can freely fix H(1)
  We can guess that a binary search on H(1) would give the optimal value to minimize H(n - 1)
  as they are dependent
 */
int main() {

	cout << fixed;
	cout << setprecision(2);
	while (cin >> n >> a) {
		long double lo = 0.0, hi = 1LL << 40;
		long double ans = 0.0;
		for (int r = 0 ; r < 200 ; ++r) {
			long double mid = lo + (hi - lo) / 2;

			bool can = 1;
			can &= mid >= 0;
			arr[0] = a;
			arr[1] = mid;
			for (int i = 2 ; i < n ; ++i) {
				arr[i] = arr[i - 1] * 2 + 2 - arr[i - 2];
				can &= arr[i] >= 0;
			}

			if (can) {
				ans = arr[n - 1];
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << ans << "\n";
	}

}
