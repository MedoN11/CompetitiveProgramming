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
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int n,m;
vector<int> v[2000];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < n ; ++i)
	{
		int x;
		for(int j = 0 ; j < m ; ++j)
		{
			scanf("%d",&x);
			v[j].push_back(x);
		}
	}
	for(int j = 0 ; j < m ; ++j)
		sort(v[j].begin(),v[j].end());

	for(int j = 0 ; j < m ; ++j)
	{
		printf("%d ",v[j][(n - 1) / 2]);
	}


}
