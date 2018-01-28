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
multiset<int> s;
map<pii,ll> mp;
int n,len,k;
int block = 0;
int arr[100005];
multiset<int> curr,out;
// Sets
// Maintain K maximums using two sets
ll tmp = 0;
void remove(int ind) {
	if(arr[ind] >= 0) {
		tmp -= arr[ind];
		return;
	}
	ll x = -arr[ind];
	if(curr.find(x) == curr.end()) {
		out.erase(out.find(x));
		tmp += x;
	} else {
		curr.erase(curr.find(x));
		tmp -= x;
		if(sz(out) > 0)  {
			curr.insert(*out.rbegin());
			tmp += *out.rbegin()*2;
			out.erase(out.find(*out.rbegin()));

		}
	}

}
void add(int ind) {
	if(arr[ind] >= 0) {
		tmp += arr[ind];
		return;
	}
	ll x = -arr[ind];
	if(sz(curr) < k) {
		curr.insert(x);
		tmp += x;
	} else {
		if(x > *curr.begin() && k) {
			tmp -= *curr.begin()*2;
			tmp += x;
			out.insert(*curr.begin());
			curr.erase(curr.begin());
			curr.insert(x);
		} else {
			out.insert(x);
			tmp -= x;
		}
	}
}
ll getBest() {
	curr.clear();
	out.clear();
	tmp = 0;
	ll ans = 0;
	for (int i = 0 ; i < n ; ++i) {

		if(i - len >= 0) {
			remove(i - len);
		}

		add(i);
		//cerr << tmp << "\n";
		if(i >= len - 1) ans = max(ans,tmp);
	}


	return ans;
}
int main() {
	scanf("%d %d",&n,&len);
	block = sqrt(n);
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	ll ans = getBest();
	for (int i = 0 ; i < n ; ++i) {
		arr[i] = -arr[i];
	}
	cout << max(ans,getBest()) << "\n";
}
