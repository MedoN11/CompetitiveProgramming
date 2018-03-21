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
string s;
//Naive O(N^2) remove every character from the front, then check if the rest form a palindrome.
//		If we do reverse(s)+"#"+s, the first position to cover largest prefix is equivalent to the bruteforce.
vector<int> z_function(string s) {
	int n = (int) s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}
int main() {
	ios
	while(cin >> s) {
		string t = "";
		for(int i = sz(s) - 1 ; i >= 0 ; --i) t += s[i];
		t += "#";
		t += s;
		vector<int> z = z_function(t);
		int ind = t.find('#');

		for (int i = ind + 1 ; i < sz(t) ; ++i) {
			if(z[i] + i == sz(t)) {
				for (int j =  i - 1 ; j > ind ; --j) s += t[j];
				cout << s << "\n";
				break;
			}
		}
	}
}
