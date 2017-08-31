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
int n;
//typedef pair<pii,int> state;
//map<state,int> mp;
const int maxn = 100005;
//ll dp_reg_max[maxn][2];
//ll dp_reg_min[maxn][2];
//bool vis_reg_max[maxn]
//ll dp_fixed_min[maxn][2][2];
//ll dp_fixed_max[maxn][2][2];
//const ll inf = 1LL << 58;
//ll solve(int ind,int f)
//{
//	if(ind == n)
//		return 0;
//	int &ret = dp_reg_max[ind][f];
//	if(vis_reg_max[ind][f])
//		return ret;
//	ret = 0;
//
//}

int t;
string line;
bool can(int ind,int len)
{

	while (ind < n)
	{
		ind += len;
		if (ind < n)
		{
			if (line[ind] == ' ')
				++ind;
			else
				return false;
		}
	}
	return ind == n;
}
int main()
{
	ios
	cin >> t;
	cin.ignore();
	while(t--)
	{

		getline(cin,line);
		n = sz(line);
		bool done = false;
		for(int i = 0 ; i < n ; ++i)
		{
			if(line[i] == ' ')
			{
				if(can(i + 1,i))
				{
					done = 1;
					break;
				}
			}
		}

		if(done) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}
