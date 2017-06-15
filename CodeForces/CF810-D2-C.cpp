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
typedef vector<int> vi;
#define ln log
#define e exp
double EPS = 1e-9;
typedef pair<double, double> point;
const int maxn = 3*100000 + 5;
const ll mod = 1000*1000*1000 + 7;
ll pow2[maxn];
ll arr[maxn];
int n;
ll naive()
{
	ll sum = 0;
	for(int i = n - 1 ; i >= 0 ; --i)
	{
		for(int j = i - 1 ; j >= 0 ; --j)
		{
			sum += (arr[i] - arr[j]) * pow2[i - j - 1];
			sum %= mod;
		}
	}
	cout << sum << "\n";
	return sum;

}

void add(ll &sum,ll x)
{
	x %= mod;
	sum += x;
	while(sum < 0) sum += mod;
	sum %= mod;
}
void sub(ll &sum,ll x)
{
	x %= mod;
	sum -= x;
	while(sum < 0) sum += mod;
	sum %= mod;
}
int main()
{
	pow2[0] = 1LL;
	for(int i = 1 ; i < maxn ; ++i)
		pow2[i] = (pow2[i - 1] << 1)%mod;
	for(int i = 1 ; i < maxn ; ++i)
		pow2[i] += pow2[i - 1],pow2[i] %= mod;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%lld",&arr[i]);
	sort(arr,arr + n);
	//naive();
	ll delta = 500000004; // mod inv of two
	ll ans = 0;
	for(int j = n - 1 ; j >= 0 ; --j)
	{
		add(ans,pow2[j] * arr[j]);

		sub(ans,(pow2[n - j - 1] ) * arr[j]);
	}
	ans *= 1LL*delta; ans %= mod;
	printf("%lld",ans);




}
