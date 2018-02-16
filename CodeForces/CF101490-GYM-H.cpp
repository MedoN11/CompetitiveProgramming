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
#define time __time
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
ll n,b;
ll res = 0;
int divs[100005];
unordered_map<ll,int> mp;
int MAX_SIZE = 0;
int solve(ll x) {

	if(x == 1) return 0;
	if(x < b) return 1;
	if(mp.find(x) != mp.end()) return mp[x];
	//cerr << x << "\n";
	int ret = 1 << 25;
	for (int j = 0 ; j < MAX_SIZE ; ++j) {
		int i = divs[j];
		if(i >= x)
			break;
		if(x % i == 0) {
			//if(x / i < b) ret = min(ret, 1 + solve(i));
			ret = min(ret,1 + solve(x / i));

		}
	}
	return mp[x] = ret;

}
int ptr = 0;
void trace(ll x) {
	if(x == 1) return ;
	if(x < b) {
		res *= b;
		res += x;
		return;
	}
	//cerr << x << "\n";
	int ret = 1 << 25;
	int opt = solve(x);
	for (int j = 0 ; j < MAX_SIZE ; ++j){
		int i = divs[j];
		if(i >= x)
			break;
		if(x % i == 0) {
			ret = min(ret,1 + solve(x / i));
			if(opt == ret) {
				res *= b;
				res += i;

				trace(x / i);
				return;
			}

		}
	}
	return;
}
int main() {
//	ios
	cin >> b >> n;
	for (int i = 2 ; i < b ; ++i) {
		if(n % i == 0) divs[MAX_SIZE++] = i;
	}
	if(n == 1) {
		cout << "1\n";
		return 0;
	}
	solve(n);

	if(solve(n) == 1 << 25) {
		cout << "impossible" << "\n";
		return 0;
	}

	trace(n);

	cout << res << "\n";

}
