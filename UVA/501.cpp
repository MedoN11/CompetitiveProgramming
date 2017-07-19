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


typedef long long ll;
typedef pair<int,ll> pii;
int arr[30001];
int n,m;
multiset<int> s;
int t;
int main()
{
	scanf("%d",&t);
	bool f = 0;
	while(t--)
	{
		s.clear();
		f = 1;
		scanf("%d %d",&n,&m);
		for(int i = 0 ; i < n ; ++i)
		{
			scanf("%d",&arr[i]);
		}

		s.insert(arr[0]);
		multiset<int>::iterator it;

		int ind = 1;
		for(int i = 0 ; i < m ;++i)
		{
			int till;
			scanf("%d",&till);
			while(till > ind)
			{
				s.insert(arr[ind]);
				if(!f)
				{
					if(*it > arr[ind])
						--it;
				}
				ind++;
			}
			if(f)
				it = s.begin(),f = 0;
			else
				it++;
			printf("%d\n",*it);

		}

	}
}

