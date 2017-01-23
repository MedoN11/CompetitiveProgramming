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
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define ll  long long
#define EPS (1e-8);
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define neg(x) memset(x,-1,sizeof(x));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define endl "\n"
using namespace std;
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
typedef pair<int,int> ii;

#define ld long double
#define MAXN 1001

long double p[1001][1001];
int n;
int deg[MAXN],left1[MAXN],right1[MAXN];

vector<pair<int, long double> > dfs(int u)
	{
	vector<pair<int,long double> > ret;
	if(u <= n)
	{
		ret.push_back(make_pair(u,1.0));
		return ret;
	}
	vector<pair<int,long double> > L = dfs(left1[u]);
	vector<pair<int,long double> > R = dfs(right1[u]);

	REP(l,L)
	{
		pair<int,long double> pr = make_pair(L[l].first,0);
		REP(r,R)
		{
			pr.second += 1.0*p[L[l].first][R[r].first] * L[l].second * R[r].second;
		}
		ret.push_back(pr);
	}
	REP(r,R)
	{
		pair<int,long double> pr = make_pair(R[r].first,0);
		REP(l,L)
		{
			pr.second += 1.0*p[R[r].first][L[l].first] * L[l].second * R[r].second;
		}
		ret.push_back(pr);
	}
	return ret;

		}



int main()
{

	fast
	while(cin >> n)
	{
		if(!n)
			break;
		for(int i = 1; i <= n ; ++i)
		{
			for(int j = 1 ; j <= n ; ++j)
			{
				//scanf("%lf",&p[i][j]);
				cin >> p[i][j];
			}
		}
		memset(deg,0,sizeof(deg));
		int u,v;
		for(int i = n + 1 ; i < (n << 1) ; ++i)
		{
			cin >> u >> v;
			left1[i] = u; right1[i] = v;
			deg[u]++; deg[v]++;
		}
		vector<pair<int,long double> > ans;
		double ret = 0.0;
		for(int i = 1; i < (n << 1) ; ++i)
		{
			if(!deg[i])
			{
				ans = dfs(i);
				break;
			}
		}

		REP(i,ans)
		if(ans[i].first == 1)
			ret = ans[i].second;

		//printf("%.6f\n",ret);
		cout << fixed;
		cout << setprecision(6);
		cout << ret << endl;

	}

}
