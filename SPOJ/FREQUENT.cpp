#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define fast std::ios_base::sync_with_stdio(false);
#define ll long long
#define MAXN 100001
using namespace std;
int arr[MAXN];
struct Node
{
	int i,j;
	int leftFreq,rightFreq,leftVal,rightVal,ans;

	Node()
	{
		i = 0, j = 0,leftFreq = 0,rightFreq = 0,ans = 0,leftVal = 0,rightVal= 0;
	}
	Node(int i_,int j_,int lf,int rf,int lv,int rv,int m)
	{
		i = i_; j = j_; leftFreq = lf;
		rightFreq = rf;
		leftVal = lv; rightVal = rv;
		ans = m;
	}

};


Node merge(Node &a, Node &b)
{
	Node ret;
	ret.leftFreq = a.leftFreq; ret.rightFreq = b.rightFreq;
	if(a.leftVal == a.rightVal && b.leftVal == a.rightVal)
		ret.leftFreq += b.leftFreq;

	if(b.rightVal == b.leftVal && a.rightVal == b.leftVal)
		ret.rightFreq += a.rightFreq;
	ret.ans = max(a.ans,b.ans);
	if(a.rightVal == b.leftVal)
	{
		ret.ans = max(ret.ans,a.rightFreq + b.leftFreq);
	}
	ret.leftVal = a.leftVal;
	ret.rightVal = b.rightVal;
	return ret;
}
struct Node tree[4*MAXN];


void build(int ind,int a,int b)
{
	if(a == b)
	{
		tree[ind] = Node(a,b,1,1,arr[a],arr[a],1);
	//	cerr << tree[ind].i << " " << tree[ind].j << " " << tree[ind].leftFreq << " " << tree[ind].rightFreq << " " << tree[ind].ans << endl;

		return;
	}
	int mid = (a + b) / 2;
	build(ind << 1,a,mid);
	build((ind << 1) + 1,mid + 1,b);
	tree[ind] = merge(tree[ind << 1],tree[(ind << 1) + 1]);
	tree[ind].i = a; tree[ind].j = b;
	//cerr << tree[ind].i << " " << tree[ind].j << " " << tree[ind].leftFreq << " " << tree[ind].rightFreq << " " << tree[ind].ans << endl;

}

Node query(int ind,int a,int b)
{

	int i = tree[ind].i; int j = tree[ind].j;
	//cerr << i << " " << j << endl;
	if(a <= i && j <= b)
		return tree[ind];

	Node lf = Node(); Node rt = Node();
	if(a > j)
		return lf;
	if(b < i)
		return lf;
	int mid = (i + j) / 2;
	if(a <= mid)
	{
		lf = query((ind << 1),a,b);
	}
	if(b > mid)
		rt = query((ind << 1) + 1,a,b);
	Node loc = merge(lf,rt);
	return loc;
}
int main()
{
	fast
	int n,q;
	while(1)
	{
		cin >> n; if(!n) break;
		cin >> q;
		for(int i = 1 ; i <= n ; ++i)
			cin >> arr[i];
		build(1,1,n);

		int i,j;
		while(q--)
		{
			cin >> i >> j;
			if(i == j)
				cout << "1" << "\n";
			else cout << query(1,i,j).ans << "\n";
		}
	}

}

