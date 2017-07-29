#include <iostream>
#include <cstdio>
#include<complex>
#include<string>
#include<vector>
#include<numeric>
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
using namespace std;
pair<pair<long long,long long>,int> arr[3*(100000)];
// Math
// Editorial is clear
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{

		scanf("%d",&n); n = (n << 1) - 1;
		long long tot = 0;
		for(int i = 1 ; i <= n ; ++i)
		{
			scanf("%lld %lld",&arr[i].first.first,&arr[i].first.second); arr[i].second = i;
			tot += arr[i].first.second;
		}
		puts("YES");
		std::sort(arr + 1, arr + n + 1);
		long long odd = 0, even = 0;
		for(int i = 1 ; i <= n ; ++i)
		{
			if(i & 1)
				odd += arr[i].first.second;
			else even += arr[i].first.second;
		}
		long long must = tot / 2LL; if(tot & 1) must++;
		if(odd >= must)
		{
			for(int i = 1 ; i <= n ; i += 2)
				printf("%d ",arr[i].second);
			puts("");
		}
		else
		{
			for(int i = 2 ; i <= n ; i += 2)
				printf("%d ",arr[i].second);
			printf("%d",arr[n].second);
			puts("");
		}

	}
}
