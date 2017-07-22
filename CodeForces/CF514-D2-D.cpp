#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define all(x)          (x).begin(),(x).end()
#define sz(v)               ((int)((v).size()))
int n,m,k;
const int maxn = 100005;
int arr[5][maxn];
int lo[4*maxn],hi[4*maxn],ans[6][4*maxn];


void build(int ind,int l,int r)
{
	lo[ind] = l, hi[ind] = r;


	if(l == r)
	{
		for(int j = 0 ; j < m ; ++j)
			ans[j][ind] = arr[j][l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind << 1,l,mid);
	build( (ind << 1) + 1,mid + 1,r);
	for(int j = 0 ; j < m ; ++j)
		ans[j][ind] = max(ans[j][ind << 1],ans[j][(ind << 1) + 1]);
}

int query(int ind,int l,int r,int j)
{
	if(lo[ind] >= l && hi[ind] <= r)
		return ans[j][ind];
	if(l > hi[ind] || r < lo[ind])
		return 0;
	return max(query(ind << 1,l,r,j),query((ind << 1) + 1,l,r,j));
}
inline int rmq(int l,int r,int j)
{
	return query(1,l,r,j);
}
bool can(int l,int r)
{
	ll shots = 0;
	for(int j = 0 ; j < m ; ++j)
	{
		shots += 1LL*rmq(l,r,j);
	}

	return shots <= k;
}

int main()
{

	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < m ; ++j) scanf("%d",&arr[j][i]);
	}
	build(1,0,n - 1);
	int maxk = 0;
	int optl = -1,optr = -1;
	int l = 0,r = 0;
	while(l < n)
	{
		while(l > r) ++r;
		while(can(l,r) && r < n)
		{
			if(r - l + 1 > maxk)
				maxk = r - l + 1,optl = l,optr = r;
			++r;
		}
		l++;
	}

	if(optl == -1 && optr == -1)
	{
		for(int j = 0 ; j < m ; ++j)
			cout << "0 ";
		return 0;
	}
	//cerr << can(optl,optr);
	for(int j = 0 ; j < m ; ++j)
	{
		printf("%d ",rmq(optl,optr,j));
	}


}
