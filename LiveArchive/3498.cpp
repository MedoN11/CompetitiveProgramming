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
ll DP[1 << 11];

//The problem can be thought of as follows. Given a permutation of N numbers. Find all possible grouping but none of the groups should be empty, and you may not use all numbers.
//
//For example a possible grouping for n = 4 is (4,3) (2) (1)
//
//Notice that N is small so you could enumerate all possible ways by DP.
//
//How to do so ? Use a bit-mask as your state where the ith bit is set to 0 if the ith number was used in a previous group.
//
//At every state, try all possible masks for a current group. If they are valid, meaning, all numbers are not used, and it is not empty, you recurse further.
//
//Base case when all numbers are used. ( Note since every group must be non-empty each time we use at least one number so our recursion must end).
long long solve(int msk)
{

	if(msk == 0)
		return 1;
	ll &ret = DP[msk];
	if(ret != -1)
		return ret;
	ret = 1;
	for(int i = 1 ; i <= msk ; ++i)
	{
		if((msk & i) == i)
		ret += 1LL*solve(msk & (~i));
	}
	return ret;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	memset(DP,-1,sizeof(DP));
	int t = 1;
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		cout << t++ << " " << (n) << " "<< solve((1 << n) - 1) - 1 << "\n";
	}
}
