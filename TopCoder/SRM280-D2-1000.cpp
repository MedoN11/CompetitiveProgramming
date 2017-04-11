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
#define fast std::ios_base::sync_with_stdio(false);
int cap = 0;
struct GroupingNumbers
{
	double minRange(vector<int> v,int n);
};
double ans = 1 << 30;
int n;
vector<int> v;
vector<int> grp[20];

void backtrack(int ind)
{
	if(ind == sz(v))
	{
		double mini = 1 << 30;
		double maxi = 0;
		for(int i = 0 ; i < n ; ++i)
		{
			if(grp[i].size() == 0)
				return;
			double loc = 0;
			REP(j,grp[i]) loc += grp[i][j];
			loc /= double((1.0*grp[i].size()));
			mini = min(mini,loc);
			maxi = max(maxi,loc);
		}
		ans = min(ans,maxi - mini);
		return;

	}
	for(int i = 0 ; i < n ; ++i)
	{
		grp[i].push_back(v[ind]);
		if(grp[i].size() <= cap)
			backtrack(ind + 1);
		grp[i].pop_back();
	}
	for(int i = 0 ; i < n ; ++i)
	{
		grp[i].push_back(v[ind]);
		if(grp[i].size() <= cap)
			backtrack(ind + 1);
		grp[i].pop_back();
	}
}
double GroupingNumbers::minRange(vector<int> vv,int nn)
{
	v = vv; n = nn;
	cap = v.size() / n; if(v.size() % n) ++cap;
	backtrack(0);
	return ans;

}
