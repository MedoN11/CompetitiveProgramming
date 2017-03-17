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
int n,m;

double DP[1005];
int main()
{
	fast
	int n;
	double l,r;
	while(cin >> n)
	{
		if(!n)
			break;
		cin >> l >> r;
		double p = 1 - l - r;
		DP[0] = 0;
		DP[1] = 1.0 / p;
		for(int i = 2 ; i <= n ; ++i)
		{
			DP[i] = 1 << 30;
			for(int j = 0 ; j < i ; ++j)
			{
				int left = j , right = i - j - 1;
				DP[i] = min(DP[i],DP[left] + DP[right] + (1 + DP[left] * l + DP[right]*r) * 1.0/p);
			}
		}
		cout << fixed;
		cout << setprecision(2);
		cout << DP[n] << endl;
	}

}

