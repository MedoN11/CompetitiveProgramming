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
const int maxn = 500001;
int lo[4*maxn],hi[4*maxn];
int arr[maxn];
const ll inf = (1LL << 32);

struct Node
{
	ll sum,max_prefix_sum,max_suffix_sum,res;
	Node() {}
	Node(ll sum,ll max_prefix_sum,ll max_suffix_sum,ll res)
	{
		this->sum = sum;
		this->max_prefix_sum = max_prefix_sum;
		this->max_suffix_sum = max_suffix_sum;
		this->res = res;
	}
};
Node ans[4*maxn];

Node merge(Node &a, Node &b)
{
	Node ans;
	ans.sum = a.sum + b.sum;
	ans.max_prefix_sum = max(a.max_prefix_sum,a.sum + b.max_prefix_sum);
	ans.max_suffix_sum = max(b.max_suffix_sum,b.sum + a.max_suffix_sum);
	ans.res = max(a.res,b.res);
	ans.res = max(ans.res,a.max_suffix_sum + b.max_prefix_sum);
	ans.res = max(ans.res,a.max_prefix_sum);
	ans.res = max(ans.res,b.max_prefix_sum);
	ans.res = max(ans.res,a.max_suffix_sum);
	ans.res = max(ans.res,b.max_suffix_sum);
	ans.res = max(ans.res,a.sum);
	ans.res = max(ans.res,b.sum);
	ans.res = max(ans.res,ans.max_prefix_sum);
	ans.res = max(ans.res,ans.max_suffix_sum);
	ans.res = max(ans.res,ans.sum);
	return ans;
}

inline void upd(int ind)
{
	ans[ind] = merge(ans[ind << 1],ans[(ind << 1) | 1]);
}

void build(int ind,int l,int r)
{
	if(l > r)
		return;
	lo[ind] = l,hi[ind] = r;
	if(l == r)
	{
		ans[ind] = Node(arr[l],arr[l],arr[l],arr[l]);
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind << 1,l,mid);
	build((ind << 1) | 1,mid + 1,r);
	upd(ind);
}

void update(int ind,int p,int v)
{
	if(lo[ind] > p || hi[ind] < p)
		return;
	if(lo[ind] == p && hi[ind] == p)
	{
		ans[ind] = Node(v,v,v,v);
		return;
	}
	update(ind << 1,p,v);
	update((ind << 1) | 1,p,v);
	upd(ind);
}
Node query(int ind,int l,int r)
{

	if(l > hi[ind] || r < lo[ind])
		return Node(-inf,-inf,-inf,-inf);

	if(l <= lo[ind] && r >= hi[ind])
		return ans[ind];

	Node a = query(ind << 1,l,r);
	Node b = query((ind << 1) | 1,l,r);
	return merge(a,b);
}

int n,q;
int main()
{
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&arr[i]);
	build(1,0,n - 1);
	scanf("%d",&q);
	while(q--)
	{
		int tp,l,r;
		scanf("%d %d %d",&tp,&l,&r);
		if(!tp)
			--l,update(1,l,r);
		else --l,--r,printf("%lld\n",query(1,l,r).res);
	}
}


