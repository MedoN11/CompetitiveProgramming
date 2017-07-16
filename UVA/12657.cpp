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
const int maxn = 1000*1000 + 5;
int L[maxn],R[maxn];

void mergeLeft(int i,int j)
{
	if(L[j] == i)
		return;
	// put i to the left of j

	// before removing i let's fix linking
	L[R[i]] = L[i];
	R[L[i]] = R[i];

	// left of i is now old left of j
	R[L[j]] = i;
	L[i] = L[j];
	// update left and right for both
	R[i] = j;
	L[j] = i;
}
//4 4
//1 4 1
//2 2 3
//3 3 4
//3 2 4

void mergeRight(int j,int i)
{
	// put j to the right of i
	if(R[i] == j)
		return;
	L[R[j]] = L[j];
	R[L[j]] = R[j];

	// right of j is now old right of i
	L[R[i]] = j;
	R[j] = R[i];

	R[i] = j;
	L[j] = i;
}

void swapf(int x,int y)
{
	if(R[y] == x)
		swap(x,y);
	if(R[x] == y)
	{

		int tmp2 = L[x];
		L[x] = y; R[x] = R[y];
		L[y] = tmp2; R[y] = x;

		R[L[x]] = x; L[R[x]] = x;
		R[L[y]] = y; L[R[y]] = y;
		return;
	}

	int tmp1 = L[x], tmp2 = R[x];
	L[x] = L[y];
	R[x] = R[y];
	L[y] = tmp1;
	R[y] = tmp2;

	R[L[x]] = x; L[R[x]] = x;
	R[L[y]] = y; L[R[y]] = y;



}

int arr[maxn];
int n,q;

void print()
{
	int root = -1;
	for(int i = 1 ; i <= n ; ++i)
		if(L[i] == 0) root = i;
	int pos = 1;
	while(pos <= n)
		cout << root << " " ,arr[pos++] = root, root = R[root];
	cout << "\n";
}
int main()
{
	int tc = 1;
	while(scanf("%d %d",&n,&q) == 2)
	{
		for(int i = 1 ; i <= n ; ++i)
			L[i] = i - 1, R[i] = i + 1;
		int st = 0;
		int tp,i,j;
	//	print();
		while(q--)
		{
			scanf("%d",&tp);
			if(tp == 4)
			{
				st ^= 1;
				continue;
			}
			scanf("%d %d",&i,&j);
			if(tp == 3)
			{
				swapf(i,j);
				continue;
			}
			if(st)
			{
				tp = 3 - tp;
			}
			if(tp == 1)
			{
				mergeLeft(i,j);
			}
			if(tp == 2)
			{
				mergeRight(i,j);
			}

			//print();
		}
		int root = -1;
		for(int i = 1 ; i <= n ; ++i)
			if(L[i] == 0) root = i;
		//cerr <<"hereez " << root << "\n";
		int pos = 1;
		while(pos <= n)
			arr[pos++] = root, root = R[root];
		ll s = 0;
		if(!st)
		{
			for(int i = 1 ; i <= n ; i += 2)
			{
				s += 1LL*arr[i];
			}
		}
		else for(int i = n ; i >= 1 ; i -= 2) s += 1LL*arr[i];

		printf("Case %d: %lld\n",tc++,s);
	}


}


