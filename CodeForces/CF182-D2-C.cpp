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
// MO's Algorithm
//simply solve it with MO's Algorithm. The queries are simply for all i + len — 1 < n, (i,i + len — 1).
//
//We are using MO's to extract the sum of K maximum negative elements (of absolute value) using two sets.
//

struct Query {
	int L,R;
	Query(int L,int R) { this->L = L , this->R = R; }
};
bool MO_CMP(Query &a, Query &b)
{
	if(a.L/block != b.L/block) {
		return a.L/block < b.L/block;

	}
	else {
		return a.R < b.R;
	}
}
multiset<int> curr,out;
ll sum = 0;
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
ll pref[100005];
ll getBest() {
	sum = 0;
	curr.clear(),out.clear();
	mp.clear();
	vector<Query> queries;
	for (int i = 0 ; i + len - 1 < n ; ++i) {
		queries.pb(Query(i,i + len - 1));
	}
	int currentL = 0; int currentR = -1, L,R;

	sort(all(queries),MO_CMP);
	tmp = 0;
	REP(i,queries) {

		L = queries[i].L; R = queries[i].R;

		while (currentR < R) {
			currentR++;
			add(currentR);

		}
		while (currentR > R) {

			remove(currentR);
			currentR--;
		}
		while (currentL < L) {
			remove(currentL);
			currentL++;

		}
		while (currentL > L) {
			currentL--;
			add(currentL);
		}
		mp[pii(L,R)] = abs(tmp);


	}
	ll ans = -(1LL << 52);
	for (int i = 0 ; i + len - 1 < n ; ++i) {
		ll bef = 0;
		if(i > 0) bef = pref[i - 1];
		ans = max(ans,mp[pii(i,i + len - 1)]);

	}

	return ans;
}
int main() {
	scanf("%d %d",&n,&len);
	block = sqrt(n);
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d",&arr[i]);
		pref[i] = arr[i];
		if(i > 0)
			pref[i] += 1LL*pref[i - 1];
	}
	scanf("%d",&k);
	ll ans = getBest();
	for (int i = 0 ; i < n ; ++i) {
		arr[i] = -arr[i];
		pref[i] = arr[i];
		if(i > 0)
			pref[i] += 1LL*pref[i - 1];
	}
	cout << max(ans,getBest()) << "\n";
}


