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
int t;
string s;
// Greedy
int main() {
	ios
	cin >> t;
	while(t--) {

		cin >> s;
		int n = sz(s);
		string tmp = "";
		int msk = 0;
		for (int i = 0 ; i < n ; ++i) msk ^= (1 << (s[i]-'0'));
		bool done = false;
		for (int i = 0 ; i < n - 2 ; ++i) tmp.pb('9');
		for (int i = n - 1 ; i >= 0 && !done ; --i) {
			msk ^= (1 << (s[i]-'0'));
			if(s[i] != '0') {
				for (char c = s[i] - 1; c >= '0' && !done ; --c) {
					if(i == 0 && c == '0')
						continue;
					int nmsk = (msk) ^ (1 << (c-'0'));
					int must = __builtin_popcount(nmsk);
					int has = n - i - 1;
					if(must <= has) {


						if(must % 2 != has % 2)
							continue;

						done = true;
						for (int j = 0 ; j < i ; ++j)
							cout << s[j];
						cout << c;
						for (int j = 0 ; j < has - must ; ++j)
							cout << 9;
						for (int j = 9 ; j >= 0 ; --j) {
							if(nmsk & (1 << j))
								cout << j;
						}
						break;
					}
				}
			}


		}
		if (!done) {
			cout << tmp;
		}
		cout << "\n";
	}

}
