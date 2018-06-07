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
#include <unordered_map>
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
typedef pair<int,ll> pii;
#define F second.first
#define S second.second
#define MP make_pair
const int maxn = 200;
int f[maxn][maxn][maxn];
int in[maxn];
const int inf = 1 << 26;
// 3D floyd worshall
// Just replace outermost loop with the intermediate vertices
// for a query k u v, answer is stored in floyd[k][u][v]
int main() {
	int t;
	int tc = 1;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		for (int i = 0 ; i <= n ; ++i) {
			for (int j = 0 ; j <= n ; ++j) {
				for (int k = 0 ; k <= n ; ++k) {
					if (i == j) f[k][i][i] = 0;
					else
						f[k][i][j] = inf;
				}
			}
		}
		for (int i = 1 ; i <= n - 1 ; ++i) {

			for (int j = i + 1 ; j <= n ; ++j) {
				int c; scanf("%d",&c); if (c == -1) c = inf;
				f[0][i][j] = f[0][j][i] = c;
			}
		}
		int p; scanf("%d",&p);
		for (int i = 1; i <= p ; ++i) {
			scanf("%d",&in[i]);
		}
		for (int a = 1 ; a <= p ; ++a) {
			int k = in[a];
			for (int i = 1 ; i <= n ; ++i) {
				for (int j = 1 ; j <= n ; ++j) {
					f[a][i][j] = min(f[a][i][j],f[a - 1][i][j]);
					f[a][i][j] = min(f[a][i][j],f[a - 1][i][k] + f[a - 1][k][j]);
				}
			}
		}
		int q; scanf("%d",&q);
		printf("Case %d:",tc++);
		while (q--) {
			int u,v,k;
			scanf("%d %d %d",&k,&u,&v);
			if (f[k][u][v] >= inf)  {
				printf(" -1");
			}
			else {
				printf(" %d",f[k][u][v]);
			}
		}
		puts("");
	}
}
