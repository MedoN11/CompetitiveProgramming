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
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define ll  long long
using namespace std;
#define MAXN 110001
int c,n;
double DP[41];
long long pascals[50][50];
double solve(int done)
{

	if(done == c)
		return 0;
	int rest = c - done;
	double &ret = DP[done];
	if(ret == ret)
		return ret;
	ret = 1;
	double p2 = (1.0*pascals[done][n]) / pascals[c][n];

	for(int i = 1 ; i <= rest ; ++i)
	{
		if(n - i > done || i > n)
			continue;
		double den = pascals[c][n];
		double num = ((double)pascals[rest][i] * (double)pascals[done][n - i]);
		double p1 = (double)(1.0*num)/den;
		ret +=  double(p1) * double((solve(done + i)));

	}
	ret /= (1 - p2);
	return ret;

}


#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
int main()
{


	int tc; cin >> tc;
	int t = 1;;
	while(tc--)
	{
		cin >> c >> n;
		memset(DP,-1,sizeof(DP));
		pascals[0][0] = 1;
		for(int i = 1 ; i <= 41 ; ++i)
		{
			pascals[i][0] = 1;
			for(int j = 1; j <= 41 ; ++j)
			{
				pascals[i][j] = 1LL*pascals[i - 1][j] + pascals[i - 1][j - 1];
			}
		}
		printf("Case #%d: %.12f\n",t++,solve(0));
	}

}
