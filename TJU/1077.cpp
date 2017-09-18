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
int t;
double L,R;
int n;
bool g[26][26];
vector<int> taken[26];
bool yes;
int c;
// Backtracking
// Problem can be abstracted to graph coloring
void bt(int ind)
{
	if(yes)
		return;
	if(ind == n)
	{
		yes = true;
		return;
	}
	for(int i = 0 ; i < c ; ++i)
	{
		bool bad = 0;
		REP(j,taken[i])
		{
			int v = taken[i][j];
			if(g[v][ind])
			{
				bad = 1;
				break;
			}
		}
		if(!bad)
		{
			taken[i].pb(ind);
			bt(ind + 1);
			taken[i].pop_back();
		}
	}
}
bool can(int d)
{
	c = d;
	if(c >= n)
		return true;
	yes = false;
	for(int i = 0 ; i < 26 ; ++i)
		taken[i].clear();
	bt(0);
	return yes;
}
int main()
{

	ios
	while(cin >> n && n != 0)
	{
		cin.ignore();

		string line;
		memset(g,0,sizeof(g));
		for(int k = 0 ; k < n ;  ++k)
		{
			getline(cin,line);
			int s = line[0] - 'A';
			for(int i = 2 ; i < sz(line) ; ++i)
			{
				int t = line[i] - 'A';
				g[s][t] = g[t][s] = 1;
			}
		}
		for(int i = 1 ; i <= n ; ++i)
		{

			if(can(i))
			{
				cout << i << " channel";
				if(i > 1) cout <<"s";
				cout <<" needed." << "\n";
				break;
			}
		}
	}


}
