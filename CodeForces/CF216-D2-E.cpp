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
vector<int> v;
int a,b,k;
const int maxn = 1000*1005;
int arr[maxn];
int n;
// Math + adhoc
// Google how to compute digital root of a number
// it has something to do with it's value % based
// based on that we can reduce the problem to counting subarrays with certain sum
// it's a standard problem that can be solved using a map.
int main()
{
	scanf("%d %d %d",&k,&b,&n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&arr[i]);
	ll z = 0;
	int i = 0;
	while(i < n)
	{
		int j = i;
		while(j < n && !arr[j]) ++j;
		int len = j - i + 1;
		z += 1LL*len*(len - 1) / 2LL;
		i = j + 1;
	}
	if(b == 0)
	{
		printf("%lld\n",z);
		return 0;
	}

	int mod = k - 1;
	map<int,int> mp;
	// x + val = b
	int sum = 0;
	ll res = 0;
	mp[0] = 1;
	for(int i = 0; i < n ; ++i)
	{
		sum += (arr[i]);
		sum %= mod;
		mp[sum]++;
		res += mp[((sum - b + mod) % mod)];
		if(b == k - 1) --res;
	}

	if(b == k - 1) res -= z;
	printf("%lld",res);

}
