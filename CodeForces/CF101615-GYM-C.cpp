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
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;;
const int maxn = 1000005;

ll ans[maxn];
ll res = 0;
ll brute(ll a,ll b) {
	for(ll i = 1 ; i <= b ; ++i) {
		for(ll j = a ; j <= b ; ++j) {
			if(j % i == 0) res += i;
		}
	}
	return res;
}
int main() {
	ios
	ll tot = 0;
	ll a,b;
	cin >> a >> b;
	memset(ans,0,sizeof(ans));
	for(ll i = 1 ; i <= 1000*1000 ; ++i) {
		for(ll j = 1LL*(a / i) * i ; j <= b ; j += 1LL*i) {
			if(j >= a && j <= b)
			{
				ans[j - a] += 1LL*i;
				if(j / i > 1000*1000) ans[j - a] += 1LL*(j / i);
			}

		}

	}
	for(int i = 0 ; i <= (b - a ) ; ++i) {
		tot += 1LL*ans[i];
	}
	cout << tot << "\n";
	//cout << brute(a,b) << "\n";


	return 0;
}
