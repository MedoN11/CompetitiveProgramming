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
typedef pair<int,ll> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
const int maxn = 100005;
int n;
int bit[maxn];

// Binary indexed Tree
// BIT to maintain extra swaps
void upd(int ind,int delta)
{
	ind++;
	while(ind < maxn)
	{
		bit[ind] += delta;
		ind += ind & -ind;
	}
}

ll query(int ind)
{
	ind++;
	ll s = 0;
	while(ind > 0)
	{
		s += bit[ind];
		ind -= ind & - ind;
	}
	return s;
}

void add(int ind)
{
	upd(0,1);
	upd(ind + 1,-1);
}
map<int,int> mp;
int main()
{
	scanf("%d",&n);
	int x;
	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%d",&x);
		mp[x] = i;
	}
	ll swaps = 0;
	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%d",&x);
		int j = mp[x];
		//cerr << j << " " << i << " " << query(j) << "\n";
		swaps += 1LL*j - i + query(j);
		add(j);
	}
	cout << swaps << "\n";


}

