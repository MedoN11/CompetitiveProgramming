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
typedef vector<int> VI;
using namespace std;

// adhoc + Dynamic Programming to match nodes + BFS
// Editorial is clear
const int maxn = 10005;
int n,k,l;
VI step;
bool arr[maxn];
int dis[22][maxn];
int m = 0;
const int inf = 1 << 28;
vector<int> pos;
int dp[1 << 22];
int get(int msk) {
	for(int i = 0 ; i < m ; ++i) {
		if((msk) & (1 << i))
			return i;
	}
	assert(false);
	return 0;
}
int match[22][22];
int solve(int msk) {
	if(msk == 0)
		return 0;
	int &ret = dp[msk];
	if(ret != -1)
		return ret;
	ret = inf;
	int curr = get(msk);

	for (int i = 0 ; i < m ; ++i) {
		if(curr == i)
			continue;
		if((msk & (1 << i)) && match[i][curr] != inf) {
			int nmsk = msk & ~(1 << i);
			nmsk &= ~(1 << curr);
			ret = min(ret,match[i][curr] + solve(nmsk));
		}
	}
	return ret;
}
void bfs(int ind) {
	queue<int> q;
	dis[ind][pos[ind]] = 0;
	q.push(pos[ind]);
	while(!q.empty()) {
		int v = q.front();q.pop();
		REP(j,step) {
			int c = step[j] + v;
			if(c <= n && dis[ind][c] > dis[ind][v] + 1) {
				dis[ind][c] = dis[ind][v] + 1;
				q.push(c);
			}
			c = v - step[j];
			if(c >= 0 && dis[ind][c] > dis[ind][v] + 1) {
				dis[ind][c] = dis[ind][v] + 1;
				q.push(c);
			}
		}
	}
}
int main() {

	scanf("%d %d %d",&n,&k,&l);
	memset(dp,-1,sizeof(dp));
	for(int i = 0 ; i < k ; ++i) {
		int x; scanf("%d",&x);
		arr[x] = 1;
	}
	step.resize(l);
	for (int i = 0 ; i < l ; ++i) {
		scanf("%d",&step[i]);
	}

	for(int i = 0 ; i <= n ; ++i) {
		if(arr[i] ^ arr[i + 1]) {
			++m;
			pos.pb(i);
		}
	}
	for(int i = 0 ;i < m ; ++i) {
		for(int j = 0 ; j < maxn ; ++j) dis[i][j] = inf;
		bfs(i);
	}
	for (int i  = 0 ; i < m ; ++i) {
		match[i][i] = 0;
		for(int j = i + 1 ; j < m ; ++j) {
			match[i][j] = match[j][i] = inf;
			for(int k = 0 ; k <= n ; ++k) {
				match[i][j] = min(match[i][j],dis[i][k] + dis[j][k]);
			}
			match[j][i] = match[i][j];
		}
	}

	int ans = solve((1 << m) - 1);
	if(ans == inf)
		ans = -1;
	printf("%d\n",ans);




}
