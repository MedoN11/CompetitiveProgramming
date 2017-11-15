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

// adhoc
const int maxn = 100005;
ll pre[maxn],arr[maxn];
int n;
ll g(int i,int j) {
	ll s = pre[j] - pre[i];
	return s;
}

ll f(int i,int j){
	return 1LL*(j - i) * 1LL*(j - i) + g(i,j) * g(i,j);
}
int main() {
	scanf("%d",&n);
	for(int i = 0 ; i < n ;++i) {
		scanf("%lld",&arr[i]);
		pre[i] = arr[i];
		if(i > 0)
			pre[i] += pre[i - 1];
	}
	ll ans = 1LL << 62;
	for(int i = 0 ; i < n ; ++i) {
		//cout << i << " ";
		for(int j = i + 1 ; j < min(i + 2000,n) ; ++j) {
			ans = min(ans,f(i,j));
		}
		//cout << "\n";
	}
	cout << ans << "\n";
}
