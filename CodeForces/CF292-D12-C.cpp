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
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;

// implementation
// max size of string is 12, so if n >= 7, answer is indeed zero
int ok[10];
string s[4];
string curr[256];
bool valid(string &s) {
	REP(i,s) if(!ok[s[i] - '0']) return 0;
	return 1;
}
bool mark[11];
bool check() {
	memset(mark,0,sizeof(mark));
	string all = s[0] + s[1] + s[2] + s[3];

	for(int i = 0 ; i < sz(all) / 2 ; ++i) {
		if(all[i] != all[sz(all) - i - 1])
			return 0;
	}

	REP(i,all) {
		mark[all[i] - '0'] = 1;
	}
	for(int i = 0 ; i < 10 ; ++i) {
		if(mark[i] && !ok[i]) return 0;
		if(ok[i] && !mark[i]) return 0;
	}
	return 1;
}
bool skip[256];
int n;
int main() {
	ios
	cin >> n;
	if(n >= 7) {
		cout << "0\n";
		return 0;
	}
	for(int i = 0 ; i < n ; ++i) {
		int a;
		cin >> a;
		ok[a] = 1;
	}
	for(int i = 0 ; i < 256 ; ++i) {
		curr[i] = to_string(i);
		if(!valid(curr[i])) skip[i] = 1;
	}
	vector<string> sol;
	for(int i = 0 ; i < 256 ; ++i) {
		if(skip[i])
			continue;
		for(int j = 0 ; j < 256 ; ++j) {
			if(skip[j])
				continue;
			for(int k = 0 ; k < 256 ; ++k) {
				if(skip[k])
					continue;
				s[0] = curr[i],s[1] = curr[j],s[2] = curr[k];
				string all = s[0] + s[1] + s[2];


				for(int len = 1 ; len <= 3 ; ++len) {
					int st = len, en = sz(all) - 1;
					bool bad = 0;
					while(st <= en && !bad) {
						if(all[st] != all[en])
							bad = 1;
						st++,en--;
					}
					if(bad)
						continue;
					s[3] = "";
					int tmp = len;
					st = 0;
					while(tmp--) {
						s[3] = all[st++] + s[3];
					}
					if(s[3][0] == '0' && sz(s[3]) > 1)
						continue;
					stringstream ss(s[3]);
					int x;
					ss >> x;
					if(x < 256) {
						if(check()) {
							sol.pb(s[0]+"."+s[1]+"."+s[2]+"."+s[3]);
						}
					}
				}
			}
		}
	}
	cout << sz(sol) << "\n";
	REP(i,sol)
	cout << sol[i] << "\n";
}
