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
int n;
ll mod = 1000*1000*1000 + 7;
const int maxn = 1000005;
int gcd(int a,int b){
	if(a == 0)
		return b;
	return gcd(b % a,a);
}
// Editorial is clear
// To calculate sum(i * C(N,i)) fast
//imagine i * C(N,i) as choosing i elements then a leader for them. It's the same as choosing the leader first, so we can choose a leader in N ways then complete all the remaining ways in 2^(N-1),
ll d[maxn];
ll cnt[maxn];
ll pow2[maxn];
ll bad[maxn];
int main() {

	pow2[0] = 1;
	for(int i = 1 ; i < maxn ; ++i) {
		pow2[i] = pow2[i - 1] * 2;
		pow2[i] %= mod;
	}
	cin >> n;
	vector<int> v;
	v.resize(n);
	for(int i = 0 ; i < n ; ++i) {
		scanf("%d",&v[i]);
		cnt[v[i]]++;
	}

	for(int i = 2 ; i < maxn ; ++i) {
		for(int j = i ; j < maxn ; j += i) {
			d[i] += cnt[j];
			if(i != j) {
			  bad[j] = i;
			}

		}
	}
	ll ans = 0;

	for(int i = 2 ; i < maxn ; ++i) {
		if(d[i] == 0)
			continue;
		ans += (1LL*i*((d[i] * pow2[d[i] - 1])%mod))%mod;
		ans %= mod;
		ans -= (1LL*bad[i]* ((d[i]%mod * pow2[d[i] - 1]%mod)%mod))%mod;
		ans %= mod;
		ans += mod;
		ans %= mod;
	}
	cout << ans << "\n";
}
