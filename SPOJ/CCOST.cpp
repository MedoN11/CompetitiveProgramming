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
typedef pair<long double,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
typedef long double ld;

// Line Sweep + BIT
struct Event {
	int type;

	int x;
	int r;
	int y1,y2;
	int ind;
	Event(int type,int x,int r,int y1,int y2,int ind)  {
		this->type = type;
		this->x = x;
		this->r = r;
		this->y1 = y1;
		this->y2 = y2;
		this->ind = ind;
	}
	bool operator <(const Event &a) const
	{
		// least x first
		if(x != a.x) return x < a.x;

		// if same x, get opening first
		 return type < a.type;


	}


};
const int maxn = 100005;
ll ans[maxn];
const int maxBIT = 1000*1000*10 + 2;
ll bit[1000*1000 * 10 + 2];
int t,n;

void add(int ind, ll r) {
	ind++;
	while(ind < maxBIT ) {
		bit[ind] += r;
		ind += ind & - ind;
	}
}

ll sum(int ind) {
	ind++;
	ll s = 0;
	while(ind > 0) {
		s += bit[ind];
		ind -= ind & - ind;
	}
	return s;
}
ll query(int l,int r) {
	return sum(r) - sum(l - 1);
}
int main() {
	scanf("%d",&t);
	while(t--) {
		vector<Event> v;
		int n;
		memset(bit,0,sizeof(bit));
		scanf("%d",&n);
		int x,y,r;
		for(int i = 0 ; i < n ; ++i) {
			scanf("%d %d %d",&x,&y,&r);
			v.pb(Event(1,x,r,y,y,-1));
		}
		int q;
		scanf("%d",&q);
		for(int i = 0 ; i < q ; ++i) {
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			v.pb(Event(0,x1,0,y1,y2,i));
			v.pb(Event(2,x2,0,y1,y2,i));

		}
		sort(all(v));
		REP(i,v) {
			Event e = v[i];
			if(e.type == 1) {
				add(e.y1,e.r);
			}
			if(e.type == 0) {
				ans[e.ind] = query(e.y1,e.y2);
			}
			if(e.type == 2) {
				ans[e.ind] = query(e.y1,e.y2) - ans[e.ind];
			}
		}
		for(int i = 0 ; i < q ; ++i) {
			printf("%lld\n",ans[i]);
		}
	}
}
