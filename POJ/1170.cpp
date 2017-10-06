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

const int maxn = 1e5 + 5;
const ll mod = 1000000007;//l1000*1000*1000 + 7;
int normal_price[10];
int quan[10];
int code[10];
int n,q;
struct offer {
	int quan;
	vector<pii> prod;
	int price;
};
offer offers[101];

vector<int> getCopy(vector<int> & v) {
	vector<int> tmp;
	REP(i,v) tmp.pb(v[i]);
	return tmp;
}

int id[5000];
int dp[11][11][11][11][11];
int solve(int a,int b,int c,int d,int e) {

	if(a < 0 || b < 0 || c < 0 || d < 0 || e < 0)
		return 1 << 30;
	int &ret = dp[a][b][c][d][e];

	if(ret != -1)
		return ret;
	ret = a * normal_price[0] + b * normal_price[1] + c * normal_price[2] + d * normal_price[3] + e * normal_price[4];
	for(int i = 0 ; i < q ; ++i) {
		int aa = a;
		int bb = b;
		int cc = c;
		int dd = d;
		int ee = e;
		REP(j,offers[i].prod) {
			int co = id[offers[i].prod[j].first];
			if(co == 0) aa -= offers[i].prod[j].second;
			if(co == 1) bb -= offers[i].prod[j].second;
			if(co == 2) cc -= offers[i].prod[j].second;
			if(co == 3) dd -= offers[i].prod[j].second;
			if(co == 4) ee -= offers[i].prod[j].second;

		}
		if(aa >= 0 && bb >= 0 && cc >= 0 && dd >= 0 && ee >= 0)
		ret = min(ret,offers[i].price + solve(aa,bb,cc,dd,ee));
	}




	return ret;


}

int main()
{
	scanf("%d",&n);
	vector<int> v;
	for(int i = 0 ; i < n ; ++i) {
		scanf("%d %d %d",&code[i],&quan[i],&normal_price[i]);
		id[code[i]] = i;
		v.pb(quan[i]);
	}
	while(sz(v) < 0) v.pb(0);
	memset(dp,-1,sizeof(dp));
	scanf("%d",&q);
	for(int i = 0 ; i < q ; ++i) {
		scanf("%d",&offers[i].quan);
		for(int j = 0 ; j < offers[i].quan ; ++j) {
			int c,k;
			scanf("%d %d",&c,&k);
			offers[i].prod.pb(pii(c,k));
		}
		scanf("%d",&offers[i].price);
	}
	cout << solve(v[0],v[1],v[2],v[3],v[4]) << "\n";

}
