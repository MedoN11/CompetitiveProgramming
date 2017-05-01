#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<set>
#include<map>
#include<list>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<memory.h>
#include<iomanip>
#include<cmath>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#define ll long long
using namespace std;


/*

  Category : Binary Search + Bruteforce

  for all i
  Try to win i games, greedily select the chepeast i options then spend the rest on draws.


 */
int n,g;
vector<int> v;
int main()
{


	while(scanf("%d %d",&n,&g) != EOF)
	{
		v.clear();
		int a,b;
		int pts = 0;
		int best = 0;
		for(int i = 0 ; i < n ; ++i)
		{
			scanf("%d %d",&a,&b);
			if(a > b)
			{
				pts += 3;
				continue;
			}
			v.push_back(b - a);

		}
		sort(v.begin(),v.end());

		int sz = v.size();
		for(int i = 1 ; i < sz;  ++i)
			v[i] += v[i - 1];
		for(int i = 0 ; i <= sz ; ++i)
		{
			int curr = pts;
			int rem = g;
			if(i > 0)
			{
				int pay = v[i - 1] + (i);
				if(pay  > rem)
					continue;
				curr += i * 3;
				rem -= pay;
			}

			int lo = i;
			int hi = sz - 1;
			int ans = -1;
			int bef = 0;
			if(i > 0) bef = v[i - 1];
			while(lo <= hi)
			{
				int mid = lo + (hi - lo) / 2;


				if(v[mid] - bef <= rem)
				{

					ans = mid;
					lo = mid + 1;
				}
				else hi = mid - 1;
			}


			if(ans != -1)
				curr += ans - i + 1;

			best = max(best,curr);

		}
		printf("%d\n",best);
	}

}
