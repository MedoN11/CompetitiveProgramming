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
const int maxn = 2000*1000 + 5;
int n;
int spt_max[25][maxn],spt_min[25][maxn];
int a[maxn],b[maxn];

inline int query_min(int i,int j)
{
	int k = (int)floor(log((double)j-i+1) / log(2.0));

	return min(spt_min[k][i],spt_min[k][(j - ( 1 << k) + 1)]);
}
inline int query_max(int i,int j)
{
	int k = (int)floor(log((double)j-i+1) / log(2.0));

	return max(spt_max[k][i],spt_max[k][(j - ( 1 << k) + 1)]);
}
int main()
{
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&a[i]);
	for(int j = 0 ; j < n ; ++j)
		scanf("%d",&b[j]);
	for(int i = 0 ; i < n ; ++i)
		spt_max[0][i] = a[i],spt_min[0][i] = b[i];
	for(int p = 1 ; (1 << p) <= n ; ++p)
	{
		for(int i = 0 ; i + (1 << p) <= n ; ++i)
		{
			spt_min[p][i] = min(spt_min[p - 1][i],spt_min[p - 1][i + (1 << (p - 1))]);
			spt_max[p][i] =  max(spt_max[p - 1][i],spt_max[p - 1][i + (1 << (p - 1))]);
		}
	}
	ll ans = 0;
	for(int i = 0 ; i < n ; ++i)
	{
		int lo = i, hi = n - 1;
		int left  = -1;
		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			int q_min = query_min(i,mid), q_max = query_max(i,mid);
			if(q_min == q_max)
			{
				left = mid;
				hi = mid - 1;
			}
			if(q_min > q_max)
			{
				lo = mid + 1;
			}
			if(q_max > q_min)
			{
				hi = mid - 1;
			}
		}
		int right = -1;
		lo = i, hi = n - 1;
		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			int q_min = query_min(i,mid), q_max = query_max(i,mid);
			if(q_min == q_max)
			{
				right = mid;
				lo = mid + 1;
			}
			if(q_min > q_max)
			{
				lo = mid + 1;
			}
			if(q_max > q_min)
			{
				hi = mid - 1;
			}
		}
		if(left != -1)
			ans += 1LL*right - left + 1;
	}
	printf("%lld\n",ans);
}
