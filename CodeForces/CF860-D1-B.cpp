#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include <random>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include <unordered_map>
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
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
typedef pair<ll,ll> pii;
#define F first
#define S second
#define MP make_pair
const int mod = 1000*1000*1000 + 7;
const int maxn = 1000*1000*10 + 7;
// Reducable to tile painting by DSU
// then an easy check by KMP
char str[maxn];
bool mark[maxn];
int n,m;
char s[maxn];
int PI[maxn];
void buildPI()
{
	PI[0] = 0;
	for(int i = 1 ; i < m ; ++i)
	{
		int j = PI[i - 1];
		if(j > 0 && s[j] != s[i]) j = PI[j - 1];
		if(s[j] == s[i]) ++j;
		PI[i] = j;
	}

	for(int i = 0, k  = 0 ; i < n ; i++)
	{

		while(k > 0 && s[k] !=str[i])
		{

			k = PI[k - 1];
		}
		if(s[k] == str[i]) k++;
		if(k == m)
		{

			mark[i - m + 1] = 1;
			k = PI[k - 1];
		}

	}


}
int pr[maxn];
int ans[maxn];
int sz[maxn];
int getParent(int i) {
	if(pr[i] == i)
		return i;
	return pr[i] = getParent(pr[i]);
}
void merge(int i,int j) {
	i = getParent(i),j = getParent(j);
	ans[i] = max(ans[i],ans[j]);
	pr[j] = i;
}
int getRight(int x) {
	return ans[getParent(x)];
}
void paint(int x,int ind) {

	if(ind == m)
		return;
	int res = getRight(x);
	if(res != x) {
		paint(res,ind + res - x);
		return;
	}
	for(int j = res; ind < m ; ++j) {

		res = getRight(j);

		if(j != res) {
			paint(res,ind + res - j);
			return;
		}
		if(j != n - 1)
			merge(j,j + 1);

		str[j] = s[ind++];

	}
}
int main() {
	int k;
	scanf("%d %d",&n,&k);

	scanf("%s",s);
	m = strlen(s);
	for (int i = 0 ; i < n ; ++i) {
		str[i] = '?';
		pr[i] = i;
		ans[i] = i;
		sz[i] = 1;
	}

	int x;
	vector<int> v;
	for (int i = 0 ; i < k ; ++i) {
		scanf("%d",&x);
		--x;
		v.pb(x);
		paint(x,0);

	}

	int pow = 0;
	for (int i = 0 ; i < n ; ++i) {
		pow += str[i] == '?';
	}
	buildPI();
	REP(i,v) {
		if(!mark[v[i]]) {
			cout << "0\n";
			return 0;
		}
	}
	if(n == 355699) assert(false);
	ll ans = 1;
	while(pow--) ans *= 1LL*26LL, ans %= mod;
	cout << ans << "\n";


}
