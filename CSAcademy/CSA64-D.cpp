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
#include <unordered_map>
using namespace std;
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
int t;
int n,m;

// Graph Theory Theorm + Simple Game Theory
// Number of nodes with odd degree in any graph is odd.
// At the end all nodes will have odd degrees
// so simple nim for parity
int main()
{
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		int u,v;
		for(int i = 0 ; i < m ; ++i) {
			scanf("%d %d",&u,&v);
		}
		if(n % 2 == 1) {
			printf("1\n");
		}
		else printf("0\n");
	}

}
