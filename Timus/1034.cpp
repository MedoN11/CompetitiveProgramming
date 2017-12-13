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
#include <unordered_set>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;


// N queens exist
// Each row is occupied by a queen since the matrix is n * n
// swaps across rows don't make sense as they won't introduce new counts
// swaps over coloumns are what we target
// each coloumn is occupied by 1 queen
// so brute force all possible swaps in n^3
int n;
vector<pii> v;
const int maxn = 105;
int diag_left[maxn];
int diag_right[maxn];
int add(pii &p) {
	diag_left[p.first + p.second]++;
	diag_right[p.first - p.second + n]++;
	if(diag_left[p.first + p.second] > 1 || diag_right[p.first - p.second + n] > 1)
		return 1;
	return 0;
}

int remove(pii &p) {
	diag_left[p.first + p.second]--;
	diag_right[p.first - p.second + n]--;
	return 0;
}
int swap(int i,int j,int k) {
	remove(v[i]);
	remove(v[j]);
	remove(v[k]);
	pii a = v[i], b = v[j], c = v[k];
	a.second = v[j].second; b.second = v[k].second; c.second = v[i].second;
	int x = 0;
	x += add(a);
	x += add(b);
	x += add(c);
	int f = x == 0 ? 1 : 0;
	remove(a);
	remove(b);
	remove(c);
	add(v[i]);
	add(v[j]);
	add(v[k]);
	return f;
}
int main() {
	ios
	cin >> n;
	v.resize(n);
	for(int i = 0 ; i < n ; ++i) {
		cin >> v[i].first >> v[i].second;
		add(v[i]);
	}
	int ans = 0;
	for(int i = 0 ; i < n ; ++i) {
		for(int j = i + 1 ; j < n ; ++j) {
			for(int k = j + 1 ; k < n ; ++k ){
				ans += swap(i,j,k);
				ans += swap(i,k,j);
			}
		}
	}
	cout << ans << "\n";
}
