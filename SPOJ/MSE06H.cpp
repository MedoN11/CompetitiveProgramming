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
using namespace std;
#define ll long long
#define MAXN (int)(10e4 + 1)

ll tree[MAXN + 1];

void upd(int ind,int delta)
{
	while(ind <= MAXN)
	{
		tree[ind] += delta;
		ind += ind & -ind;
	}
}

ll query(int ind)
{
	ll sum = 0;
	while(ind > 0)
	{
		sum += 1LL*tree[ind];
		ind -= ind & -ind;
	}
	return sum;
}

int main()
{
	int tc;
	cin >> tc;
	int n,m,k;
	int t = 1;
	while(tc--)
	{
		scanf("%d %d %d",&n,&m,&k);
		memset(tree,0,sizeof(tree));
		vector<pair<int,int> > edges;
		edges.resize(k);
		for(int i = 0 ; i < k ; ++i)
		{
			scanf("%d %d",&edges[i].first,&edges[i].second);

		}
		sort(edges.begin(),edges.end());
		long long ans = 0;
		for(int i = 0 ; i  < k ; ++i)
		{

			int y = edges[i].second;
			ans += query(MAXN) - query(y);
			upd(y,1);
		}
		printf("Test case %d: %lld\n",t++,ans);

	}
}
