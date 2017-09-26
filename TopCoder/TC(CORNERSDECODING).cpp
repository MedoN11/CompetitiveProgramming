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
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
const bool debug = true;
const int maxn = 100005;
typedef pair<double, double> point;
// Editorial : https://apps.topcoder.com/forums/?module=Thread&threadID=684537

// Line Sweep
struct CornersDecoding
{
	ll blackPixels(vector<int> rows,vector<int> cols);
};
ll CornersDecoding::blackPixels(vector<int> rows, vector<int> cols)
{
	int n = sz(rows);
	vector<pii> v;
	for (int i = 0; i < n; i++)
		v.pb(make_pair(rows[i], cols[i]));

	sort(all(v));
	set<int> s;

	int ptr = 0;
	int lasty = 0;
	long long ans = 0;
	while (ptr < n)
	{
		int hor = 0;
		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			int l = *it++;
			int r = *it++;
			hor += r - l;
		}
		ans += (ll) hor * (v[ptr].first - lasty);
		lasty = v[ptr].first;

		int ptr2 = ptr;
		while (ptr2 < n && v[ptr2].first == v[ptr].first)
		{
			if (s.count(v[ptr2].second))
			{
				s.erase(v[ptr2].second);
			}
			else
			{
				s.insert(v[ptr2].second);
			}
			ptr2++;
		}
		if ((ptr2 - ptr) & 1)
			return -1;
		ptr = ptr2;
	}
	if (sz(s) > 0)
		return -1;
	return ans;
}

