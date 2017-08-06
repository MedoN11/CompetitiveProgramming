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
#include<complex>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
const int maxn = 2000005;
map<ll,vector<int> > mp;
map<int,ll> rev;
int sp[maxn + 1];
bool isPrime[maxn + 1];
void sieve()
{
	for(int i = 1 ; i <= maxn ; ++i) isPrime[i] = 1,sp[i] = i;
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(int i = 2; i <= maxn ; ++i)
	{
		if(isPrime[i])
		{
			for(int j = (i << 1) ; j <= maxn ; j += i)
			{
				isPrime[j] = 0;
				if(sp[j] == j)
					sp[j] = i;
			}
		}
	}

}

int main()
{
	sieve();
	for(int i = 1 ; i < 2000000 ; ++i)
	{
		// factor i
		long long hash = 1;
		int x = i;

		while(x > 1)
		{
			int pf = sp[x];
			hash *= 1LL*pf;
		//	hash %= 1000007;
			while(x % pf == 0) x /= pf;
		}

		rev[i] = hash;
		mp[hash].pb(i);
	}
	int n;
	while(scanf("%d",&n) != EOF)
	{
		if(n == 1)
			puts("Not Exist!");
		else
		{
			long long hash = rev[n];
			vector<int>::iterator it = upper_bound(all(mp[hash]),n);
			if(it == mp[hash].end())
				puts("Not Exist!");
			else printf("%d\n",*it);
		}
	}
}


