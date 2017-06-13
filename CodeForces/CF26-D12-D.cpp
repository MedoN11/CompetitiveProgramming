#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<utility>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<complex>
#include<algorithm>
#include<memory.h>
#include<string>
#include <unordered_map>
#include<vector>

#include<numeric>
using namespace std;


// total number of paths = (n + m, m)
// we need to start at (0,k) and end at (n + m, n - m + k)
// but some of these paths will go below x
// so to fix we count bad paths which are
// (n + m, n + m - k - 2)
// by replacing ups and downs we need to do in total and ignoring K
// it's the same as (n + m, m - k - 1)
// the rest is simplification of factorials and using this identity (n,k) = (n,n - k )
int main()
{
	int n,m,till;
	scanf("%d %d %d",&n,&m,&till);
	double res = 1.0;
	if(n - m + till < 0)
	{
		printf("0");
		return 0;
	}
	for(int k = 0 ; k <= till ; ++k)
	{
		res *= 1.0 * (m - k);
		res /= 1.0 * (n + k + 1);
	}
	printf("%.12f",1.0 - res);
}
