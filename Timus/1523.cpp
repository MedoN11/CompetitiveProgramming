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
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include<cstring>
#include <cmath>
#include <complex>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
using namespace std;
#define ll long long
#define MAXN 200001

// Dynamic Programming + BIT
// Maintain an array of K fenwick trees
// Number of subsequences of length L ending with element a[i] = number of subsequences of length L - 1 ending with a number x < a[i]
// the above can be counted using BIT
int n,k;
vector<int> v;
ll tree[12][MAXN+1];
ll mod = (ll)(1000*1000*1000LL);
void fix(ll &res)
{
	while(res < 0)
		res += mod;
	res %= mod;
}
void update(int t,int ind,ll delta)
{
	delta %= mod;
	while(ind <= MAXN)
	{
		tree[t][ind] += 1LL*delta;
		tree[t][ind] %= mod;
		fix(tree[t][ind]);
		ind += ind & -ind;
	}
}

ll query(int t,int ind)
{
	ll sum = 0;
	while(ind > 0)
	{
		sum += 1LL*tree[t][ind];
		fix(sum);
		sum %= mod;
		ind -= ind & -ind;
	}
	fix(sum);
	return sum;
}
int main()
{
	scanf("%d %d",&n,&k);
	v.resize(n);
	memset(tree,0,sizeof(tree));
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&v[i]);

	for(int i = n - 1 ; i >= 0 ; --i)
	{
		update(1,v[i],1);
		for(int j = 2 ; j <= k ; ++j)
			update(j,v[i],query(j - 1,v[i] - 1));
	}
	ll ans = query(k,n);
	ans %= mod;
	fix(ans);

	cout << ans << "\n";
}
