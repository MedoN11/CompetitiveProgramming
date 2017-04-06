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



typedef pair<int,int> ii;
#define MAXN 100005
int t;
int fenwick[100005];

void update(int ind,int val)
{
	while(ind < MAXN)
	{
		fenwick[ind] = min(fenwick[ind],val);
		ind += ind & - ind;
	}
}
int getMin(int ind)
{
	int mini = 1 << 30;
	while(ind > 0)
	{
		mini = min(mini,fenwick[ind]);
		ind -= ind & -ind;
	}
	return mini;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{

		vector<pair<int,ii> > v;
		for(int i = 0 ; i < MAXN ; ++i)
			fenwick[i] = 1 << 30;
		int n; scanf("%d",&n);
		v.resize(n);
		for(int i = 0 ; i < n ; ++i)
			scanf("%d %d %d",&v[i].first,&v[i].second.first,&v[i].second.second);
		sort(v.begin(),v.end());
		int ret = 0;


		for(int i = 0 ; i < n ; ++i)
		{
			bool bad = 0;
			int best = getMin(v[i].second.first);

			if(best < v[i].second.second)
				bad = 1;
			if(!bad)
				++ret;
			update(v[i].second.first,v[i].second.second);
		}

		printf("%d\n",ret);
	}
}
