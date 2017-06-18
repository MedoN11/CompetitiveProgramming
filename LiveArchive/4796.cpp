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
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define pb push_back
const int maxn = 2*105005;

int tree[maxn];
int pre[maxn],suf[maxn],arr[maxn];
int sz = 1;
int t;
inline void upd(int ind,int x)
{
	while(ind <= sz)
		tree[ind] = max(tree[ind],x),ind += ind & (-ind);
}
inline int query(int ind)
{
	int x = 0;
	while(ind > 0)
		x = max(tree[ind],x),ind -= ind & (-ind);
	return x;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		map<int,int> cord;
		int n; scanf("%d",&n);
		sz = 1;
		for(int i = 0 ; i < n ; ++i) scanf("%d",&arr[i]),cord[arr[i]] = 1;
		for(map<int,int>::iterator it = cord.begin() ; it != cord.end();it ++)
			it->second = sz++;
		pre[0] = suf[n - 1] = 1;
		for(int i = 0 ; i < n ; ++i) arr[i] = cord[arr[i]];
		for(int i = 1 ; i < n ; ++i)
		{
			pre[i] = 1;
			if(arr[i] > arr[i - 1])
				pre[i] += pre[i - 1];
		}
		for(int i = n - 2 ; i >= 0 ; --i)
		{
			suf[i] = 1;
			if(arr[i] < arr[i + 1])
				suf[i] += suf[i + 1];
		}
		for(int i = 0 ; i <= sz ; ++i) tree[i] = 0;
		int ans = 1;
		for(int i = 0 ; i < n ; ++i)
		{
			ans = max(ans,suf[i] + query(arr[i] - 1));
			upd(arr[i],pre[i]);
		}
		printf("%d\n",ans);
	}
}
