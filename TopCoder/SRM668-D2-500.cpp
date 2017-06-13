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
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<complex>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef vector<int> vi;
#define ln log
#define e exp
double EPS = 1e-9;
typedef pair<double, double> point;
const int maxn = 4*100005 + 5;
ll lo[maxn],hi[maxn],ans[maxn];


void upd(int i)
{

	ans[i] = max(ans[i << 1],ans[(i << 1) + 1]);
}
void init(int i,int a,int b)
{
	if(a > b)
		return;
	lo[i] = a; hi[i] = b;
	if(a == b)
	{
		ans[i] = 0;
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
		ans[i] = max(ans[i],val);
		return;
	}
	update(i << 1,ind,val);
	update((i << 1) + 1,ind,val);
	upd(i);
}

ll query(int i,int a,int b)
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


	return max(query((i << 1) ,a,b),query((i << 1) + 1,a,b));

}

vector<ll> v;
ll area(ll r, ll h)
{
	 return 1LL*r * r * h;
}
int n;
double pi = acos(-1.);
map<ll,ll> cord;
int main()
{
	scanf("%d",&n);
	memset(ans,0,sizeof(ans));
	for(int i = 0 ; i < n ; ++i)
	{
		ll r,h; scanf("%lld %lld",&r,&h);
		v.push_back(area(r,h));
		//cout << v.back() << "\n";
	}


	REP(i,v)
	cord[v[i]] = 1;
	int ind = 1;
	for(map<ll,ll>::iterator it = cord.begin(); it != cord.end(); it++)
	{
		it->second = ind++;
	}
	init(1,1,ind);
	ll ans = 0;
	for(int i = 0 ; i < n ; ++i)
	{
		ll me = cord[v[i]];

		ll best = 0;
		if(me > 1)
			best = max(0LL,query(1,1,me - 1));
		//cout << best << "\n";
		update(1,me,1LL*v[i] + best);
		ans = max(ans,1LL*v[i] + best);

	}
	//cout << ans << "\n";
	printf("%.12f",1.0 * pi * ans);

}


