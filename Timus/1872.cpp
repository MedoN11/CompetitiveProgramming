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

using namespace std;


vector<pii> room;
vector<pair<pii,int> > intervals;

bool fits(int i,int j)
{
	// room i fits in interval j
	return intervals[j].first.second >= room[i].first && room[i].first >= intervals[j].first.first;
}
int n,m;
int matching[5001];
int res[5001];
int greedyMatching()
{
	memset(matching,-1,sizeof(matching));
	for(int i = 0 ; i < n ; ++i)
	{
		int sol = -1;
		int min_r = 1 << 30;
		for(int j = 0 ; j < m ; ++j)
		{

			if(intervals[j].first.first > room[i].first || matching[j] != -1)
				continue;
			if(min_r > intervals[j].first.second && intervals[j].first.second >= room[i].first)
				min_r = intervals[j].first.second,sol = j;

		}
		if(sol == -1) return -1;
		matching[sol] = i;
	}
	return n;
}
int main()
{
	scanf("%d",&n); m = n;
	room.resize(n), intervals.resize(n);
	for(int i = 0 ; i < n ; ++i) scanf("%d",&room[i].first),room[i].second = i;
	for(int j = 0 ; j < m ; ++j) scanf("%d %d",&intervals[j].first.first,&intervals[j].first.second),intervals[j].second = j;
	sort(all(room));
	sort(all(intervals));
	int res1 = greedyMatching();
	//cerr << res1 << "\n";
	//for(int i = 0 ; i < n ;++i) cout << room[matching[i]].second << "\n";
	if(res1 != n)
	{
		puts("Let's search for another office.");
	}
	else
	{

		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = i + 1 ; j < n ; ++j)
			{
				int m1 = matching[i], m2 = matching[j];
				if(fits(m2,i) && fits(m1,j))
				{

					puts("Ask Shiftman for help.");
					return 0;
				}
			}
		}

		for(int i = 0 ; i < n ; ++i) res[intervals[i].second] = room[matching[i]].second;
		printf("Perfect!\n");
		printf("%d",res[0] + 1);
		for(int i = 1 ; i < n;  ++i) printf(" %d",res[i] + 1);

	}

}
