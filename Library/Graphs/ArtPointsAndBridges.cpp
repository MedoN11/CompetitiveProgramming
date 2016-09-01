#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <stack>
#include <queue>
#include <iterator>
#include <vector>
#include <iterator>
#include <math.h>
#include<cstring>
#include <unordered_set>
#include <cmath>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#include <cmath>
#include <map>
#define fast std::ios_base::sync_with_stdio(false);
#define LL long long
#define ll long long
#define endl "\n"
#define Int int
#define lp(i,n) for(int i=0;i<(int)n;i++)
#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);i++)
#define neg(v)       memset(v,-1,sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);i++)
#define lp1(i,n)    for(int i=1;i<=(int)n;i++)
#define countBits(msk) __builtin_popcount(msk)
using namespace std;
typedef pair<int,int> ii;
#define FOR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define readfile freopen("input.txt","r",stdin);
#define writefile ("output.txt","w",stdout);
LL gcd(LL a, LL b) { if(b==0) return a;   return gcd(b,a%b);}
LL lcm (LL a, LL b) {   return a*(b/(gcd(a,b)));  }
typedef vector<int> vi;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline LL toLL(string s){LL v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
using namespace std;

int N;
int dfs_num[100005];
int dfs_low[100005];
bool isArt[1000005];
vector<vector<int> > Graph(100005);
int counter = 0;
int root_childs = 0;
void dfs(int idx,int p)
{

	// mark the time of visiting that node and the highest ancestor it can go to is itself.
	dfs_num[idx] = dfs_low[idx] = counter++;
	rep(k,Graph[idx])
	{
		int next = Graph[idx][k];
		if(dfs_num[next] == -1)
		{
			dfs(next,idx);
			if(dfs_num[idx] > dfs_low[next])
			{
				// bridge
			}

			if(dfs_num[idx] >= dfs_low[next])
			{
				// art. point
			}
			dfs_low[idx] = min(dfs_low[idx],dfs_low[next]);

		}
		else
		{
			if(next != p) dfs_low[idx] = min(dfs_low[idx],dfs_num[next]);

		}
	}


}


void getBridgesAndArticulationPoints()
{

	memset(dfs_num,-1,sizeof(dfs_num));
	memset(dfs_low,-1,sizeof(dfs_low));
	for(int i = 0 ; i < N ; i++)
	{
		if(dfs_num[i] != -1)
		{
			counter = 0;
			root_childs = 0;
			dfs(i,-1);
			if(root_childs > 1)
			{
				// root is art. pt.
			}
		}
	}
}




