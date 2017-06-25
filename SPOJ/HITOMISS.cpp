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
#define pb push_back
int p[11];
int at[11];
int n;

int main()
{
	int t;
	scanf("%d",&t);
	int tc = 1;
	while(t--)
	{
		deque<int> q[11];
		scanf("%d",&n);
		for(int i = 0 ; i < 52 ; ++i)
		{
			int x;
			scanf("%d",&x);
			q[0].push_back(x - 1);
		}
		for(int i = 0 ; i  < n ; ++i) at[i] = 0;
		bool bad = false;
		int lim = 100001;
		while(lim--)
		{
			for(int i = 0  ; i < n ; ++i)
			{
				if(sz(q[i]) == 0)
					continue;
				int curr = q[i].front();
				q[i].pop_front();
				if(curr == at[i])
				{
					if(i + 1 < n) q[i + 1].push_back(curr);
					p[i] = curr;
				}
				else q[i].push_back(curr);
				++at[i];
				at[i] %= 13;
			}

		}
		for(int i = 0  ; i < n ; ++i)
			bad |= sz(q[i]) > 0;
		printf("Case %d: ",tc++);
		if(bad) printf("unwinnable\n");
		else
		{
			printf("%d",p[0] + 1);
			for(int i = 1 ; i < n ; ++i)
				printf(" %d",p[i] + 1);
			printf("\n");
		}
	}
}

