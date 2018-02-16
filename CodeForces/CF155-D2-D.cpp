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
#define time __time
typedef pair<ll,ll> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 100005;
int cnt[maxn];
int sp[maxn],isPrime[maxn];
int main() {
	ios
	memset(isPrime,1,sizeof(isPrime));
	memset(sp,-1,sizeof(sp));
	for (int i = 2 ; i < maxn ; ++i) {
		if(sp[i] == -1) sp[i] = i;
		if(isPrime[i]) {
			for (int j = i << 1; j < maxn ; j += i) {
				if(sp[j] == -1) sp[j] = i;
				isPrime[j] = 0;
			}
		}
	}
	int n,m;
	cin >> n >> m;
	char c;
	int x;
	set<int> mawgod;
	while(m--) {
		cin >> c >> x;
		if(c == '+') {
			if(mawgod.find(x) != mawgod.end()) {
				cout << "Already on\n";
				continue;
			}
			int tmp = x;
			int conf = -1;
			while(tmp > 1) {
				int curr = sp[tmp];
				if(cnt[curr] != 0) {
					conf = cnt[curr];
					break;
				}
				while(tmp % curr == 0) tmp /= curr;
			}
			if(conf != -1) {
				cout << "Conflict with " <<(conf)<<"\n";
			} else {
				cout << "Success\n";
				tmp = x;
				mawgod.insert(x);

				while(tmp > 1) {
					int curr = sp[tmp];
					cnt[curr] = x;
					while(tmp % curr == 0) tmp /= curr;
				}
			}
		} else {
			if(mawgod.find(x) == mawgod.end()) {
				cout << "Already off\n";
				continue;
			}
			mawgod.erase(x);
			cout << "Success\n";
			int tmp = x;
			while(tmp > 1) {
				int curr = sp[tmp];
				cnt[curr] = 0;
				while(tmp % curr == 0) tmp /= curr;
			}
		}
	}


}
