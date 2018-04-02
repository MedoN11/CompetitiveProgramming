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
int n;
const int maxn = 200005;
int x[maxn],y[maxn];
ll cnt[2][2][2];
int det[maxn + 1];

// Let's enumerate all vertices using shoelace
// while standing at vertex i, we can choose an ending points from all j's such that j >= 0 && j < i - 1 ( diagonal cut cannot be polygon side)
// to do so we just need to calculate simple prefix sum of the shoelace formula
// then iterate for 2^3 to handle parity
int main() {
		fi("integral.in");
		fo("integral.out");
	ios
	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		int a,b;
		cin >> a >> b;
		x[i] = a, y[i] = b;
		x[i] = abs(a), y[i] = abs(b);
		x[i] %= 2, y[i] %= 2;

	}
	y[n] = y[0],x[n] = x[0];
	ll s = (x[1] - x[0]) * (y[1] + y[0]);
	for (int i = 1 ; i < n ; ++i) {
		det[i] = s%2;
		while(det[i] < 0) det[i] += 2;
		det[i] %=2;
		s += (x[i + 1] - x[i]) * (y[i + 1] + y[i]);
	}
	cerr << s << "\n";
	if(s % 2) {
		cout << "0\n";
		return 0;
	}

	ll ways = 0;

//	cnt[x[0]][y[0]][0]++;
	for (int i = 1 ; i < n ; ++i) {
		for (int dx = 0 ; dx < 2 ; ++dx) {
			for (int dy = 0 ; dy < 2 ; ++dy) {
				for (int a = 0 ; a < 2 ; ++ a) {
					int curr = det[i] + (dx - x[i]) * (dy + y[i]);
					curr -= a;
					while(curr < 2) curr += 2;
					curr %= 2;
					if(!curr)
						ways += 1LL*cnt[dx][dy][a];
				}
			}
		}

		cnt[x[i - 1]][y[i - 1]][det[i - 1]]++;
	}
	//ways -= (n);
	cout << (ways-1) << "\n";




}
