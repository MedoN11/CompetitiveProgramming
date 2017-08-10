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
#include<complex>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
using namespace std;
#define ll  long long
//It's a variation of "print first number larger than N but here are some constraints on the digits you use".
struct FavouriteDigits
{
	ll findNext(ll n,int d1,int c1,int d2,int c2);
};
string str;
int dp[64][64][64][2][2];
int d1,d2,c1,c2;
int solve(int ind,int cnt1,int cnt2,int bg,int z)
{
	if(ind == 64) return cnt1 >= c1 && cnt2 >= c2 ? 0 : 1 << 25;
	int &ret = dp[ind][cnt1][cnt2][bg][z];
	if(ret != -1)
		return ret;
	ret = 1 << 25;

	for(int i = 0 ; i <= 9 ; ++i)
	{
		int curr = str.at(ind) - '0';
		if(!bg && i < curr)
			continue;
		int cost = (z || i != 0) ? 1 : 0;
		int f1 = d1 == i;
		int f2 = d2 == i;
		if(d1 == 0 && !z) f1 = 0;
		if(d2 == 0 && !z) f2 = 0;
		ret = min(ret,cost + solve(ind + 1,cnt1 + f1,cnt2 + f2,bg || i > curr,z || i != 0));
	}


	return ret;
}

ll cons = 0;
void trace(int ind,int cnt1,int cnt2,int bg,int z)
{
	if(ind == 64) return ;
	int opt = solve(ind,cnt1,cnt2,bg,z);

	int ret = 1 << 25;
	for(int i = 0 ; i <= 9 ; ++i)
	{
		int curr = str.at(ind) - '0';
		if(!bg && i < curr)
			continue;
		int cost = (z || i != 0) ? 1 : 0;
		int f1 = d1 == i;
		int f2 = d2 == i;
		if(d1 == 0 && !z) f1 = 0;
		if(d2 == 0 && !z) f2 = 0;
		ret = min(ret,cost + solve(ind + 1,cnt1 + f1,cnt2 + f2,bg || i > curr,z || i != 0));
		if(opt == ret)
		{
			cons *= 10; cons += i;
			trace(ind + 1,cnt1 + f1,cnt2 + f2,bg || i > curr,z || i != 0);
			return;
		}
	}


	return;
}
ll FavouriteDigits::findNext(ll n,int d1_,int c1_,int d2_,int c2_)
{
	memset(dp,-1,sizeof(dp));
	c1 = c1_, c2 = c2_; d1 = d1_; d2 = d2_;
	str = to_string(n);
	while(str.size() < 64) str = '0' + str;
	cerr << solve(0,0,0,0,0) << "\n";
	//cout << str << "\n";
	trace(0,0,0,0,0);
	return cons;
}

int main()
{
	FavouriteDigits d;
	cout << d.findNext(47,1,0,2,0);
}

