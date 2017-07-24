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
// Adhoc Problem
vector<int>  seq;
int L[maxn],R[maxn];
int tmp_dp[maxn];
int main_dp[maxn];
map<int,int> cord;
int a[maxn];
int main()
{
	scanf("%d",&n);
	seq.resize(n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&seq[i]),cord[seq[i]] =1;
	int ind = 0;
	for(map<int,int>::iterator it = cord.begin() ; it != cord.end() ; it++) it->second = ind++;
	rotate(seq.begin(),max_element(all(seq)),seq.end());
	int cnt = 0;
	int mx = *max_element(all(seq));
	seq.pb(mx);
	for(int i = 0 ; i < n ; ++i)
		if(seq[i] == mx)
			cnt++;

	for(int i = 0 ; i < n ; ++i) a[i] = cord[seq[i]];

	for(int i = 0; i <= n ; ++i)
	{
		R[i] = n ,L[i] = 0;
	}
	stack<int> s;
	for(int i = 0 ; i <= n ; ++i)
	{

		main_dp[i] = tmp_dp[a[i]];
		tmp_dp[a[i]]++;
		while(!s.empty() && seq[s.top()] < seq[i])
		{
			R[s.top()] = i;
			tmp_dp[a[s.top()]]--;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()) s.pop();
	for(int i = n ; i >= 0 ; --i)
	{


		while(!s.empty() && seq[s.top()] < seq[i])
		{
			L[s.top()] = i;

			s.pop();
		}
		s.push(i);
	}

	long long res = 0;
	for(int i = 0 ; i < n ; ++i)
	{
		if(seq[i] == seq[0])
			continue;
		//cerr << (i + 1) <<" " << (cntR[i] + 1) << "\n";
		res += main_dp[i];
		res += 2;
		if(L[i] == 0 && R[i] == n)
		{
			res--;
		}

	}
	res += (1LL*cnt*(cnt - 1))/2LL;

	printf("%lld\n",res);
}


