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
using namespace std;;

// 2D Binary indexed Tree + Query offline preprocessing
// Process the contribution of each garland for each ask operation
// then re-iterate on queries, and enumerate toggling garlands, then for each ask loop on all garland and sum contributions of on garlands
const int max_x = 2005, max_y = 2005;
int n,m,k;
bool on[2001];
ll bit2D[max_x][max_y];
int val[max_x][max_y];
vector<pii> garlands[2001];
void update(int x,int y,int c) {
	while(x < max_x) {

		int tmp_y = y;
		while(tmp_y < max_y) {
			bit2D[x][tmp_y] += 1LL*c;
			tmp_y += tmp_y & -(tmp_y);
		}
		x += x & (-x);
	}
}

ll query(int x,int y) {

	ll res = 0;
	while(x > 0) {

		int tmp_y = y;
		while(tmp_y > 0) {
			res += bit2D[x][tmp_y];
			tmp_y -= tmp_y & -(tmp_y);
		}
		x -= x & -x;
	}
	return res;
}
int naive(int x1,int y1,int x2,int y2) {
	ll res = 0;
	for(int i = x1 ; i <= x2 ; ++i) {
		for(int j = y1 ; j <= y2 ; ++j) {
			res += val[i][j];
		}
	}
	return res;
}
map<pii,ll> cont;
vector<pair<int,pair<pii,pii > > > ask;
ll solve(int x1,int y1,int x2,int y2) {
	ll res = 0;

	res+=query(x2, y2) ;
	res-=query(x1 - 1, y2);
	res-=query(x2, y1 - 1);
	res+=query(x1 - 1, y1 - 1);
	return res;
}
int main()
{
	memset(on,1,sizeof(on));
	scanf("%d %d %d",&n,&m,&k);
	for(int ind = 0 ; ind < k ; ind++) {
		int len;
		scanf("%d",&len);
		for(int i = 0 ;i  < len ; ++i) {
			int a,b,c; scanf("%d %d %d",&a,&b,&c);
			garlands[ind].pb(pii(a,b));
			val[a][b] = c;
		}
	}

	int q;
	scanf("%d",&q);
	char str[11];
	vector<pii> res;
	for(int i = 0 ; i < q ; ++i) {
		scanf("%s",str);
		int x;
		if(str[0] == 'S') {
			scanf("%d",&x); --x;
			res.pb(pii(0,x));
		}
		else {
			int x1,y1,x2,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			ask.pb(make_pair(i,make_pair(pii(x1,y1),pii(x2,y2))));
			res.pb(pii(1,i));

		}
	}

	for(int ind = 0 ; ind < k ; ++ind) {
		REP(j,garlands[ind]) {
			int x = garlands[ind][j].first, y = garlands[ind][j].second;
			update(x,y,val[x][y]);
		}
		REP(j,ask) {
			int x1 = ask[j].second.first.first, y1 = ask[j].second.first.second, x2 = ask[j].second.second.first, y2 = ask[j].second.second.second;
			cont[pii(ask[j].first,ind)] += solve(x1,y1,x2,y2);
		}
		REP(j,garlands[ind]) {
			int x = garlands[ind][j].first, y = garlands[ind][j].second;
			update(x,y,-val[x][y]);
		}
	}

	REP(i,res) {
		if(!res[i].first) {
			on[res[i].second] ^= 1;
		} else {
			ll sum = 0;
			for(int j = 0 ; j < k ; ++j) {
				if(on[j])
				sum += 1LL*cont[pii(res[i].second,j)];
			}
			printf("%lld\n",sum);
		}
	}
}
