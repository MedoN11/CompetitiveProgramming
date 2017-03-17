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
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <unordered_map>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define ll  long long
using namespace std;
ll DP[15];
ll fac[15];

//The first approach is easier to understand and code, but notice that you don’t care about which number is used, instead you worry about how many numbers can be used, so you could just do it by a dfs by keep tracking of “free” numbers and using factorials. The depth in this case will be at most n.

ll nCk(int n,int k)
{
	return 1LL*(fac[n] / (fac[n - k] * fac[k]))*1LL;
}
long long dfs(int rem)
{
	if(rem == 0)
		return 1;
	ll &ret = DP[rem];
	if(ret != -1)
		return ret;
	ret = 1;
	for(int i = 1 ; i <= rem ; ++i)
	{
		ret += 1LL*nCk(rem,i) * 1LL*dfs(rem - i);
	}
	return ret;

}
int main()
{
	int tc;
	scanf("%d",&tc);
	memset(DP,-1,sizeof(DP));
	int t = 1;
	fac[0] = 1LL;
	for(int i = 1 ; i <= 14 ; ++i)
		fac[i] = 1LL*i * fac[i - 1];


	while(tc--)
	{
		int n;
		scanf("%d",&n);
		cout << t++ << " " << (n) << " "<< 1LL*dfs(n) - 1 << "\n";
	}
}
