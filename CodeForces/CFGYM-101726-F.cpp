
#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include <random>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include <unordered_map>
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
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
int t;
const int maxn = 100005;
int main() {


	double pi = acos(-1.0);
	scanf("%d",&t);
	int n,w,s;
	while(t--) {
		scanf("%d %d %d",&n,&w,&s);
		vector<int> v;
		int pos = 0;
		int x;
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d",&x);
			v.pb(x);
			if(!x) pos = i;
		}
		double lef = 0.0;
		for (int i = 0 ; i < pos ; ++i) {
			lef = max(lef,atan2(v[i],(pos - i) * (w + s)));
		}
		double rit = 0.0;
		for (int i = pos + 1 ; i < n ; ++i) {
			rit = max(rit,atan2(v[i],(i - pos) * (w + s)));
		}
		double per = (16.0*60.0)/pi;
		printf("%.6f\n",(pi - rit - lef)*per);
	}


}
