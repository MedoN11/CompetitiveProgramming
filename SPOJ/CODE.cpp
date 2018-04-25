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
#include <unordered_map>
#include<memory.h>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
typedef pair<int,int> pii;
typedef pair< long double,long double> pdd;
#define F first
#define S second
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define mp make_pair
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define for1LL(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define fornLL(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define ld long double

// Euler tour..debrujin sequence construction
// TLE CODE because time limit is so strict..optimization is constant to pass
const int maxn = 2000005;
int n;
vector<string> v;
unordered_map<string,int> st;
int cnt[maxn];
map<int,string> rev;
void bt(string &str) {
	if (sz(str) == n - 1) {
		v.pb(str);
		st[str] = sz(v) - 1;
		rev[sz(v) - 1] = str;
		return;
	}
	forn(i,10) {
		string tmp = str;
		tmp += to_string(i);
		//cerr << tmp << "\n";
		bt(tmp);
	}
}
int ind = 0;
vector<int> g[maxn];

int gb = 0;
void add(int i) {
	string s = v[i];
	string tmp = "";
	fore(i,1,sz(s) - 1) tmp += s[i];
	forn(j,10) {
		string cur = tmp;
		cur += to_string(j);
		g[i].pb(st[cur]);
		cnt[ind - 1]++;
	}

}
string tour = "";
void euler(int u) {

	while(sz(g[u]) > 0) {
		int v = g[u].back();
		g[u].pop_back();
		euler(v);

	}
	tour += rev[u][n - 2];



}
int main() {

	while (scanf("%d",&n) && n) {
		if (n == 1) {
			cout << "0123456789\n";
			continue;
		}
		v.clear();
		forn(i,maxn)g[i].clear(),cnt[i] = 0;
		string cur = "";
		bt(cur);

		REP(i,v) {
			add(i);

		}

		euler(0);
		tour += '0';
		reverse(all(tour));
		cout  << tour << "\n";
	}

//	cout << "];";

}
