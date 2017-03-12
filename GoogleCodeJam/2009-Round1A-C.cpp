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

 In such cases of expectation with cycling it can be solved as follows for "some" recurrences. Consider E(X) as expectation of X. Now say E(X) = P1*E(X) + P2*E(Y) where Y > X, and P1 is the probability of ending at where we are, and P2 is probability of going to another place ( Remember Y > X ). Now if you write it as E(X) - P1*E(X) = P2*E(Y), you can see that E(X) = P2*E(Y) / 1 - P1. So now you don't need to worry about cycles, and the recurrence is sequential. If I understand "depth" incorrectly, someone let me know. Now as an editorial of this problem, I remember I used DP where the editorial solved it by a system of linear equations ( something like this). Now let's solve this by DP. Let our state be solve(x) how many distinct cards we have so far. If we already have N cards then we can see that the expectation is indeed zero. If not then we know that we have N - x new cards, and x olds ones. Now assume we get a new cards pile of size C, we just need to enumerate all possible cases of cards we might get with pascal's triangle. ( 1 new card 2 new cards..etc). Case of zero new cards is cyclic, and can be solved by writing the recurrence like above. Now for the transitions, you can see that for each state no matter where we are going the turn just increased by one, so E(X) = 1 + Summations of (all reachable states * their probability). I'm editing the code now, if someone has trouble understanding it let me know.
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
