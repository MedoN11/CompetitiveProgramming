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
typedef pair<long double,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
typedef long double ld;
const int maxn = 1000*1000*10 + 5;
using namespace std;
int t;
ll mod = 1000*1000*1000 + 7;
ll fact[3000000 + 5];

int put(int x,int y)
{
	int p = 1;
	for(int i= 1 ; i <= y; i<<=1 )
	{
		if(y & i) p= (1LL*p*x) %mod;
		x = (1LL*x*x) %mod;
	}
	return p;
}

ll nCk(int n,int m)
{
	if(m == 0)
		return 1;
	return (1LL * fact[n] * put( (1LL * fact[m] * fact[n-m] ) % mod, mod - 2 ))%mod;
}
ll fast(int n,int r)
{

	return ((nCk(n,r)%mod))%mod;
}

int main()  {
	scanf("%d",&t);
	fact[0] = 1;
	for(int i=1;i < 3000005;i++) fact[i] =( 1LL * fact[i-1] *i )%mod;

	while(t--) {
		int n;
		scanf("%d",&n);
		ll two = 500000004;
		printf("%lld\n",((n*nCk(2*n,n)%mod)*two)%mod);
	}

}
