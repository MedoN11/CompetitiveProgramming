#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define all(x)          (x).begin(),(x).end()
#define sz(v)               ((int)((v).size()))
typedef pair<int,int> pii;
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
using namespace std;
const int maxn = 100000 + 1;
ll tree[maxn];
#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define all(x)          (x).begin(),(x).end()
#define sz(v)               ((int)((v).size()))
typedef pair<int,int> pii;
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
using namespace std;

ll mod = 1000*1000*1000 + 7;
int main()
{
	int t;
	scanf("%d",&t);
	ll curr,ele;
	ll sum;
	while(t--)
	{
		ll a,b,c,n;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);

		sum = 1;
		priority_queue<int> pq;
		priority_queue<int> tmp;
		pq.push(1);
		a %= mod,b%=mod,c%=mod;
		for(int i = 1 ; i < n ;++i)
		{
			//cerr << sum << "\n";
			ll curr = pq.top();
			ele = (1LL*(a*curr%mod));
			ele %= mod;
			ele += 1LL*(b * ((1LL*i + 1)%mod) + c);

			ele %= mod;
			//cerr << ele << "\n";
			int f = i + 1;
			f /= 2;
			if((i + 1) % 2 == 0) --f;
			//cerr << i/2 << " " << sz(pq) - 1 << "\n";
			if(sz(pq) - 1 < f)
			{
			if(tmp.empty() || -tmp.top() > ele)
			pq.push(ele);
			else pq.push(-tmp.top()),tmp.pop(),tmp.push(-ele);
			}
			else
			{
				tmp.push(-ele);
				if(pq.top() > -tmp.top())
				{
					int c = pq.top(); pq.pop();
					pq.push(-tmp.top()); tmp.pop();
					tmp.push(-c);
				}

			}

			sum += 1LL*ele;
		}
		printf("%lld\n",sum);
	}

}

