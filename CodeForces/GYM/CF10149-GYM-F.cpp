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
int n,p,k;
int nxt[500002];
int lst[500002];
bool here[500002];
int v[500002];
map<int,int> cord;
int main()
{



	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int p,k;
		n = 500002;
		memset(nxt,0,sizeof(nxt));
		memset(lst,0,sizeof(lst));
		memset(here,0,sizeof(here));
		memset(v,0,sizeof(v));
		scanf("%d %d",&p,&k);
		cord.clear();
		map<int,int> cord;
		for(int i = 0 ; i < p ; ++i)
		{
			scanf("%d",&v[i]); --v[i];
			cord[v[i]] = 1;
		}
		int ind = 0;
		for(map<int,int>::iterator it = cord.begin() ; it != cord.end() ; it++)
		{
			it->second = ind++;
		}
		for(int i = 0 ; i < p ; ++i)
		{
			v[i] = cord[v[i]];
		}
		for(int i = 0 ; i < n ; ++i)
		{
			lst[i] = p;
			here[i] = 0;

		}

		for(int i = p - 1 ; i >= 0 ; --i)
		{
			nxt[i] = lst[v[i]];
			lst[v[i]] = i;
		}

		priority_queue<pair<int,int> > PQ;
		int bag = 0;
		int moves = 0;
		for(int i = 0 ; i < p ; ++i)
		{
			if(here[v[i]])
			{
				PQ.push(make_pair(nxt[i],v[i]));
				continue;
			}
			if(bag < k)
			{
				++moves; ++bag;
				here[v[i]] = 1;
				PQ.push(make_pair(nxt[i],v[i]));

			}
			else
			{
				pair<int,int> e = PQ.top(); PQ.pop();
				here[e.second] = 0;
				++moves;
				here[v[i]] = 1;
				PQ.push(make_pair(nxt[i],v[i]));
			}

		}

		printf("%d\n",moves);
	}

}
