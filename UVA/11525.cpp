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
using namespace std;
// Math + BIT
// Problem can be abstractead as
// given a sorted permutation and 2 queries of the form delete kth element, and get kth element.
// so we simulate process with a BIT in log^2n..also logn by binary search on bit itself is possible but not needed to pass
int t;
int n;
const int maxn = 55000;
int bit[maxn];
void  add(int ind,int delta)
{

	while(ind < maxn)
	{
		bit[ind] += delta;
		ind += ind & -ind;
	}
}
int sum(int ind)
{

	int s = 0;
	while(ind > 0)
	{
		s += bit[ind];
		ind -= ind & -ind;
	}
	return s;
}
int getKth(int k)
{
	int lo = 1, hi = n;
	int ans = -1;
	while(lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if(sum(mid) >= k)
		{
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	return ans;
}
int main()
{
	ios
	cin >> t;
	while(t--)
	{
		cin >> n;

		for(int i = 1 ; i <= n ; ++i)
			add(i,1);
		for(int i = 1 ; i <= n ; ++i)
		{
			int x;
			cin >> x;
			int k = getKth(x + 1);
			if(i != 1)
				cout << " ";
			cout << k;
			add(k,-1);
		}
		cout << "\n";

	}
}

