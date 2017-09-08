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
#include <complex>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef  pair<int,int> pii;
int n;
int q;
int block;
const int maxqueries = 200005;
const int maxn = 200005;
ll ans[maxqueries];
struct node
{
	int l,r,ind;
}queries[maxqueries];

int arr[maxn];
ll res = 0;
bool QCMP(node &a, node &b)
{
	if(a.l/block!=b.l/block) return a.l/block < b.l/block;
	else return a.r < b.r;
}
int bit[maxn + 1];

void inc(int ind,int delta)
{
	ind++;
	while(ind < maxn)
	{
		bit[ind] += delta;
		ind += ind & -ind;
	}
}
int sum(int ind)
{
	ind++;
	int s = 0;
	while(ind > 0)
	{
		s += bit[ind];
		ind -= ind & -ind;
	}
	return s;
}
inline void add(int ind,bool r)
{
	if(r)
	{
		ind = arr[ind];
		res += 1LL*sum(maxn - 1) - sum(ind);
		inc(ind,1);
	}
	else
	{
		ind = arr[ind];
		res += sum(ind - 1);
		inc(ind,1);
	}
}
inline void remove(int ind,bool r)
{
	if(r)
	{
		ind = arr[ind];
		res -= 1L*sum(maxn - 1) - sum(ind);
		inc(ind,- 1);
	}
	else
	{
		ind = arr[ind];
		res -= 1LL*sum(ind - 1);
		inc(ind,-1);
	}
}

map<int,int> cord;
int main()
{


	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%d",&arr[i]);
		cord[arr[i]] = 1;
	}
	cin >> q;

	for(int i = 0 ; i < q ; ++i)
	{
		cin >> queries[i].l >> queries[i].r; queries[i].ind = i;
		queries[i].l--; queries[i].r--;
	}
	block = ceil(sqrt(n));
	int ind = 0;
	for(map<int,int>::iterator it = cord.begin(); it != cord.end(); it++)
	{
		it->second = ind++;
	}
	for(int i = 0 ; i < n ; ++i)
		arr[i] = cord[arr[i]];
	int currentL = 0; int currentR = -1;
	int L,R;
	sort(queries,queries+q,QCMP);
	for(int i = 0 ; i < q ; ++i)
	{
		cerr << "here" << "\n";
		L = queries[i].l; R = queries[i].r;

		while(currentR < R)
		{
			currentR++;
			add(currentR,1);

		}
		while(currentR > R)
		{

			remove(currentR,1);
			currentR--;
		}
		while(currentL < L)
		{
			remove(currentL,0);
			currentL++;

		}
		while(currentL > L)
		{
			currentL--;
			add(currentL,0);
		}
		ans[queries[i].ind] = res;

	}
	for(int i = 0 ; i < q ; ++i)
		printf("%lld\n",ans[i]);

}

