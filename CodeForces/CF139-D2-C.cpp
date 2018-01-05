
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
using namespace std;
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
bool g[10][10];
int n,k;
vector<string> v;
vector<string> rh;
bool vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
string seq[4] = {"aaaa","abab","abba","aabb"};
bool ok(string &s,string &t) {
	int i = -1,j = -1;
	int tmp = k;
	for(int ind = sz(s) - 1 ; ind >= 0; --ind) {
		if(tmp == 1 && vowel(s[ind])) {
			i = ind;
			break;
		}
		if(vowel(s[ind])) --tmp;
	}
	tmp = k;
	for(int ind = sz(t) - 1 ; ind >= 0 ; --ind) {
		if(tmp == 1 && vowel(t[ind])) {
			j = ind;
			break;
		}
		if(vowel(t[ind])) --tmp;
	}
	if(i == -1 || j == -1) return 0;
	if(sz(s) - i != sz(t) - j) return 0;
	while(i < sz(s) && j < sz(t)) {
		if(s[i] != t[j]) return 0;
		++j;
		++i;
	}
	return 1;
}
bool end1 = 0;
void go() {
	for(int i = 0 ; i < 4 ; ++i) {
		for(int j = i + 1 ; j < 4 ; ++j) {
			if(ok(v[i],v[j]))
				g[i][j] = 1;
		}
	}
//	for(int i = 0 ; i < 4 ; ++i) {
//		for(int j = i + 1 ; j < 4 ; ++j)
//			cout << g[i][j];
//		cout << "\n";
//	}
	for(int k = 0 ; k < 4 ; ++k) {
		bool ok = 1;
		for(int i = 0 ; i < 4 ; ++i) {
			for(int j = i + 1 ; j < 4 ; ++j) {
				if(seq[k][i] == seq[k][j]) ok &= g[i][j];
			}
		}
		if(ok) {
			rh.pb(seq[k]);
			return ;
		}
	}
	end1 = 1;
}

int main() {
	ios
	cin >> n >> k;

	for(int i = 0 ; i < n ; ++i) {
		v.clear();
		memset(g,0,sizeof(g));
		for(int j = 0 ; j < 4 ; ++j) {
			string s; cin >> s;
			v.pb(s);
		}
		go();
	}

	if(end1) cout << "NO\n";
	else {
		int f[4] = {0,0,0,0};
		for(int i = 0 ; i < sz(rh) ; ++i) {
			if(rh[i] == "aaaa")++f[0];
			if(rh[i] == "abab")++f[1];
			if(rh[i] == "abba")++f[2];
			if(rh[i] == "aabb")++f[3];

		}

		if(f[1] + f[2] + f[3] == 0) {
			cout << "aaaa\n";
			return 0;
		}
		for(int i = 1 ; i < 4 ; ++i) {
			for(int j = i + 1 ; j < 4 ; ++j) {
				if(f[i] && f[j])
				{
					cout << "NO\n";
					return 0;
				}
			}
		}

		for(int i = 1 ; i < 4 ; ++i) {
			if(f[i]) {
				cout << seq[i] << "\n";
				return 0;
			}
		}




	}
	//assert(false);
}
