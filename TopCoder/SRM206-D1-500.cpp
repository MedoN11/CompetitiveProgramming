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
#include<complex>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
using namespace std;
typedef pair<int,int> pii;
vector<pii> pts;
int n;
int H,W;
vector<int> ans;
ll res = -1;


vector<int> largestRectangle(int w,int h,vector<int> x,vector<int> y)
{
	n = sz(x);
	x.pb(-1); x.pb(w); y.pb(-1); y.pb(h);

	// bounds by X
	ll res = 0;
	bool bad = 0;
	for(int i = 0 ; i < sz(x) ; ++i)
	{
		for(int j = 0 ; j < sz(x) ; ++j)
		{
			int x1 = x[i] + 1, x2 = x[j] - 1;
			if(x1 > x2)
				continue;
			if(x2 >= w)
				continue;
			for(int k = 0 ; k < sz(y) ; ++k)
			{
				int y1 = y[k] + 1;
				for(int z = 0 ; z < sz(y) ; ++z)
				{
					int y2 = y[z] - 1;
					if(y1 > y2)
						continue;
					if(y2 >= h)
						continue;
					bad = 0;
					for(int i = 0 ; i < n &&!bad ; ++i)
					{
						if(x[i] >= x1 && x[i] <= x2 && y[i] >= y1 && y[i] <= y2)
							bad = 1;
					}
					if(!bad)
					{
						ll area = (x2 - x1 + 1) * (y2 - y1 + 1);
						if(res == area)
						{
							if(y1 < ans[0])
							{
								ans.clear();
								ans.pb(y1); ans.pb(x1); ans.pb(x2 - x1 + 1); ans.pb(y2 - y1 + 1);
							}
							else
							{
								if(y1 == ans[0] && x1  < ans[1])
								{
									ans.clear();
									ans.pb(y1); ans.pb(x1); ans.pb(x2 - x1 + 1); ans.pb(y2 - y1 + 1);
								}
								else
								{
									if(y1 == ans[0] && x1 == ans[1] && (x2 - x1  + 1) > ans[2])
									{
										ans.clear();
										ans.pb(y1); ans.pb(x1); ans.pb(x2 - x1 + 1); ans.pb(y2 - y1 + 1);
									}
								}
							}
						}
						else
						{
							if(res < area)
							{
								res = area;
								ans.clear();
								ans.pb(y1); ans.pb(x1); ans.pb(x2 - x1 + 1); ans.pb(y2 - y1 + 1);
							}
						}
					}
				}
			}
		}
	}
	cerr << res << "\n";
	swap(ans[0],ans[1]);
	return ans;
}
int main()
{
	int n;
	cin >> n;
	vector<int> xx,yy; xx.resize(n),yy.resize(n);
	for(int i = 0 ; i < n ; ++i) cin >> xx[i];
	for(int i = 0 ; i < n ; ++i) cin >> yy[i];
	int h,w;
	cin >> w >> h;
	vector<int> v = largestRectangle(w,h,xx,yy);
	cerr << v[0] <<" "<< v[1] <<" " << v[2] <<" " << v[3] << " " << res << "\n";


}

