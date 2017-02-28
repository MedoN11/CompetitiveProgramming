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
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
using namespace std;
#define ll long long
#define MAXN (int)(10e4 + 1)
#define inf 1 << 30
int t,n;
vector<pair<int,int> > v;
int DP[2][3003][3003];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		v.clear();
		scanf("%d",&n);
		int sum = 0;
		for(int i = 0 ; i < n ; ++i)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			v.push_back(make_pair(a,b));
			sum += b;
		}

		sort(v.begin(), v.end());
		reverse(v.begin(),v.end());


		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 0 ; j <= sum ; ++j)
				for(int k = 0 ; k <= sum ; ++k)
					DP[i][j][k] = inf;
		DP[0][0][0] = 0;
		for(int i = 1 ; i < n ; ++i)
		{

			for(int sum1 = 0 ; sum1 <= sum ; ++sum1)
			{
				for(int sum2 = 0; sum2  <= sum; ++sum2)
				{

					DP[i & 1][sum1][sum2] = inf;


				}
			}
			for(int sum1 = 0 ; sum1 <= sum ; ++sum1)
			{
				for(int sum2 = 0; sum2 <= sum; ++sum2)
				{

					int curr = v[i].second;
					if(sum1 - curr >= 0 && DP[(i - 1) & 1][sum1 - curr][sum2] != inf)
					{
						int opt1 = DP[(i - 1) & 1][sum1 - curr][sum2];
						if(sum1 - curr == 0)
							opt1 += v[i].first;
						DP[i & 1][sum1][sum2] = min(opt1,DP[i & 1][sum1][sum2]);
					}
					if(sum2 - curr >= 0 && DP[(i - 1) & 1][sum1][sum2 - curr] != inf)
					{
						int opt1 = DP[(i - 1) & 1][sum1][sum2 - curr];
						if(sum2 - curr == 0)
							opt1 += v[i].first;

						DP[i & 1][sum1][sum2] = min(opt1,DP[i & 1][sum1][sum2]);

					}
					DP[i & 1][sum1][sum2] = min(DP[i & 1][sum1][sum2],DP[(i - 1) & 1][sum1][sum2]);

				}
			}
		}

		int ind = (n - 1) & 1;
		int ans = inf;
		for(int sum1 = 1 ; sum1 <= sum ; ++sum1)
		{
			for(int sum2 = 1; sum2 <= sum; ++sum2)
			{
				if(DP[ind][sum1][sum2] != inf)
				{
					int price = v[0].first + DP[ind][sum1][sum2];
					ans = min(ans,price * max(sum - (sum1 + sum2),max(sum1,sum2)));
				}
			}
		}
		cout << ans << "\n";


	}
}
