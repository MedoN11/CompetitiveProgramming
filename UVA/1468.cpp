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
const int maxn = 60005;
pii a,b;
int t;
// Bruteforce + Binary search + Binary indexed tree
// bruteforce on x position, then construct a difference pair, and use binary search to get the furthest one
// checking f in bs is done by a BIT
int dis(pii x,pii y){
	return abs(x.first - y.first) + abs(x.second - y.second);
}
vector<pii> v;
int n,m;
bool ok(int i,int j) {
	pii p = pii(i,j);
	int x = dis(p,a), y = dis(p,b);
	int ok = 1;
	REP(k,v) {
		int xs = dis(v[k],a),ys = dis(v[k],b);
		if(xs <= x && ys <= y)
			ok = 0;
		if(!ok)
			break;

	}
	return ok;

}

// random testing
void randomGen() {
	cout << "1" <<"\n";
	cout << "20" << " " << 10<<"\n";
	set<pii> s;
	cout << "5 5\n 9 5\n";
	for(int i = 2 ; i < 10 ; ++i) {
		int x = rand() % 20, y = rand() % 20;

		if(s.find(pii(x,y)) != s.end())
		{
			--i;
			continue;
		}
		s.insert(pii(x,y));
		cout << x << " " << y << "\n";
	}
}
// some bruteeforce to verify some ideas
int brute() {
	int good = 0;
	for(int i = 0 ; i < m ; ++i) {
		for(int j = 0 ; j < m ; ++j) {
			if(ok(i,j))
				++good;
		}
	}

	return good;


}
int bit[2*maxn];

void push(int ind,int x) {
	ind++;
	while(ind < 2*maxn) {
		bit[ind] = min(bit[ind],x);
		ind += ind & - ind;
	}
}
int query(int ind) {
	ind++;
	int s = 1 << 30;
	while(ind > 0) {
		s = min(s,bit[ind]);
		ind -= ind & - ind;
	}
	return s;
}
bool dominated(pii p) {
	int w = query(p.first);
	if(w <= p.second)
		return 1;
	return 0;
}
ll solve(pii p) {
	int s = maxn;
	int lo = 0, hi = s;
	int ans = -1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(!dominated(pii(p.first + mid,p.second + mid))) {
			ans = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	if(ans == -1)
		return 0;
	int up = min(a.second + ans,m - 1) - a.second;
	int down = a.second - max(0,a.second - ans) ;
	return down + up + 1;
}

int main() {

	scanf("%d",&t);
	while(t--) {
		fill(bit,bit + 2*maxn , 1 << 30);
		cin >> m >>n;
		scanf("%d %d",&a.first,&a.second);
		scanf("%d %d",&b.first,&b.second);

		v.resize(n);
		v[0] = a, v[1] = b;
		for (int i = 2 ; i < n ; ++i) {
			scanf("%d %d",&v[i].first,&v[i].second);
		}
		for (int i = 0 ; i < n ; ++i) {
			push(dis(a,v[i]),dis(b,v[i]));
		}
		ll ans = 0;
		for (int i = 0 ; i < m ; ++i) {
			pii p = pii(abs(a.first - i),abs(b.first - i));
			ans += 1LL*solve(p);
		}
		printf("%lld\n",ans);


	}

}





