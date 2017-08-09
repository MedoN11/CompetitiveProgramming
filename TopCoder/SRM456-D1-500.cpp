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
#include<complex>
#include<string>
#include<vector>
#include<numeric>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
using namespace std;
#define ll  long long

struct CutSticks
{
	double maxKth(vector<int> &sticks,int C,int K);
};
typedef long double ld;
int n,c,k;
vector<int> v;
long double EPS = 1e-6;
int can(long double x)
{
	ll has = 0;
	ll tmp_c = c;
	ll before = 0;
	for(int i = 0 ; i < n ; ++i)
	{
	    ll pieces = max(0LL, (long long)((v[i] / (1.0*x) - 1)));
		if(v[i] >= x) ++before;
		int take = min(tmp_c,pieces);
		tmp_c -= take;
		before += take;
	}
	return before >= k;
	//cout << x << " " << ind << "\n";


}
double CutSticks::maxKth(vector<int> &vv,int c_,int k_)
{
	v = vv; c = c_, k = k_;
	n = v.size();
	sort(v.rbegin(),v.rend());
	//cout << can(34.92) << "\n";
	//	for(int i = 0 ; i < 50 ; ++i)
	//		cerr << can(i) << "\n";
	ld lo = 0.0,hi = 1e11;
	double ans = 0.0;
	for(int i = 0 ; i < 200 ; ++i)
	{

		long double mid = lo +(hi - lo) / 2.0;
		if(can(mid))
			ans = mid, lo =mid;
		else hi = mid;
	}

	return ans;
}
