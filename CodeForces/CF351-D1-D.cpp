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
#define F first
#define S second
#define MP make_pair
const int block = 310;
const int maxn  = 100005;
int arr[maxn];

// Adhoc processsing + MO's Algorithm
// Add and removal are complicated.Must be done in O(1), log(n) gets TLE.
struct Query {
	int L,R,ind;
	Query(int l,int r,int ind) {
		this->L = l;
		this->R = r;
		this->ind = ind;

	}
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
int toL[maxn],toR[maxn];
int n;
int currentL = 0; int currentR = -1, L,R;
int freq[maxn];
int sp[maxn];
int res[maxn];
bool bad[maxn];
int ok = 0;
int cnt = 0;
vector<int> pos[maxn];
int lft[maxn],rt[maxn],off[2][maxn];
int far_left[maxn],far_right[maxn];
const int inf = 1 << 30;
bool arth(int ind) {
	int x = arr[ind];
	if(freq[x] == 1) return 1;
	int spanL = max(currentL,lft[ind]);
	int spanR = min(currentR,rt[ind]);
	if(bad[ind]) {
		spanL = ind;
		if(spanL <= far_left[x] && far_right[x] <= spanR) {
			return 1;
		}
		spanL = max(currentL,lft[ind]);
		spanR = ind;
		if(spanL <= far_left[x] && far_right[x] <= spanR) {

			return 1;

		}
		return 0;

	}
	if(spanL <= far_left[x] && far_right[x] <= spanR) {

		return 1;

	}
	return 0;
}
void add(int ind) {
	int x = arr[ind];
	if(freq[x] == 0) ++cnt;
	far_right[x] = max(far_right[x],ind);
	far_left[x] = min(far_left[x],ind);
	freq[x]++;
	if(arth(ind)) {
		if(!sp[x]) sp[x] = 1,++ok;
	}
	else {
		if(sp[x]) {
			sp[x] = 0, --ok;
		}
	}


}
void remove(int ind) {
	int x = arr[ind];
	freq[x]--;
	if(far_right[x] == ind) {
		if(toL[ind] >= currentL)
			far_right[x] = toL[ind];
		else far_right[x] = -inf;
	}
	if(far_left[x] == ind) {
		if(toR[ind] <= currentR) {
			far_left[x] = toR[ind];
		}
		else far_left[x] = inf;
	}
	if(far_left[x] == inf && far_right[x] != -inf)
		far_left[x] = far_right[x];
	if(far_right[x] == -inf && far_left[x] != inf)
		far_right[x] = far_left[x];
	if(freq[x] == 0) {
		--cnt;
		if(sp[x]) {
			sp[x] = 0;
			--ok;
		}
	} else {
		if(lft[ind] != -1 && currentR >= lft[ind] && lft[ind] >= currentL && !sp[x]) {
			if(arth(lft[ind])) {
				sp[x] = 1;
				++ok;
			}
		}
		if(rt[ind] != n && currentL <= rt[ind] && rt[ind] <= currentR && !sp[x]) {
			if(arth(rt[ind])) {
				sp[x] = 1;
				++ok;

			}
		}
	}

}
int main() {
	scanf("%d",&n);
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d",&arr[i]);
		pos[arr[i]].pb(i);
		off[0][i] = off[1][i] =  -1;
		rt[i] = n,lft[i] = -1;
		far_left[i] = inf, far_right[i] = -inf;
		toL[i] = toR[i] = i;
	}
	for (int i = 0 ; i < maxn ; ++i) {
		vector<int> v = pos[i];

		// get left & right spans
		REP(j,v) {
			int ind = v[j];
			if(j == 0) lft[ind] = -1,toL[ind] = ind;
			else lft[ind] = v[j - 1],off[0][ind] = ind - v[j - 1],toL[ind] = v[j - 1];
			if(j == sz(v) - 1) rt[ind] = n,toR[ind] = ind;
			else rt[ind] = v[j + 1],off[1][ind] = v[j + 1] - ind,toR[ind] = v[j + 1];

		}
		for (int j = sz(v) - 2 ; j >= 0 ; --j) {
			int ind = v[j],nxt = v[j + 1];
			if(off[1][ind] == - 1 || off[1][ind] == off[1][nxt]) {
				rt[ind] = rt[nxt];
				off[1][ind] = off[1][nxt];
			}

		}
		for (int j = 1 ; j < sz(v) ; ++j) {
			int ind = v[j], prv = v[j - 1];
			if(off[0][ind] == -1 || off[0][ind] == off[0][prv]) {
				lft[ind] = lft[prv];
				off[0][ind] = off[0][prv];
			}
		}
		for (int j = 0 ; j < sz(v) ; ++j) {
			int ind = v[j];
			if(off[0][ind] == -1 || off[1][ind] == -1)
				continue;
			if(off[0][ind] != off[1][ind])
				bad[ind] = 1;
		}

	}

	int q;
	scanf("%d",&q);
	vector<Query> queries;
	for (int i = 0 ; i < q ; ++i) {
		int a,b;
		scanf("%d %d",&a,&b); --a,--b;
		queries.pb(Query(a,b,i));
	}

	sort(all(queries),MO_CMP);
	//cout << "here "<< ok << " "<< cnt << "\n";
	REP(i,queries) {
		L = queries[i].L; R = queries[i].R;
		while (currentR < R) {
			currentR++;
			add(currentR);

		}
		while (currentR > R) {
			currentR--;
			remove(currentR + 1);

		}
		while (currentL < L) {
			currentL++;
			remove(currentL - 1);


		}
		while (currentL > L) {
			currentL--;
			add(currentL);
		}

		res[queries[i].ind] = cnt + (ok == 0);


	}
	for (int i = 0 ;i < q ; ++i) {
		printf("%d\n",res[i]);
	}


}

//10
//1 4 4 2 4 1 5 6 7 8
//1
//2 6
