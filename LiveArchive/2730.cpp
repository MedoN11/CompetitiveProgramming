
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
#include <vector>
#include <iostream>
using namespace std;
#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast std::ios_base::sync_with_stdio(false);
using namespace std;
#define MAXN 26 + 26 + 1
int m;
map<char,int> mp;
int ind = 0;
vector<int> G[MAXN];


/*
 Define F(X) such that it returns true if it's possible to start with X items, and deliever to the sink with
 the requested capacity.
 F(X) is definitely increasing. If we can deliever with X then we for sure deliever with X + 1.

 It remains how to do the checks fast. The idea I used here is a Dynamic Programming, the graph isn't a DAG but we can
 ignore cycles during DP since an optimal path will never contain cycles.

 Notice once a state is entered it set to 0, so if this state is recalled by one of it's childs it will return false, and ignore the cycles

 */
int DIS[MAXN];
bool isTown(int i)
{
	return i < 26;
}
int DP[MAXN][7000];
int sink;
int must;
bool solve(int u,int rem)
{
	if(rem < must)
		return 0;
	if(u == sink)
		return 1;
	int &ret = DP[u][rem];
	if(ret != -1)
		return ret;
	ret = 0;
	for(int i = 0 ; i < G[u].size() ; ++i)
	{
		int v = G[u][i];
		int pay = 0;
		if(isTown(v))
		{
			pay = rem / 20;
			if(rem % 20)
				++pay;
		}
		else pay = 1;
		ret |= solve(v,rem - pay);
	}
	return ret;
}
int main()
{
	fast
	for(int i = 0 ; i < 26 ; ++i)
		mp[(char)('A' + i)] = ind++;
	for(int i = 0 ; i < 26 ; ++i)
		mp[(char)('a' + i)] = ind++;
	int tc = 1;
	while(cin >> m , m != -1)
	{
		for(int i = 0 ; i < MAXN ; ++i)
			G[i].clear();
		char u,v;
		int i,j;
		while(m--)
		{
			cin >> u >> v;
			i = mp[u]; j = mp[v];
			G[i].push_back(j);
			G[j].push_back(i);
		}
		memset(DP,-1,sizeof(DP));
		int quant;
		cin >> quant >> u >> v;
		must = quant;
		sink = mp[v];
		int ans = -1;
		int lo = quant;
		int hi = 6999;
		int src = mp[u];
		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			if(solve(src,mid))
			{
				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		assert(ans != -1);
		cout << "Case " << (tc++) << ": " << ans << "\n";

	}

}
