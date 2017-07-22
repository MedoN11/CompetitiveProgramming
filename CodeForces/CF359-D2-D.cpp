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
#define ll  long long
#define pb push_back
#define all(x)          (x).begin(),(x).end()
#define sz(v)               ((int)((v).size()))
typedef pair<int,int> pii;
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
using namespace std;
const int maxn = 3*100001;
int n;
int v[maxn];
int spT[19][maxn];

int  gcd ( int a, int b )
{
	if(a == 0)
		return b;
	return gcd(b % a,a);

}
inline int query(int i,int j)
{
	int k = (int)floor(log((double)j-i+1) / log(2.0));

	return __gcd(spT[k][i],spT[k][(j - ( 1 << k) + 1)]);
}
int L[maxn];
int main()
{
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&v[i]),spT[0][i] = v[i],L[i] = -1;
	stack<int> s;
	int curr;

	for(int i = n - 1 ; i >= 0 ; --i)
	{
		while(!s.empty() && v[s.top()] >= v[i])
		{
			curr = s.top(); s.pop();
			L[curr] = i;
		}
		s.push(i);
	}


	for(int p = 1 ; (1 << p) <= n ; ++p)
	{
		for(int i = 0 ; i + (1 << p) <= n  ; ++i)
		{
			spT[p][i] = gcd(spT[p - 1][i] ,spT[p - 1][(i + (1 << (p - 1)))]);
		}
	}

	int foo = 0;
	vector<int> ans;

	for(int i = 0 ; i < n ; ++i)
	{

		int lo = i;
		int hi = n - 1;
		int right = i;
		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			int g = query(i,mid);
			//assert(g <= v[i]);
			if(g == v[i])
				lo = mid + 1,right = mid;
			else hi = mid - 1;
		}
		lo = L[i] + 1;
		hi = i;
		int left = i;
		while(lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			int g = query(mid,i);
			//assert(g <= v[i]);
			if(g == v[i])
				hi = mid - 1,left = mid;
			else lo = mid + 1;
		}

		int curr = right - left + 1;
		if(curr > foo)
		{
			foo = curr;
			ans.clear();
		}
		if(foo == curr) ans.pb(left);
	}
	printf("%d %d\n",sz(ans),foo - 1);
	for(int i = 0 ; i < sz(ans) ; ++i)
		printf("%d ",ans[i] + 1);

}
