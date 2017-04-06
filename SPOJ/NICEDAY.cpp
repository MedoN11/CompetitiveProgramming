#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
using namespace std;


/*
 3 Dimensions. Sort on one dimension, build Segment tree over second, and queries manage third.
 Sort the input on the first value, then the tuples which can be better than the ith one is from 1 to i - 1.
 We would like to know if there exists a tuple smaller than us in second and third values
 so we build a segment tree over the second values and update with third value.
 for each i we query for the least value from 1 to second value
 if it's less then this tuple should be counted.
 */
typedef pair<int,int> ii;
#define MAXN 100005
int t;
int lo[4*MAXN];
int hi[4*MAXN];
int ans[4*MAXN];

void upd(int ind)
{
	ans[ind] = min(ans[ind << 1],ans[(ind << 1) + 1]);
}
void init(int ind,int a,int b)
{
	if(a > b)
		return;
	lo[ind] = a; hi[ind] = b;
	if(a == b)
	{
		ans[ind] = 1 << 30;
		return;
	}
	int mid = (a + b) / 2;
	init(ind << 1,a,mid);
	init((ind << 1) + 1,mid + 1,b);
	upd(ind);
}

void update(int ind,int val,int a)
{
	if(lo[ind] > a || hi[ind] < a)
		return;
	if(lo[ind] == a && hi[ind] == a)
	{
		ans[ind] = val;
		return;
	}
	update(ind << 1,val,a);
	update((ind << 1) + 1,val,a);
	upd(ind);
}

int query(int ind,int a,int b)
{
	if(a <= lo[ind] && b >= hi[ind])
		return ans[ind];
	if(a > hi[ind] || b < lo[ind])
		return 1 << 30;
	return min(query(ind << 1,a,b),query((ind << 1) + 1,a,b));
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{

		vector<pair<int,ii> > v;

		int n; scanf("%d",&n);
		v.resize(n);
		for(int i = 0 ; i < n ; ++i)
			scanf("%d %d %d",&v[i].first,&v[i].second.first,&v[i].second.second);
		sort(v.begin(),v.end());
		int ret = 0;
		ans[0] = 1 << 30;
		init(1,1,MAXN - 2);

		for(int i = 0 ; i < n ; ++i)
		{
			bool bad = 0;
			int best = query(1,1,v[i].second.first);
			//cerr << best << "\n";
			if(best < v[i].second.second)
				bad = 1;
			if(!bad)
				++ret;
			update(1,v[i].second.second,v[i].second.first);
		}

		printf("%d\n",ret);
	}
}
