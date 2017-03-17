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
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;
int t,n;
vector<pair<double,double> > v;
double run_me,cycle_me;

double f(double x)
{
	double mn = 1 << 29;
	REP(j,v)
	{
		mn = min(mn,(double) ((1.0*x) / v[j].first) + (double)((1.0*t - x) / v[j].second));
	}
	double me = ( (1.0*x) / run_me) + (1.0*t - x) / cycle_me;
	return -1*(me - mn);
}
pair<double, double> ternaryReal()
{
	double left = 0, right = t; // set your range
	for(int i = 0 ; i < 500 ;++i)
	{ // stop when reaching almost right = left
		double g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;

		if (f(g) > f(h)) // use > if f increase then decrease
			right = h;
		else
			left = g;
	}

	return make_pair(left, f(left));

}
int main()
{
	fast
	while(cin >> t)
	{
		v.clear();
		cin >> n;
		double run,cycle;
		for(int i = 0 ; i < n - 1 ; ++i)
		{
			cin >> run >> cycle;
			v.push_back(make_pair(run,cycle));
		}

		cin >> run_me >> cycle_me;
		std::cout << std::fixed;
		 std::cout << std::setprecision(2);
		pair<double,double> ans = ternaryReal();
		if(ans.second < 0)
		{
			cout << "The cheater cannot win." << endl;
			continue;
		}
		cout << "The cheater can win by ";
		cout <<(int)(ans.second*3600 + 0.5)<<" seconds ";
		cout <<"with r = " << (ans.first)<<"km and k = " << (1.0*t - ans.first)<<"km."<<endl;


	}


}

