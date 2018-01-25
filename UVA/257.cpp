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
const ll m = 100001;
// ADHOC
//we just check palindromes of length 3, and 4 because any palindrome of larger length contains either of these as subtring, and larger palindromes makes answer worse. I think checking all palindromes should TLE,
//but didn't try. Also statement is a bit unclear, that's why I have one WA.
vector<ll> v;
typedef pair<ll,ll> pii;
struct Entry {
	string s;
	int l,r;
	Entry(string s,int l,int r) {
		this->s = s;
		this->l = l;
		this->r= r;
	}
};

bool ok(Entry &a,Entry &b) {
	if(a.s == b.s) return 0;
	string s = a.s,t = b.s;
//	cerr << s << " " << t << "\n";
	if(sz(s) < sz(t)) swap(s,t);
	bool sub = 0;
	for (int i = 0 ; i < sz(s) ; ++i) {
		if(i + sz(t) - 1 < sz(s)) {
			bool f = 1;
			for (int j = 0 ; j < sz(t) && i + sz(t) - 1 < sz(s) && f; ++j) {
				f &= s[i + j] == t[j];
			}
			if(f) return 0;
		}
	}
	return 1;
}
int main() {
	ios
	string str;
	vector<string> sol;

	while(cin >> str) {
		vector<Entry> v;
		for (int i = 1 ; i < sz(str) - 1; ++i) {
			if(str[i - 1] == str[i + 1]) {
				string tmp = "";
				tmp += str[i - 1]; tmp+= str[i] ;tmp+= str[i + 1];
				v.pb(Entry(tmp,i - 1,i + 1));

			}
		}
		for (int i = 1 ; i < sz(str) - 2 ; ++i) {
			if(str[i - 1] == str[i + 2] && str[i] == str[i + 1]) {
				string tmp = "";
				tmp+=str[i - 1] ;tmp += str[i] ;tmp+= str[i + 1] ;tmp+= str[i + 2];
				v.pb(Entry(tmp,i - 1,i + 2));
			}
		}
		int f = 0;
		REP(i,v) {
			if(f) break;
			REP(j,v) {
				if(ok(v[i],v[j])) {
					f = 1;
					break;
				}
			}
		}

		if(f){ sol.pb(str);
		cerr << str << "\n";
		}

	}
	REP(i,sol) {
		cout << sol[i] << "\n";
	}


}

