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
typedef pair<ll,ll> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 101;

// Games
// Grundy calculation using dp
int n;
int dp[101][101];
vector<int> v[maxn];
int solve(int i,int j,vector<int> &v) {
	if(i == j)
		return 1;
	if(i > j || j >= sz(v))
		return 0;

	int &ret = dp[i][j];
	if(ret != -1) return ret;
	set<int> grund;
	for(int k = i ; k <= j ; ++k) {
		int curr = v[k];
		int ptr = i;
		int sub = 0;
		while(ptr <= j) {
			// move
			while(ptr <= j && v[ptr] <= curr) ++ptr;
			if(ptr <= j) {
				int st = ptr;
				while(ptr <= j && v[ptr] > curr) {
					++ptr;
				}
				if(st == ptr) ++ptr;
				sub ^= solve(st,ptr - 1,v);
			}
		}
		grund.insert(sub);
	}
	ret = 0;
	while(grund.find(ret) != grund.end()) ++ret;
	return ret;
}
vector<int> arr;
int get(int i) {
	int x = 0;
	for(int j = 0 ; j < n ; ++j) {
		if(i != j)
			x ^= arr[j];
	}
	return x;
}
int main() {
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i) {
		int len; scanf("%d",&len);
		v[i].resize(len);
		for(int j = 0 ; j < len ; ++j) {
			scanf("%d",&v[i][j]);
		}
	}
	arr.resize(n);
	int sol = 0;

	for(int i = 0 ; i < n ; ++i) {
		memset(dp,-1,sizeof(dp));
		arr[i] = solve(0,sz(v[i]) - 1,v[i]);
		sol ^= solve(0,sz(v[i]) - 1,v[i]);
	}
	if(sol) {
		cout << "G\n";
		for(int a = 0 ; a < n ; ++a) {
			memset(dp,-1,sizeof(dp));

			for(int k = 0 ; k < sz(v[a]) ; ++k) {
				int i = 0, j = sz(v[a]) - 1;
				vector<int> vr = v[a];
				int curr = vr[k];
				int ptr = i;
				int sub = 0;
				while(ptr <= j) {
					// move
					while(ptr <= j && vr[ptr] <= curr) ++ptr;

					if(ptr <= j) {
						int st = ptr;
						while(ptr <= j && vr[ptr] > curr) {
							++ptr;
						}
						if(st == ptr) ++ptr;
						sub ^= solve(st,ptr - 1,vr);
					}
				}
				if((sub ^ get(a)) == 0) {
					cout << (a + 1) <<" " <<(k + 1) << "\n";
					return 0;
				}
			}

		}

	} else {
		cout << "S\n";
	}
}
