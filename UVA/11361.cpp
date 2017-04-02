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
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
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
#include<algorithm>
#include <cassert>
#include <stack>
#include<cstring>
#include <cmath>
#include <complex>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <cstdio>
#include<map>
using namespace std;
#define ll long long
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)

// This can be solved by DP on digits. Start with a simple problem, let's say you want to count
// numbers between a and b using DP. Your state would start enumerating all possible numbers, while keeping track if you are larger than b, and less than A. (2 Flags)
// This can be done in log(b). You can find more information about this online.
//
// Here we can modify this to count numbers divisble by k along with their sums by taking the mod in each step.
//
// So now we have a solution that works in T*logN*K^2..with K being 10000 this is too much, but notice that the numbers at are most 2^31,
// which means that the sum of their digits cannot exceed 100, so for any K > 100, answer is indeed zero. For K < 100, we do the DP, since K in this case is at most 100, the DP will be fast enough.

string a,b;
int n;
ll DP[35][100][100][2][2];

int k;
ll solve(int ind,int kMod,int sumMod,int bta,int ltb)
{
	if(ind == n)
		return sumMod == 0 && kMod == 0 ? 1 : 0;
	ll &ret = DP[ind][kMod][sumMod][bta][ltb];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int i = 0 ; i <= 9 ; ++i)
	{
		int A = a.at(ind) - '0';
		int B = b.at(ind) - '0';
		if(A > i && !bta)
			continue;
		if(i > B && !ltb)
			continue;
		ret += solve(ind + 1,(kMod * 10 + i) % k,(sumMod + i) %k,bta || i > A , ltb || i < B );
	}
	return ret;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	int l,r;
	while(tc--)
	{
		scanf("%d %d %d",&l,&r,&k);
		if(k > 100)
		{
			puts("0");
			continue;
		}
		a = to_string(l);
		b = to_string(r);
		memset(DP,-1,sizeof(DP));
		int sz = sz(a);
		while(sz++ < sz(b))
		{
			a = '0' + a;
		}
		n = sz(b);
		cout << solve(0,0,0,0,0) << "\n";

	}

}
