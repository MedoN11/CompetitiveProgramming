
#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
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
#include <cstdio>
#include<map>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
using namespace std;
#define ll long long
#define MAXN 350005
ll lo[4*MAXN];
ll hi[4*MAXN];
ll res[4*MAXN];
ll pre[MAXN];

// for each opening bracket we want to know how much area does it contribute
// we can find the width easily by processing it’s closing bracket by a stack and getting distance in between..we process that in array to[i] which gives the index of it’s matched closed bracket
// Now we need to know the height, we can solve that by DP.
// Define DP[I] = 1 + max(DP[j]), i <= j <= to[i]
// doing so would take O(N^2)
// but we can do this in NlogN
// build segment tree of prefix sums of the bracket sequence
// then run Range maximum query
// adding areas to white or black depends on parity of the nesting
{
	res[ind] = max(res[ind << 1],res[(ind << 1) + 1]);
}
void build(int ind,int a,int b)
{
	if(a > b)
		return;
	lo[ind] = a; hi[ind] = b;
	if(a == b)
	{
		res[ind] = pre[a];
		return;
	}
	int mid = a + (b - a) / 2;
	build(ind << 1,a,mid);
	build((ind << 1) + 1,mid + 1,b);
	upd(ind);
}

ll query(int ind,int a,int b)
{
	if(a > b)
		return 0;

	if(lo[ind] >= a && hi[ind] <= b)
		return res[ind];
	if(hi[ind] < a || lo[ind] > b)
		return 0;

	int left = query(ind << 1,a,b);
	int right = query((ind << 1) + 1,a,b);
	return max(left,right);
}
char s[MAXN];
int n;
int to[MAXN];
pair<ll,ll> lvl[MAXN];

ll calc(int ind,ll wid)
{
	pair<ll,ll> p = lvl[ind];
	return 1LL*wid * p.second;
}
char c[MAXN];
int main()
{
	int t;
	scanf("%d",&t);
	lvl[1] = make_pair(1,1);
	for(int i = 2 ; i < MAXN ; ++i)
	{
		lvl[i] = make_pair(lvl[i - 1].first + 2, lvl[i - 1].second + 1);
	}
	while(t--)
	{
		memset(pre,0,sizeof(pre));
		scanf("%s",c); n = strlen(c);
		stack<pair<char,int> > stk;
		for(int i = 1 ; i <= n ; ++i)
			s[i] = c[i - 1];
		for(int i = 1 ; i <= n ; ++i)
		{
			if(s[i] == ')')
			{
				if(stk.top().first == ')')
					stk.push(make_pair(')',i));
				else
				{
					pair<char,int> m = stk.top(); stk.pop();
					to[m.second] = i;
				}

			}
			else stk.push(make_pair('(',i));
		}

		ll area = 0;
		int dep = 0;
		pre[0] = 0;
		for(int i = 1 ; i <= n ; ++i)
		{
			if(s[i] == '(')
				++dep;
			else --dep;
			pre[i] = dep;
		}
		build(1,1,n);
		for(int i = 1 ; i <= n ; ++i)
		{
			if(s[i] == '(')
			{
				ll lvl = query(1,i,to[i]) - pre[i - 1];
				ll wid = to[i] - i;
				if(pre[i] % 2 == 1)
					area += 1LL*calc(lvl,wid);
				else area -= 1LL*calc(lvl,wid);
			}
		}

		printf("%lld\n",area);
	}

}


