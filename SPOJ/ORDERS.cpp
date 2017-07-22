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

const int maxn = 200005;

int t;
int n;
int arr[maxn];
int sum[4*maxn],lo[4*maxn],hi[4*maxn];

void build(int ind,int l,int r)
{
	lo[ind] = l,hi[ind] = r;
	if(l == r)
	{
		sum[ind] = 1;
		return;
	}
	int mid = l + (r - l) / 2;
	build(((ind << 1)),l,mid);
	build((ind << 1) | 1,mid + 1,r);
	sum[ind] = sum[ind << 1] + sum[(ind << 1) | 1];
}

void update(int ind,int p = 0)
{
	if(lo[ind] > p || p > hi[ind])
		return;
	if(lo[ind] == hi[ind] && p == lo[ind])
	{
		sum[ind] = 0;
		return;
	}
	update((ind << 1),p);
	update((ind << 1) | 1,p);
	sum[ind] = sum[ind << 1] + sum[(ind << 1) | 1];
}

int query(int ind,int k)
{
	if(lo[ind] == hi[ind] && k == 1)
		return lo[ind];
	if(k <= sum[ind << 1])
		return query(ind << 1,k);
	else return query((ind << 1) | 1,k - sum[ind << 1]);

}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(sum,0,sizeof(sum));
		build(1,1,n);
		for(int i = 1 ; i <= n ; ++i)
			scanf("%d",&arr[i]);
		for(int i = n ; i >= 1; --i)
		{
			int pos = i - arr[i];

			int at = query(1,pos);
			arr[i] = at;
			update(1,at);
		}
		printf("%d",arr[1]);
		for(int i = 2 ; i <= n ; ++i)
			printf(" %d",arr[i]);
		printf("\n");
	}


}
