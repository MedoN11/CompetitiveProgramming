
#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
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
#include<algorithm>
#include <cassert>
#include <stack>
#include<cstring>
#include <cmath>
#include <complex>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <cstdio>
#include<map>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
using namespace std;
#define ll long long
int n;
int t;
vector<double> v;

// sort, and try every 3 consecutive entries
// why does that work?
// check triangle inquality
// let i <= j <= k <= f
// assume i + j >= k
// we are trying to prove that if there exists f > k such that i + j >= f
// then j + k >= f..if we prove it suffices to try every 3 consecutive entries.
// we know that f - k <= f - i (>>> 1)
// from i + j >= f ..we can see j >= f - i (>>> 2)
// from 1 and 2 we see j >= f - k
// so we arrive at j + k >= f

// to get triangle area we use hero's formula

int main()
{
	scanf("%d",&t);;
	while(t--)
	{
		v.clear();
		scanf("%d",&n);
		for(int i = 0 ; i < n ; ++i)
		{
			double x;
			scanf("%lf",&x);
			//cin >> x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		double all = 0.0;
		for(int i = 0 ; i < n - 2 ; ++i)
		{

			if(v[i] + v[i + 1] >= v[i + 2])
			{
				double p = (v[i] + v[i + 1] + v[i + 2]) / 2.0;
				double curr = p;
				curr *= (p - v[i]);
				curr *= (p - v[i + 1]);
				curr *= (p - v[i + 2]);
				curr = sqrt(curr);
				all = max(all,curr);
			}
		}

		if(all == -1)
			all = 0.00;
		printf("%.2f\n",all);
	}

}


