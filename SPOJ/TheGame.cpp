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
#define MAXN 1000001
int tc;
int main()
{
	int n;
	cin >> tc;
	while(tc--)
	{
		int x = 0;
		scanf("%d",&n);
		int s;
		for(int i = 1 ; i <= n ; ++i)
		{
			scanf("%d",&s);
			int grund = 0;
			for(int j = 1 ; j <= s ; ++j)
				grund ^= i;
			x ^= grund;
		}

		if(x)
			puts("Tom Wins");
		else puts("Hanks Wins");
	}


}
