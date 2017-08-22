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
typedef pair<int,ll> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
const int maxn = 100005;
int n,q;
int arr[maxn];
vector<int> tree[4*maxn];
int lo[4*maxn],hi[4*maxn];


// Build merge sort tree
// Binary search the answer by reversing the problem
// An element is at least kth if it's greater than or equal to k elements
// binary search can be applied
void merge(int ind)
{
	vector<int> L = tree[ind << 1], R = tree[(ind << 1) + 1];
	int a = 0, b = 0;
	while(a < sz(L) && b < sz(R))
	{
		if(L[a] <= R[b]) tree[ind].pb(L[a++]);
		else tree[ind].pb(R[b++]);
	}
	while(a < sz(L)) tree[ind].pb(L[a++]);
	while(b < sz(R)) tree[ind].pb(R[b++]);
}
void build(int ind,int l,int r)
{
	lo[ind] = l, hi[ind] = r;
	if(l == r)
	{
		tree[ind].pb(arr[l]);
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind << 1,l,mid);
	build((ind << 1) + 1,mid + 1,r);
	merge(ind);
}
int query(int ind,int i,int j,int num)
{
	if(i > hi[ind] || j < lo[ind])
		return 0;
	if(lo[ind] >= i && hi[ind] <= j)
	{
		// full cover
		return upper_bound(all(tree[ind]),num) - tree[ind].begin();
	}
	return query(ind << 1,i,j,num) + query((ind << 1) + 1,i,j,num);

}
int main()
{
	scanf("%d %d",&n,&q);


	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&arr[i]);

	int i,j,k;
	build(1,0, n - 1);
	sort(arr, arr + n);
	while(q--)
	{
		scanf("%d %d %d",&i,&j,&k);
		--i,--j;
		int lo = 0, hi = n - 1;
		int ans = 0;
		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			if(query(1,i,j,arr[mid]) >= k)
				ans = arr[mid],hi = mid - 1;
			else lo = mid + 1;
		}
		printf("%d\n",ans);

	}

}

