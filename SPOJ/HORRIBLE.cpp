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
typedef pair<int,int> pii;
#define ios {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define REP(i, v)       for(int i=0;i<sz(v);++i)
using namespace std;
const int maxn = 1000*1000+ 10;
int lo[4*maxn];
int hi[4*maxn];
ll ans[4*maxn];
ll lazy[4*maxn];
int t;
int n,c;

void upd(int i)
{
	ans[i] = 1LL*ans[i << 1] + 1LL*lazy[i << 1] * (1LL*hi[i << 1] - lo[i << 1] + 1) + 1LL*ans[(i << 1) | 1] + 1LL*lazy[(i << 1) | 1] * 1LL*(hi[(i << 1) | 1] - 1LL*lo[(i << 1) | 1] + 1);
}
void prop(int i)
{
	lazy[i << 1] += 1LL*lazy[i];
	lazy[(i << 1) | 1] += 1LL*lazy[i];
	lazy[i] = 0;
}
void build(int ind,int l,int r)
{
	if(l > r)
		return;
	lo[ind] = l, hi[ind] = r;
	if(l == r)
	{
		ans[ind] = 0; lazy[ind] = 0;
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind << 1,l,mid);
	build((ind << 1) | 1,mid + 1,r);
	upd(ind);
}

void update(int ind,int l,int r,ll v)
{
//	if(l > r)
//		return;
	if(lo[ind] >= l && hi[ind] <= r)
	{
		lazy[ind] += 1LL*v;
		return;
	}
	if(lo[ind] > r || hi[ind] < l)
		return;
	prop(ind);
	update(ind << 1,l,r,v);
	update((ind << 1) | 1,l,r,v);
	upd(ind);

}
ll query(int ind,int l,int r)
{

	if(l > r)
		return 0LL;
 	if(lo[ind] >= l && hi[ind] <= r)
	{

		//cerr <<  ans[ind] + lazy[ind] * (1LL*hi[ind] - lo[ind] + 1) << "\n";
		return ans[ind] + lazy[ind] * (1LL*hi[ind] - lo[ind] + 1);
	}
	if(lo[ind] > r || hi[ind] < l)
		return 0;
	prop(ind);
	ll x = 0;
	x += query(ind << 1,l,r);
	x += query((ind << 1) | 1,l,r);

	upd(ind);
	return x;
}
//1
//4 2
//0 2 4 2
//1 1 4
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(lazy,0,sizeof(lazy));
		memset(ans,0,sizeof(ans));
		scanf("%d %d",&n,&c);
		build(1,0,n - 1);
		while(c--)
		{
			int tp; scanf("%d",&tp);
			if(!tp)
			{
				int l,r;
				ll v;
				scanf("%d %d %lld",&l,&r,&v);
				--l;--r;
				update(1,l,r,v);
			}
			else
			{
				int l,r; scanf("%d %d",&l,&r);
				--l; --r;
				printf("%lld\n",query(1,l,r));
			}
		}

	}
}
