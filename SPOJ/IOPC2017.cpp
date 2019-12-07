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
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
const int maxn = 100005;
int lo[4][4 * maxn], hi[4][4 * maxn], ans[4][4 * maxn], lazy[4][4 * maxn];
#define ios std::ios_base::sync_with_stdio(false);

// DS + inclusion exclusion.
// Solve for each dimension independently.
// formula is dimension with odd number of greens.
// Decent explanations can be found online.
inline void prop(int tr, int ind) {
	if (lazy[tr][ind]) {

		ans[tr][ind] = (hi[tr][ind] - lo[tr][ind] + 1) - ans[tr][ind];
		if (lo[tr][ind] != hi[tr][ind]) {
			lazy[tr][ind * 2] ^= 1;
			lazy[tr][ind * 2 + 1] ^= 1;
		}

		lazy[tr][ind] = 0;
	}
}

inline void merge(int tr, int ind) {
	ans[tr][ind] = ans[tr][ind * 2] + ans[tr][ind * 2 + 1];
}

void build(int tr, int ind, int l, int r) {
	lo[tr][ind] = l, hi[tr][ind] = r;
	if (l == r) {
		ans[tr][ind] = 0;
		lazy[tr][ind] = 0;
		return;
	}
	int m = (l + r) / 2;
	build(tr, ind * 2, l, m);
	build(tr, ind * 2 + 1, m + 1, r);
	merge(tr, ind);
}

void update(int tr, int ind, int l, int r) {
	prop(tr, ind);
	//cerr << lo[tr][ind] << " " << hi[tr][ind] << endl;
	if (lo[tr][ind] > r || l > hi[tr][ind])
		return;
	if (l <= lo[tr][ind] && hi[tr][ind] <= r) {
		// upd child
		// leaf
		//cerr << lo[tr][ind] <<" "<<hi[tr][ind] << endl;
		// flip
		ans[tr][ind] = (hi[tr][ind] - lo[tr][ind] + 1) - ans[tr][ind];
		if (lo[tr][ind] != hi[tr][ind]) {
			lazy[tr][ind * 2] ^= 1;
			lazy[tr][ind * 2 + 1] ^= 1;
		}
		return;
	}
	//cerr << "oo" << endl;
	update(tr, ind * 2, l, r);
	update(tr, ind * 2 + 1, l, r);
	merge(tr, ind);
}

int query(int tr, int ind, int l, int r) {
	prop(tr, ind);
	if (lo[tr][ind] > r || l > hi[tr][ind])
		return 0;
	if (l <= lo[tr][ind] && r >= hi[tr][ind]) {
		return ans[tr][ind];
	}
	int res = query(tr, ind * 2, l, r) + query(tr, ind * 2 + 1, l, r);
	merge(tr, ind);
	return res;
}
int s[3][10005];
void updateSlow(int tr, int l, int r) {
	for (int i = l; i <= r; ++i) {
		s[tr][i] ^= 1;
	}
}

int querySlow(int tr, int l, int r) {
	int x = 0;
	for (int i = l; i <= r; ++i)
		x += s[tr][i];
	return x;
}
// 37088

int main() {
	ios;
	int t;
	cin >> t;
	while (t--) {
		memset(lazy,0,sizeof(lazy));
		memset(ans,0,sizeof(ans));
		memset(s,0,sizeof(s));
		int nx, ny, nz, q;
		cin >> nx >> ny >> nz >> q;
		//cerr << max(nx,max(ny,nz)) - 1 << endl;
		for (int i = 0; i <= 2; ++i) build(i,1,0, max(nx,max(ny,nz)) - 1);
		while (q--) {
			int tp; cin >> tp;
			if (tp <= 2) {
				int i,j; cin >> i >> j;
				update(tp,1,i,j);
				//updateSlow(tp,i,j);
			} else {
				// query
				int x1,x2,y1,y2,z1,z2;
				cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
				int rx = query(0,1,x1,x2),
				ry = query(1,1,y1,y2),
				rz = query(2,1,z1,z2);
//				int rx = querySlow(0,x1,x2),
//				ry = querySlow(1,y1,y2),
//				rz = querySlow(2,z1,z2);
				int gx = (x2 - x1 + 1) - rx,
				gy = (y2 - y1 + 1) - ry,
				gz = (z2 - z1 + 1) - rz;
				long long ans = 0;
				//cerr << rx << " " << ry << " " << rz << endl;
				//cerr << gx << " " << gy << " " << gz << endl;
// all red

				ans += 1ll*rx * ry * rz;
//				// 2 red
//				// (x,y)
//				ans += rx * ry * gz;
//				// (x,z)
//				ans += rx * rz * gy;
//				// (y,z)
//				ans += gx * rz * ry;

// 1 red

				// x
				ans += 1ll*rx * gy * gz;
				// y
				ans += 1ll*gx * ry * gz;
				// z
				ans += 1ll*gx * gy * rz;

				// print
				cout << ans << "\n";
			}
		}

	}
}
