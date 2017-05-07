#include <iostream>
#include <cstdio>
#include<list>
#include<sstream>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<numeric>
#include<utility>
#include<memory.h>
#include<iomanip>
#include<cmath>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int n,m;
int t;
int adj[501][501];
vector<int> g[501];
int main()
{
	fast
	cin >> t;
	int tc = 1;
	while(t--)
	{
		cin >> n >> m;
		int u,v;
		for(int i = 0 ; i < n ; ++i)
			g[i].clear();
		for(int i = 0 ; i < m ; ++i)
		{
			cin >> u >> v;
			--u; --v;

			adj[u][v] = adj[v][u] = 1;
			g[u].push_back(v); g[v].push_back(u);

		}
		cout << "Case " <<(tc++)<<": ";
		bool bad = 0;
		int arr[5];
		memset(arr,0,sizeof(arr));
		for(int i = 0 ; i < n && !bad ; ++i)
		{
			//cerr << (i + 1) << " " << g[i].size() << "\n";
			if(g[i].size() > 4)
				bad = 1;
			else
			arr[(int)g[i].size()]++;
		}
		bad |= arr[0] > 0;

		if(bad)
		{
			cout << "NotValid" << "\n";
			continue;
		}
		if(arr[4] == 1 && arr[1] == 4 && arr[3] == 0)
		{
			cout << "X" <<"\n";
			continue;
		}

		if(arr[4] == 0 && arr[3] == 1 && arr[1] == 3)
		{
			cout << "Y" << "\n";
			continue;
		}
		if(arr[4] == 0 && arr[3] == 0 && arr[1] == 2)
		{
			cout << "I" << "\n";
			continue;
		}
		cout << "NotValid" << "\n";


	}



}
