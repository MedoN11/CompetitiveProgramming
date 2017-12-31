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
using namespace std;;

// group into large and small groups
// (smart) bruteforce? or maybe some sqrt decomp variation
int n,m,q;
int magic = 300;
const int maxn = 100005;
vector<int> sets[maxn];
ll arr[maxn];
vector<pii> bigs;
int mp[maxn];
vector<ll> inc[1000];
ll delta[1000];
ll sum[1000];


int main() {
	scanf("%d %d %d",&n,&m,&q);
	for (int i = 0 ; i < n ; ++i)
		scanf("%lld",&arr[i]);
	int big = 0, sz = -1;
	for(int j = 0 ; j < m ; ++j) {
		int len;
		scanf("%d",&len);
		if(len > sz) {
			sz = len;
			big = j;
		}
		int nxt;
		for(int k = 0 ; k < len ; ++k) {
			scanf("%d",&nxt);
			--nxt;
			sets[j].pb(nxt);
		}
		sort(all(sets[j]));
		bigs.pb(pii(-len,j));
	}
	char c;
	int targ,by;
	if(m < magic - 1) {
		for(int i = 0 ; i < magic ; ++i) inc[i].resize(m);
		for(int i = 0 ; i < m ; ++i) {
			REP(j,sets[i]) {
				sum[i] += arr[sets[i][j]];
				for(int k = 0 ; k < m ; ++k) {
					vector<int>::iterator it = lower_bound(all(sets[k]),sets[i][j]);
					if(it == sets[k].end() || *it != sets[i][j])
						continue;
					inc[i][k]++;
				}
			}
		}

		while(q--) {
			scanf(" %c %d",&c,&targ);

			if(c == '?') {
				--targ;
				printf("%lld\n",sum[targ]);
			} else {
				scanf("%d",&by);

				--targ;
				for(int i = 0 ; i < m ; ++i) {
					sum[i] += 1LL*inc[targ][i] * by;
				}
			}
		}


		return 0;
	} else {
		sort(all(bigs));

		vector<int> magic_v;

		for(int i = 0 ; i < magic ; ++i) {
			magic_v.pb(bigs[i].second);
		}

		sort(all(magic_v));

		for(int i = 0 ; i < magic ; ++i) mp[magic_v[i]] = i,inc[i].resize(magic);
		for(int i = 0 ; i < magic ; ++i) {
			REP(j,sets[magic_v[i]]) {
				sum[i] += arr[sets[magic_v[i]][j]];
				for(int k = 0 ; k < magic ; ++k) {
					vector<int>::iterator it = lower_bound(all(sets[magic_v[k]]),sets[magic_v[i]][j]);
					if(it == sets[magic_v[k]].end() || *it != sets[magic_v[i]][j])
						continue;
					inc[i][k]++;
				}
			}
		}
		while(q--) {
			scanf(" %c %d",&c,&targ);
			--targ;
			if(c == '?') {

				vector<int>::iterator it = lower_bound(all(magic_v),targ);
				if(it != magic_v.end() && *it == targ) printf("%lld\n",sum[mp[targ]]);
				else {
					ll s = 0;
					for(int i = 0 ; i < sz(sets[targ]) ; ++i) {
						s += arr[sets[targ][i]];
						// magic iteration
						for(int j = 0 ; j < magic ; ++j)
						{
							vector<int>::iterator it = lower_bound(all(sets[magic_v[j]]),sets[targ][i]);
							if(it != sets[magic_v[j]].end() && *it == sets[targ][i]) s += delta[j];

						}
					}
					printf("%lld\n",s);
				}
			} else {
				scanf("%d",&by);
				vector<int>::iterator it = lower_bound(all(magic_v),targ);
				if(it != magic_v.end() && *it == targ) {
					for(int i = 0 ; i < magic ; ++i) {
						sum[i] += 1LL*inc[mp[targ]][i] * by;
					}
					delta[mp[targ]] += by;
				} else {
					REP(i,sets[targ]) {
						arr[sets[targ][i]] += by;
						// magic iteration
						for(int j = 0 ; j < magic ; ++j) {
							vector<int>::iterator it = lower_bound(all(sets[magic_v[j]]),sets[targ][i]);
							if(it == sets[magic_v[j]].end() || *it != sets[targ][i])
								continue;
							sum[j] += by;
						}
					}
				}

			}
		}
	}


}
