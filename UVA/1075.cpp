#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <unordered_map>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define ll  long long
#define EPS (1e-8);
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define neg(x) memset(x,-1,sizeof(x));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define endl "\n"
using namespace std;
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
typedef pair<int,int> ii;
#define MAXN 500

int n;
pair<int,int> arr[10];


bool can(double inc)
{
	double ptr = arr[0].first + inc;
	for(int i = 1 ; i < n ; ++i)
	{

		if(ptr > arr[i].second)
			return 0;
		if(ptr < arr[i].first)
			ptr = arr[i].first;
		ptr += inc;
	}
	return 1;
}
double medo()
{
	double lo = 0.0;
	double hi = 1440*60*60;
	double ans = 0.0;

	for(int i = 0 ; i < 50; ++i)
	{
		double mid = lo + (hi - lo) / 2.0;

		if(can(mid))
		{
			ans = mid;
			lo = mid;
		}
		else hi = mid;
	}
	return ans;
}
int main()
{

	double sol = 0.0;
	int tc = 1;
	while(scanf("%d",&n) && n)
	{
		sol = 0.0;
		for(int i = 0 ; i < n ; ++i)
		{
			scanf("%d %d",&arr[i].first,&arr[i].second);
			arr[i].first *= 60; arr[i].second *= 60;
		}
		sort(arr,arr + n);
		do
		{
			sol = max(sol,medo());
		}
		while(next_permutation(arr,arr + n));
		int s = (int)(sol + 0.5);
		int min = (s)/60; int sec = (((int)((s))) % 60);
		printf("Case %d: %d:%02d\n",tc++,min,sec);
	}
}
