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
#define MAXN 100005
int n,k;
int v[10001];
int mod = 5000000;
int tree[51][MAXN + 1];

inline void fix(int &res)
{
	if(res >= mod)
		res -= mod;
}
void add(int t,int ind,int delta)
{
	fix(delta);
	while(ind <= MAXN)
	{
		tree[t][ind] += delta;
		fix(tree[t][ind]);
		ind += ind & -ind;
	}
}

int query(int t,int ind)
{
	int sum = 0;
	while(ind > 0)
	{
		fix(tree[t][ind]);
		sum += tree[t][ind];
		fix(sum);
		ind -= ind & -ind;
	}
	return sum;
}
inline int Read()
{
	char ch = getchar();
	while (!((ch >= '0' && ch <= '9') || ch == '-')) ch = getchar();
	int x = 0, p = 1;
	if (ch == '-') p = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * p;
}
int main()
{
	scanf("%d %d",&n,&k);
	memset(tree,0,sizeof(tree));
	for(int i = 0 ; i < n ; ++i)
		v[i] = Read();
	for(int i  = 0 ; i < n ; ++i)
	{
		add(1,v[i],1);
		for(int j = 2 ; j <= k ; ++j)
		{
			if(v[i] > 0)
			add(j,v[i],query(j - 1,v[i] - 1));
		}
	}
	cout << query(k,MAXN) << "\n";



}
