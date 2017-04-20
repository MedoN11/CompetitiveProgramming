#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
using namespace std;
#define ll long long
typedef long double ld;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define clr(x) memset(x,0,sizeof(x));
typedef vector<int> vi;
#include <iostream>
#include <cmath>
#include <complex>
#include <cassert>
using namespace std;

map<string,int> mp;
int floyd[51][51];
int n,e;
int ind = 0;
int get(string &s)
{
	if(mp.find(s) == mp.end())
		mp[s] = ind++;
	return mp[s];
}
int main()
{
	int tc = 1;
	while(scanf("%d %d",&n,&e))
	{
		if(!n && !e)
			return 0;
		ind = 0; mp.clear();
		for(int i = 0 ; i < 51 ; ++i)
			for(int j = 0 ; j < 51 ; ++j)
				floyd[i][j] = 1 << 25;
		string a,b;
		int u,v;
		while(e--)
		{
			cin >> a >> b;
			u = get(a); v = get(b);
			floyd[u][v] = floyd[v][u] = 1;
		}
		for(int k = 0 ; k < n ; ++k)
		{
			for(int i = 0 ; i < n ; ++i)
			{
				for(int j = 0 ; j < n ; ++j)
				{
					floyd[i][j] = min(floyd[i][k] + floyd[k][j],floyd[i][j]);
				}
			}
		}
		int mx = -1;
		for(int i = 0 ; i < n ; ++i)
			for(int j = 0 ; j < n ; ++j)
				mx = max(mx,floyd[i][j]);
		printf("Network %d: ",tc++);
		if(mx == 1 << 25)
			printf("DISCONNECTED");
		else printf("%d",mx);
		printf("\n\n");
	}
}
