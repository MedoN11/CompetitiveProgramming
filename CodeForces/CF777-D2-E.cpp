#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <vector>
#include <iterator>
#include <math.h>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <cstdio>
#include<map>
#define ll long long
using namespace std;
#define MAXN 1000001

int lo[4*MAXN + 1];
int hi[4*MAXN + 1];
ll ans[4*MAXN + 1];
ll arr[MAXN];


void upd(int i)
{

	int left = ans[i << 1];
	int right = ans[(i << 1) + 1];
	if(arr[right] > arr[left])
		ans[i] = right;
	else ans[i] = left;
}
void init(int i,int a,int b)
{
	if(a > b)
		return;
	lo[i] = a; hi[i] = b;
	if(a == b)
	{
		ans[i] = a;
		return;
	}
	int mid = (a + b) / 2;
	init(i << 1,a,mid);
	init((i << 1) + 1,mid + 1,b);
	upd(i);


}

void update(int i,int ind,ll val)
{

	if(ind < lo[i])
		return;
	if(ind > hi[i])
		return;

	if(lo[i] == hi[i])
	{
		arr[lo[i]] = val;
		return;
	}
	update(i << 1,ind,val);
	update((i << 1) + 1,ind,val);
	upd(i);
}

int query(int i,int a,int b)
{
	if(a > b)
		return 0;
	if(hi[i] < a || lo[i] > b)
	{
		return 0;
	}
	if(lo[i] >= a && hi[i] <= b)
	{		return ans[i];
	}

	int left = query(i << 1,a,b);
	int right = query((i << 1) + 1,a,b);
	if(arr[left] < arr[right])
		return right;
	return left;
}

typedef pair<ll,ll> ii;
typedef pair<ii,ll> entry;
vector<entry> v;
int main()
{
	lo[0] =  1 << (30);
	hi[0] = - (1 << 30);
	arr[0] = -(1LL << 55);
	int n;
	scanf("%d",&n);
	memset(arr,0,sizeof(arr));
	ll b,a,h;
	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%lld %lld %lld",&a,&b,&h);
		v.push_back(entry(ii(b,a),h));
	}
	map<int,int> mp;
	map<int,int> cord;
	for(int i = 0 ; i < n ; ++i)
	{

		mp[v[i].first.second] = 1;
		mp[v[i].first.first] = 1;
	}
	map<int,int>::iterator it = mp.begin();
	int cnt = 1;
	for(; it != mp.end() ;it++)
	{
		if(cord.find(it->first) == cord.end())
			cord[it->first] = cnt++;
	}
	for(int i = 0 ; i < n ; ++i)
	{
		v[i].first.first = cord[v[i].first.first];
		v[i].first.second = cord[v[i].first.second];
	}
	init(1,1,cnt);
	sort(v.rbegin(),v.rend());
	ll ans = 0;
	for(int i = 0 ; i < n ; ++i)
	{
		//cerr << v[i].first.first << " " << v[i].first.second << " " << v[i].second << "\n";
		ll best = max(0,query(1,1,v[i].first.first - 1));
		//cerr << i << " " << arr[best] << "\n";
		ans = max(ans,1LL*arr[best] + v[i].second);
		if(arr[v[i].first.second] < 1LL*arr[best] + v[i].second)
			update(1,v[i].first.second,1LL*arr[best] + v[i].second);
	}
	cout << ans;
}
