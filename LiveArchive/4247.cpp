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
const int maxn = 100005;
ll inf = (ll)(1e18);
//Backtracking..can't prove it runs in time.
bool vis[630][630];
// n & s??
char dir[4] = {'E','N','S','W'};
int dx[4]  = {0,-1,1,0};
int dy[4]  = {1,0,0,-1};
int n,m;
int r;
int global = 0;
int cur = 0;
bool valid(int i,int j) {
	return i >= 0 && j >= 0 && j < m && i < n && !vis[i][j];
}
int res = 0;
void solve(int i,int j,int k) {
	if(global == n * m - r)
		return;
	++cur;
	res = max(res,cur);
	vis[i][j] = 1;
	int newI = i + dx[k], newJ = j + dy[k];
	if(!valid(newI,newJ)) {
		for (int k = 0 ; k < 4 ; ++k) {
			int xc = i+dx[k],yc = j+dy[k];
			if(valid(xc,yc)) {
				solve(xc,yc,k);
			}
		}
	} else {
		solve(newI,newJ,k);
	}

	--cur;

	vis[i][j] = 0;
}
int main() {
	int tc = 1;
	while(scanf("%d %d",&n,&m) && n) {

		memset(vis,0,sizeof(vis));
		scanf("%d",&r);
		for (int i = 0 ; i < r ; ++i) {
			int x,y;
			scanf("%d %d",&x,&y);
			vis[x][y] = 1;
		}
		global = 0;
		int ans = 0;
		int x = -1 ,y = -1;
		char d;
		for (int i = 0 ; i < n; ++i) {
			for (int j = 0 ; j  < m ; ++j) {
				if(!vis[i][j]) {
					for (int k = 0 ; k < 4 ; ++k) {

						int xc = dx[k] + i, yc = dy[k] + j;
						if(!valid(xc,yc))
							continue;
						res = 0;
						solve(i,j,k);
						//cerr << i << " " << j << " " << curr <<" "<<dir[k]<< "\n";
						if(ans < res) {
							ans = res;
							x = i , y = j;
							d = dir[k];
						}
					}

				}
			}
		}
		printf("Case %d: %d %d %d %c\n",tc++,ans,x,y,d);
	}

}
