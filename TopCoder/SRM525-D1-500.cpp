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
const int maxn = 100005;

struct  Rumor{
	int getMinimum(string s,vector<string> g);
};
int a[16];
int b[16];
int tmpa[16],tmpb[16];
vector<int> g[20];
int Rumor::getMinimum(string s,vector<string> gr) {

	int n = sz(s);
	int ans = 1 << 30;
	set<int> un_sharedA,un_sharedB;
	for(int i = 0 ; i < n ; ++i) {
		REP(j,gr[i]) {
			if(gr[i][j] == 'Y')
				g[i].pb(j);
		}
	}
	int k = 0;
	vector<int> sharedA;
	vector<int> sharedB;
	REP(i,s) {
		un_sharedA.insert(i);
		un_sharedB.insert(i);
		if(s[i] == 'Y') k++,a[i] = 1, b[i] = 1;
		else a[i] = 0,b[i] = 0;
	}
	if(k == n)
		return 0;
	for(int msk = 0; msk < (1 << n) ; ++msk) {
		int days = 0;
		un_sharedA.clear();
		un_sharedB.clear();
		REP(i,s) {
			un_sharedA.insert(i);
			un_sharedB.insert(i);
			if(s[i] == 'Y') a[i] = 1, b[i] = 1;
			else a[i] = 0,b[i] = 0;
		}
		while(1) {
			sharedA.clear();
			sharedB.clear();
			for(int i = 0 ; i < n ; ++i) tmpa[i] = a[i], tmpb[i] = b[i];

			for(set<int>::iterator it = un_sharedA.begin(); it != un_sharedA.end() ; it++) {
				int ind = *it;
				if((!a[ind]))
					continue;
				// share A first
				if(msk & (1 << ind)) {

					sharedA.pb(ind);
					REP(i,g[ind]) tmpa[g[ind][i]] = 1;

				} else {

					if(un_sharedB.find(ind) == un_sharedB.end()) {
						sharedA.pb(ind);
						REP(i,g[ind]) tmpa[g[ind][i]] = 1;
					}

				}
			}

			for(set<int>::iterator it = un_sharedB.begin(); it != un_sharedB.end() ; it++) {
				int ind = *it;
				if(!b[ind])
					continue;
				// share B first
				if((msk & (1 << ind)) == 0) {

					sharedB.pb(ind);
					REP(i,g[ind]) tmpb[g[ind][i]] = 1;

				} else {


					if(un_sharedA.find(ind) == un_sharedA.end()) {
						sharedB.pb(ind);
						REP(i,g[ind]) tmpb[g[ind][i]] = 1;
					}

				}
			}
			REP(i,sharedA) un_sharedA.erase(sharedA[i]);
			REP(i,sharedB) un_sharedB.erase(sharedB[i]);
			bool change = 0;
			int full = 0;
			for(int i = 0 ; i < n ; ++i) {
				if(a[i] != tmpa[i]) a[i] = tmpa[i],change = 1;
				if(b[i] != tmpb[i]) b[i] = tmpb[i],change = 1;
				if(a[i] == 1 && b[i] == 1) ++full;
			}
			if(!change)
				break;
			days++;
			if(full == n) {
				ans = min(ans,days);
				break;
			}

		}
	}
	return ans == (1 << 30) ? - 1 : ans;
}

int main() {
	string s;
	cin >> s;
	vector<string> v;
	int n; cin >> n;
	v.resize(n);
	for(int i = 0 ; i < n ; ++i)
		cin >> v[i];
	Rumor r;
	cout << r.getMinimum(s,v);
}
