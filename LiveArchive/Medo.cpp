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
int n,m;
const int maxn = 1005000;
int seq[maxn << 1];
vector<int>  v;
int L[maxn << 1],R[maxn << 1];
int main()
{
	scanf("%d",&n);
	v.resize(n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&v[i]);
	for(int i = 0 ; i < n ; ++i) seq[i] = v[i];

	for(int i = n , j = 0 ; i < 2 * n ; ++i,++j)
		seq[i] = v[j];
	for(int i = 0; i < 2 * n ; ++i) R[i] = 2*n - 1,L[i] = 0;
	stack<int> s;
	for(int i = 0 ; i < 2 * n ; ++i)
	{
		while(!s.empty() && seq[s.top()] < seq[i])
		{
			R[s.top()] = i - 1;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()) s.pop();
	for(int i = 2 * n  - 1 ; i >= 0 ; --i)
	{
		while(!s.empty() && seq[s.top()] < seq[i])
		{
			L[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}
	long long res = 0;
	for(int i = 0 ; i < n ; ++i)
	{
		cerr << i << " " << L[i] << " " << R[i] << "\n";
		// add to the left
		res += L[i] - i;
		int bound = L[i] + n;
		int till = min(bound,R[i]);
		res += till - i;
	}
	printf("%lld\n",res);
}


