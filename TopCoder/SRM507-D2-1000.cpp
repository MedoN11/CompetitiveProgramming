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
#define ll long long
#define sz(v)               ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define pb push_back
typedef pair<int, int> pii;
#define mp make_pair
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

struct CubeRoll
{
	int getMinimumSteps(int s,int t,vector<int> v);
};
const int inf = 1 << 30;
bool seen[110001];
int BFS(int s,int t,int l,int r)
{
	queue<pii> Q;
	Q.push(pii(s,0));
	while(!Q.empty())
	{
		pii p = Q.front(); Q.pop();
		if(p.second > 3 || p.first >= r || p.first <= l)
			continue;

		seen[p.first] = 1;
		if(p.first == t)
			return p.second;
		for(int i = 1; i < 400 ; ++i)
		{
			int x = p.first + i * i;
			if(x < r && !seen[x])
			Q.push(pii(p.first + i * i,p.second + 1)),seen[x] = 1;
			x = p.first - i * i;
			if(x > l && !seen[x])
			Q.push(pii(p.first - i * i,p.second + 1)),seen[x] = 1;
		}


	}
	return 4;
}
int CubeRoll::getMinimumSteps(int s,int t,vector<int> v)
{
	if(s > t)
		swap(s,t);
	sort(all(v));
	int left = 1 << 30, right = 1 << 30;
	REP(i,v)
	{
		if(v[i] >= s && v[i] <= t)
			return -1;
		if(v[i] < s)
			left = v[i];
		if(v[i] > t && right == (1 << 30))
			right = v[i];
	}
	if(left != inf && right != inf)
	{
		return BFS(s,t,left,right);
	}

	int ans = BFS(s,t,max(0,s - 2), t + 2);
	int d = t - s;
	if(d % 2 == 1 || d % 4 == 0)
		ans = min(ans,2);
	else ans = min(ans,3);

	return ans;
}


int main()
{
	CubeRoll r;
	int s,t; cin >> s >> t;
	int m; cin >> m;
	vector<int> v(m);
	for(int i = 0 ; i < m ; ++i) cin >> v[i];
	cout  << r.getMinimumSteps(s,t,v);
}
