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
#include <unordered_map>
using namespace std;
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
int s,q,k;
vector<int> a,b;
int n;

// Number Theory + Math

int gcd(int a,int b) {
	if(a == 0)
		return b;
	return gcd(b % a,a);
}
bool valid(int g) {
	for(int i = 0 ; i < n ; ++i) if((a[i] % g) != b[i]) return 0;
	return 1;
}
int main()
{


	cin >> n;
	a.resize(n);
	b.resize(n);
	for(int i = 0 ; i < n ; ++i) scanf("%d",&a[i]);
	for(int j = 0 ; j < n ; ++j) scanf("%d",&b[j]);

	int g = 0;
	for(int i = 0 ; i < n ; ++i) {
		if(b[i] > a[i])
		{
			cout << "-1\n";
			return 0;
		}
		if(a[i] == b[i])
			continue;
		g = gcd(g,a[i] - b[i]);

	}
	if(g == 0) {
		bool ok = 1;
		int mx = 0;
		for(int i = 0 ; i < n ; ++i) {
			mx = max(mx,a[i]);
			ok &= a[i] == b[i];
		}

		if(ok) cout << (mx + 1) << "\n";
		else cout << "-1\n";
		return 0;
	}
	bool ok = 1;
	for(int i = 0 ; i < n ; ++i) {
		ok &= (a[i] % g) == b[i];
	}
	ll mn = g;
	if(ok) {
		mn = g;
		if(valid(1)) {
			mn = min(mn,1LL);
		}
		for(ll i = 1 ; 1LL*i * i <= g ; ++i) {
			if(g % i == 0 && valid(i)) {
				mn = min(mn,i);

			}
			if(i != 1 && valid(g / i)) {
				mn = min(mn,g/i);
			}
		}
		cout << mn << "\n";
	}
	else cout << "-1\n";


}
