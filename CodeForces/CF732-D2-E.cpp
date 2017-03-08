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
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define ll  long long
using namespace std;

int n,m;
vector<pair<int,int> > sock;
set<pair<int,int> > comp;
int res[2000001];
int num[2000001];

int main()
{
	scanf("%d %d",&n,&m);
	memset(res,-1,sizeof(res));
	for(int i = 0 ; i < n ; ++i)
	{
		int a; scanf("%d",&a);
		comp.insert(make_pair(a,i));
	}
	for(int i = 0 ; i < m ; ++i)
	{
		int a; scanf("%d",&a);
		sock.push_back(make_pair(a,i));
	}

	sort(sock.begin(),sock.end());
	int conn = 0;
	ll cost = 0;
	REP(j,sock)
	{
		int x = sock[j].first; set<pair<int,int> >::iterator it;
		bool bad = 0;
		int f = 0;
		int cnt = 0;
		while(!bad)
		{
			it = comp.lower_bound(make_pair(x,-1));
			if(it != comp.end() && it->first == x)
				break;
			x = (x + 1) >> 1;
			++cnt;
			if(f && x == 1)
				bad = 1;
			if(x == 1)
				f = 1;

		}
		if(bad)
			continue;

		++conn;
		cost += 1LL*cnt;
		res[it->second] = sock[j].second;
		num[sock[j].second] = cnt;
		comp.erase(*it);
	}
	cout << conn << " " << cost << endl;
	for(int i = 0 ; i < m ; ++i)
		printf("%d ",num[i]);
	puts("");
	for(int i = 0 ; i < n ; ++i)
		printf("%d ",res[i] + 1);

}

