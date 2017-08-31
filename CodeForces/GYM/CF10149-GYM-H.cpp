
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
typedef pair<pii,int> state;
vector<int> left1;
pair<bool,vector<int> > solve(int n,int s)
		{


	int sz = n / 2;
	left1.clear();
	if(s == 0)
		return make_pair(0,left1);

	for(int i = 0 ; i < sz ; ++i)
	{
		left1.pb(9);
		s -= 2 * 9;
	}
	if(s == 0) return make_pair(1,left1);
	if(s > 0 || (s * -1) % 2 != 0)
		return make_pair(0,left1);
	int pos = sz - 1;
	//cerr << s << "\n";
	while(pos >= 0)
	{
		int rem = s * -1;
		int take = min(rem / 2,pos == 0 ? 8 : 9);
		left1[pos] -= take;
		s += 2 * take;
		//cerr << s << "\n";
		if(s == 0)
			return make_pair(true,left1);
		--pos;
	}
	return make_pair(false,left1);
		}
int n,s;
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&n,&s);
		if(n == 1)
		{
			if(s <= 9)
				printf("%d\n",s);
			else printf("-1\n");
			continue;
		}
		if(n & 1)
		{
			int m = n - 1;
			bool done = 0;
			for(int j = 0 ; j <= 9 && !done ; ++j)
			{
				if(s - j >= 0)
				{
					pair<bool,vector<int> > f = solve(m,s - j);
					if(f.first)
					{
						done = 1;
						REP(i,f.second) printf("%d",f.second[i]);
						printf("%d",j);
						for(int i = sz(f.second) - 1; i >= 0 ; --i)
							printf("%d",f.second[i]);
					}
				}

			}
			if(!done)
				printf("-1");
		}
		else
		{
			pair<bool,vector<int> > f = solve(n,s);
			if(!f.first) printf("-1");
			else
			{
				REP(i,f.second) printf("%d",f.second[i]);
				for(int i = sz(f.second) - 1; i >= 0 ; --i)
					printf("%d",f.second[i]);
			}
		}
		puts("");
	}
}
