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
const int maxn = 100005;
int l[maxn],r[maxn];
int val[maxn];
bool root[maxn];
int n;
const int inf = 1e9 + 1;
set<int> s;
void dfs(int u,int mini,int maxi)
{
	if(val[u] > mini && val[u] < maxi)
		s.insert(val[u]);
	if(l[u] >= 0)
	{
		dfs(l[u],mini,min(maxi,val[u]));
	}
	if(r[u] >= 0)
	{
		dfs(r[u],max(mini,val[u]),maxi);
	}

}
int main()
{
	scanf("%d",&n);

	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%d %d %d",&val[i],&l[i],&r[i]);
		--l[i]; --r[i];
		if(l[i] >= 0)
		root[l[i]] = 1;
		if(r[i] >= 0)
		root[r[i]] = 1;
	}
	for(int i = 0 ; i < n ; ++i)
		if(!root[i])
		{
			dfs(i,-inf,inf);
		}
	int ans = 0;
	for(int i = 0 ; i < n ; ++i)
		ans += !(s.find(val[i]) != s.end());
	printf("%d\n",ans);
}
