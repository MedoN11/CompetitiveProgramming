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
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)


int n,m,q;
set<int> cover[21];
int f[21];
int cont[21];
vector<int> res;
int ans = -1;

void gen(int num,int rem,vector<int>  &v)
{


	if(rem < 0)
		return;

	if(rem == 0)
	{

		int tot = 0;
		REP(i,v)
		{

			//cerr << v[i] + 1 << " ";
			tot += f[v[i]];
		}
		//cerr << "\n";
		for(int j = 0 ; j < m ; ++j)
		{
			REP(i,v)
			{
				if(cover[j].find(v[i]) != cover[j].end())
				{
					tot += cont[j];
					break;
				}
							}
		}
		if(ans > tot)
			return;
		if(tot == ans)
		{
			bool f = 0;
			for(int i = sz(v) - 1 ; i >= 0 ; ++i)
			{
				if(v[i] < res[i])
					f = 1;
				if(v[i] > res[i])
					f = 0;
				if(v[i] != res[i])
					break;
			}
			if(f)
			{
				res.clear();
				REP(i,v)
				res.push_back(v[i]);
			}
		}
		else
		{
			ans = tot;
			res.clear();
			REP(i,v)
			res.push_back(v[i]);
		}


		return;
	}

	if(num >= 0)
	{

		v.push_back(num);
		gen(num - 1,rem - 1,v);
		v.pop_back();
		gen(num - 1,rem,v);

	}
}
int main()
{

	int tc = 1;
	int q;
	while(scanf("%d %d",&n,&q))
	{


		if(!(n + q))
			break;
		ans = -1;
		res.clear();
		for(int i = 0 ; i < n ; ++i)
			scanf("%d",&f[i]);

		scanf("%d",&m);
		for(int i = 0 ; i < m ; ++i)
			cover[i].clear();

		for(int j = 0 ; j < m ; ++j)
		{
			int x;
			scanf("%d",&x);
			int y;
			for(int k = 0 ; k < x ; ++k)
			{
				scanf("%d",&y);
				--y;
				cover[j].insert(y);
			}
			int give;
			scanf("%d",&give);
			set<int>::iterator it = cover[j].begin();
			for(;it!=cover[j].end();it++)
				f[*it] -= give;
			cont[j] = give;
		}

		vector<int> v;
		gen(n - 1,q,v);

		sort(res.begin(),res.end());
		printf("Case Number  %d\n",tc++);
		printf("Number of Customers: %d\n",ans);
		printf("Locations recommended:");
		REP(j,res) printf(" %d",res[j] + 1);


		printf("\n\n");

	}


}
