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
#include <unordered_set>
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
int mod = 1000*1000*1000 + 7;
unordered_map<string,int> mp;
// bruteforce + unordered set/map
string get(string &s) {
	string res = "";
	for (int i = 0 ; i < sz(s) ; ++i) {
		string t = "";
		for (int j = i ; j < sz(s) ; ++j) {
			t += s[j];

			if(mp[t] == 1) {
				if(sz(t) < sz(res) || res == "") res = t;
			}
		}
	}
	return res;
}
void add(string &s) {
	unordered_set<string> seen;
	for (int i = 0 ; i < sz(s) ; ++i) {
		string t = "";
		for (int j = i ; j < sz(s) ; ++j) {
			t += s[j];
			if(seen.find(t) != seen.end())
				continue;
			seen.insert(t);
			mp[t]++;
		}
	}
}
int main() {
	ios
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0 ; i  < n ; ++i) {
		cin >> v[i];
		add(v[i]);
	}
	for (int i = 0 ; i < n ; ++i) {
		cout << get(v[i]) << "\n";
	}

}
