#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
int arr[2001];

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

inline ll lcm(ll a,ll b)
{
	return (long long)(1LL*a * (1LL*b/__gcd(a,b)));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int tot = 0;
		int n;
		scanf("%d",&n);
		ll mx = 0;
		for(int i = 0 ; i < n ; ++i)
			arr[i] = readInt(),mx += arr[i];
		for(int i = 0 ; i < n ; ++i)
		{
			int ans = 1;
			ll s = arr[i];
			ll lc = arr[i];
			for(int j = i + 1 ; j < n ; ++j)
			{
				s += 1LL*arr[j];
				if(lc > mx)
					break;
				lc = lcm(lc,arr[j]);
				if(s % lc == 0) ++ans;
			}
			tot += ans;
		}
		printf("%d\n",tot);
	}

}
