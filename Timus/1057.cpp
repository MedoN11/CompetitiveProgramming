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
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
int n,m;
int k,b;
ll x,y;

// Rephrase problem as : Find the numbers in base b with exaclty k 1's between x and y
//then easy digit dp :)
string letters = "0123456789ABCDEF";
string base,lim;
string fromDecToBase(ll num,int base)
{
	if(num == 0)
		return "0";
	string ret = "";
	while(num > 0)
	{
		ret = letters[num % base] + ret;
		num /= base;
	}
	return ret;
}

ll dp[66][2][2][25];

ll solve(int ind,int ls,int br,int rem)
{
	if(rem < 0)
		return 0;
	if(ind == 65)
		return rem == 0 ? 1 : 0;
	ll &ret = dp[ind][ls][br][rem];
	if(ret != -1)
		return ret;
	ret = 0;
	int lim_ch = lim.at(ind) - '0';
	int base_ch = base.at(ind) - '0';
	for(int j = 0 ; j <= 1 ; ++j)
	{
		if(base_ch > j && !br)
			continue;
		if(j > lim_ch && !ls)
			continue;

		ret += solve(ind + 1,lim_ch > j || ls,base_ch < j || br,rem - j);
	}
	return ret;

}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%lld %lld",&x,&y);
	scanf("%d %d",&k,&b);
	base = fromDecToBase(x,b);
	lim = fromDecToBase(y,b);
	while(sz(base) < 65) base = '0' + base;
	while(sz(lim) <  65) lim = '0' + lim;
	//cerr << base << "\n" << lim << "\n";
	printf("%lld\n",solve(0,0,0,k));


}


