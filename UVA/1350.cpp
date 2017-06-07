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
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
ll dp1[101][2];
ll dp3[101][2];
ll dp2[101];
ll solve(int n,int lst)
{
	if(n == 1)
		return !lst;
	ll &ret = dp1[n][lst];
	if(ret != -1)
		return ret;
	ret = 0;
	if(lst)
		ret += solve(n - 1,0);
	else ret += solve(n - 1,0) + solve(n - 1,1);
	return ret;
}
vector<char> v;
int m;
ll solve2(int n,int lst)
{

	if(n == m)
		return lst == 1 ? 1 : 2;
	ll &ret = dp3[n][lst];
	if(ret != -1)
		return ret;
	ret = 0;
	if(n == 1)
	{
		ret += solve2(n + 1,1);
	}
	else
	{
		if(lst)
			ret += solve2(n + 1,0);
		else ret += solve2(n + 1,0) + solve2(n + 1,1);
	}
	return ret;

}
void trace(int n,int lst,ll k)
{

	if(n == m)
	{
		//cerr << k << "\n";
		if(lst) v.push_back('0');
		else
		{
			if(k >= 1) v.push_back('1');
			else v.push_back('0');
		}
		return;
	}
	if(n == 1)
	{
		v.push_back('1');
		trace(n + 1,0,k - 1);
		return;
	}
	if(lst)
	{
		v.push_back('0');
		trace(n + 1,0,k);
		return;
	}
	ll opt1 = solve2(n + 1,0);
	if(opt1 <= k)
	{
		v.push_back('1');
		trace(n + 1,1,k - opt1);
	}
	else
	{
		v.push_back('0');
		trace(n + 1,0,k);
	}
}
const int lim = 50;
int main()
{
	fast
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	dp2[0] = 0;
	for(int i = 1 ; i <= lim ; ++i)
		dp2[i] = solve(i,0) + dp2[i - 1];
	int t; cin >> t;
	while(t--)
	{
		ll k; cin >> k;
		memset(dp3,-1,sizeof(dp3));
		int lo = 0, hi = lim;
			int len = -1;
		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			if(dp2[mid] >= k)
			{
				len = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}


		k -= dp2[len - 1];
		v.clear();
	//	cerr << k << "\n";
		m = len;
		trace(1,0,k);
		REP(i,v)
		cout << v[i];
		cout << "\n";
	}



}
