
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


