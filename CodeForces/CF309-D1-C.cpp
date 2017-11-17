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
const int maxn = 1000*1000 + 5;

// Binary search - greedy - powers of two
// This is a tricky problem
// The first greedy attempt by sorting both and greedily assigning fails.

// Now the solution
// sort the b array
// First of all we need to notice that if in the optimal answer we fit k items, then there must exist an optimal answer with the k being a prefix of size k
// if another optimal solution does not, we just replace them, and obtain a continious sequence.

// now assume we want to check if it's possible to fit the first k items that are all powers of two
// we process all the numbers with their powers, and then iterate from large to small.
//if there is excess we throw it back to smaller power.
int cap[31];
int b[maxn];
int n,m;
int tmp[31];
ll cap_copy[31];
bool can(int ind) {
	memset(tmp,0,sizeof(tmp));
	for(int j = ind ; j >= 0; --j) tmp[b[j]]++;
	for(int i = 0 ; i < 31; ++i) cap_copy[i] = cap[i];
	for(int k = 30 ; k >= 0 ; --k) {
		if(cap_copy[k] < tmp[k])
			return 0;
		cap_copy[k] -= tmp[k];
		if(k > 0)
		cap_copy[k - 1] += 2LL * cap_copy[k];
	}
	return 1;
}
int main() {

	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < n ; ++i) {
		int x = 0;
		scanf("%d",&x);
		for(int j = 30 ; j >= 0 ; --j) {
			if(x & (1 << j)) cap[j]++;
		}
	}
	for(int i = 0 ; i < m ; ++i) {
		int x;
		scanf("%d",&x);
		b[i] = x;
	}
	sort(b,b + m);
	int lo = 0,hi = m - 1;
	int ans = -1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(can(mid))
			ans = mid, lo = mid + 1;
		else hi = mid - 1;
	}
	ans++;
	cout << ans << "\n";

}
