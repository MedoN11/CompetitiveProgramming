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
#define ll long long
using namespace std;
#define MAXN 100001
int n;
map<int,int> freq;
set<pair<int,int> > s;
void remove(int x)
{
	s.erase(make_pair(-freq[x],x));
	freq[x]--;
	if(freq[x] != 0)
	{
		s.insert(make_pair(-freq[x],x));
	}
	else freq.erase(x);
}
int getLeast(int x)
{
	int val = -1;
	if(freq.begin()->first != x)
		val = freq.begin()->first;
	else
	 val = freq.lower_bound(x + 1)->first;
	remove(val);
	return val;
}
int getMostFreq()
{
	int val = s.begin()->second;
	remove(val);
	return val;
}
bool bad(int m)
{
	return (-1*s.begin()->first) == (n - m + 1) / 2;
}
int main()
{

	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i)
	{
		int a; scanf("%d",&a);
		freq[a]++;
		if(freq[a] > (n + 1) / 2)
		{
			puts("-1");
			return 0;
		}
	}
	for(int i = 1 ; i <= (int)(10e5); ++i)
	{
		if(freq.find(i) != freq.end())
			s.insert(make_pair(-freq[i],i));
	}

	int lst = -1;
	for(int i = 1 ; i <= n ; ++i)
	{

		if(bad(i - 1) && (i & 1))
		{

			//cout << "Most ";
			printf("%d ",lst = getMostFreq());
			//cout << "\n";

		}
		else
		{
			//cout << "Least ";
			printf("%d ",lst = getLeast(lst));
			//cout << "\n";
		}
	}




}
