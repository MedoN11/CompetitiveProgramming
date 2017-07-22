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
using namespace std;
const int maxn = 2000*1000+ 10;
int lo[4*maxn];
int hi[4*maxn];
ll ans[4*maxn];
ll lazy[4*maxn];
int arr[maxn];
int t;
int n,c;

inline void upd(int i)
{
	ans[i] = min(ans[i << 1] + lazy[i << 1],ans[(i << 1) | 1] + lazy[(i << 1) | 1]);
}
inline void prop(int i)
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
		ans[ind] = arr[l]; lazy[ind] = 0;
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
		return 1LL << 52;
 	if(lo[ind] >= l && hi[ind] <= r)
	{

		return ans[ind] + lazy[ind];
	}
	if(lo[ind] > r || hi[ind] < l)
		return 1LL << 52;
	prop(ind);
	ll x = min(query(ind << 1,l,r), query((ind << 1) | 1,l,r));

	upd(ind);
	return x;
}
char buf[100000];
int main()
{
	scanf("%d",&n);

		for(int i = 0 ; i < n ; ++i)
			scanf("%d",&arr[i]);
		build(1,0,n - 1);

		int c;
		scanf("%d",&c);
		gets(buf);
		int l,r;
		ll v;
		ll ans = 0;
		while(c--)
		{

			fgets(buf,sizeof(buf),stdin);
			int tp = sscanf(buf,"%d %d %lld",&l,&r,&v);
			if(tp == 2)
			{

				if(l <= r) ans = query(1,l,r);
				else ans = min(query(1,l,n - 1) , query(1,0,r));
				printf("%lld\n",ans);
			}
			else
			{


				if(l <= r) update(1,l,r,v);
				else
				{
					update(1,l, n - 1,v);
					update(1,0,r,v);
				}
			}

	}
}
