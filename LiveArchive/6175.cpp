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
using namespace std;
int t;
double L,R;
// DP + probability
// define solve(rem,r) as the expectation of have rem steps remaining and rightmost position r
double dp2[1001][1001 + 1001];
double solve2(int rem,int r)
{
	if(rem == 0)
		return r;
	double &ret = dp2[rem][r + 1001];
	if(ret == ret)
		return ret;
	double left = 1.0*L*solve2(rem - 1,max(0,r - 1));
	double right =  R*solve2(rem - 1,r + 1);
	return ret =  left + right + (1.0 - R - L) * solve2(rem - 1,r);
	return ret;

}
int main()
{

	ios
	cin >> t;
	int tc;
	int steps;
	cout << fixed << setprecision(4);
	while(t--)
	{
		cin >> tc >> steps >> L >> R;
		//memset(dp2,-1,sizeof(dp2));
		if(L + R == 0)
			cout << "0.0000" << "\n";
		else
		{
			memset(dp2,-1,sizeof(dp2));
			cout << tc << " " << solve2(steps,0) << "\n";
		}

	}

}
