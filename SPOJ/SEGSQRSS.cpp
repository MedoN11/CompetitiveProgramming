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
typedef long long ll;
const int maxn = 100005;
typedef pair<int,int> pii;
int lo[4*maxn];
int hi[4*maxn];
ll sum[4*maxn];
ll sum_sq[4*maxn];
ll lazySum[4*maxn];
ll lazyRes[4*maxn];
const int emp = -10000;

pair<ll,ll> calc(int ind)
{

	ll tmpSum = 0;
	ll tmpSq = 0;
	tmpSum = sum[ind];
	tmpSq = sum_sq[ind];
	if(lo[ind] == hi[ind])
	{
		if(lazyRes[ind] != emp)
			tmpSum = lazyRes[ind];
		tmpSum += lazySum[ind];
		return make_pair(tmpSum,tmpSum*tmpSum);
	}
	if(lazyRes[ind] != emp)
	{
		tmpSum = 1LL*(hi[ind] - lo[ind] + 1) * lazyRes[ind];
		tmpSq = 1LL*(hi[ind] - lo[ind] + 1) * lazyRes[ind] * lazyRes[ind];
	}


	//cerr << tmpSq << " " << tmpSum << "\n";
	tmpSq += 1LL*(hi[ind] - lo[ind] + 1) * (lazySum[ind] * lazySum[ind]);
	//cerr << tmpSq << "\n";
	tmpSq += 1LL*(hi[ind] - lo[ind] + 1) * 2 * lazySum[ind];
	//cerr << tmpSq << "\n";

	tmpSum += 1LL*lazySum[ind] * (hi[ind] - lo[ind] + 1);
	return make_pair(tmpSum,tmpSq);
}
void upd(int ind)
{
	sum[ind] = calc(ind << 1).first + calc((ind << 1) | 1).first;
	sum_sq[ind] = calc(ind << 1).second + calc((ind << 1) | 1).second;

}

void prop(int ind)
{
	if(lo[ind] == hi[ind])
	{
		sum[ind] = calc(ind).first,sum_sq[ind] = calc(ind).second;
		lazyRes[ind] = emp;
		lazySum[ind] = 0;
		return;
	}
	if(lazyRes[ind] != emp)
	{
		lazyRes[ind << 1] = lazyRes[ind];
		lazySum[ind << 1] = 0;
		lazyRes[(ind << 1) | 1] = lazyRes[ind];
		lazySum[(ind << 1) | 1] = 0;
		lazyRes[ind] = emp;
	}
	lazySum[ind << 1] += lazySum[ind];
	lazySum[(ind << 1) | 1] += lazySum[ind];
	lazySum[ind] = 0;
}
void build(int ind,int l,int r)
{
	lo[ind] = l,hi[ind] = r;
	if(l == r)
	{
		sum[ind] = 0;
		sum_sq[ind] = 0;
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind << 1,l,mid);
	build((ind << 1) | 1,mid + 1,r);
	upd(ind);
}

void updateSet(int ind,int l,int r,int v)
{
	if(lo[ind] > r || hi[ind] < l)
		return;

	if(lo[ind] >= l && hi[ind] <= r)
	{
		lazyRes[ind] = v;
		lazySum[ind] = 0;
		return;
	}
	prop(ind);
	updateSet((ind << 1),l,r,v);
	updateSet((ind << 1) | 1,l,r,v);
	upd(ind);
}

void updateSum(int ind,int l,int r,int s)
{
	if(lo[ind] > r || hi[ind] < l)
		return;

	if(lo[ind] >= l && hi[ind] <= r)
	{
		lazySum[ind] += s;
		return;
	}
	prop(ind);
	updateSum((ind << 1),l,r,s);
	updateSum((ind << 1) | 1,l,r,s);
	upd(ind);
}

ll query(int ind,int l,int r)
{
	if(lo[ind] > r || hi[ind] < l)
		return 0;

	if(lo[ind] >= l && hi[ind] <= r)
	{
		return lazySum[ind] != 0 || lazyRes[ind] != emp ? calc(ind).second : sum_sq[ind];
	}
	prop(ind);
	ll s = query(ind << 1,l,r) + query((ind << 1) | 1,l,r);
	upd(ind);
	return s;
}
int t;
int n,q;
int main()
{
//	lazySum[1] = 4;
//	lazyRes[1] = 2;
//	lo[1] = 1, hi[1] = 4;
//	cout << calc(1).second << "\n";
	scanf("%d",&t);
	int tp,l,r;
	int tc = 1;
	while(t--)
	{
		scanf("%d %d",&n,&q);
		build(1,0,n - 1);
		for(int i = 0 ; i < 4*maxn ; ++i)
			lazyRes[i] = emp;
		for(int i = 0 ; i < n ; ++i)
		{
			int x; scanf("%d",&x);
			updateSet(1,i,i,x);
		}
		int v;
		printf("Case %d:\n",tc++);
		while(q--)
		{
			scanf("%d %d %d",&tp,&l,&r);
			--l,--r;
			if(tp == 2)
			{
				printf("%lld\n",query(1,l,r));
			}
			if(tp == 0)
			{
				scanf("%d",&v);
				updateSet(1,l,r,v);
			}
			if(tp == 1)
			{
				scanf("%d",&v);
				updateSum(1,l,r,v);
			}
		}


	}


}
