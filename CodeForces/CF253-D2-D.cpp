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
typedef pair<ll,ll> pii;
#define F first
#define S second
#define MP make_pair
int grid[401][401];
int dp[401][401];
int n,m,k;
// 2 pointers + preprocessing
unsigned short col_dp[401][401][401];
char str[401];
int query(int i1,int j1,int i2,int j2)
{
	int rem = dp[i2][j2];
	if(i1 > 0)
		rem -= dp[i1 - 1][j2];
	if(j1 > 0)
		rem -= dp[i2][j1 - 1];
	if(i1 > 0 && j1 > 0)
		rem += dp[i1 -1][j1 - 1];
	return rem;
}
int rem[26];
unsigned short see[26][401][401];
int main() {

//		fi("input.txt");
//		fo("output.txt");

	scanf("%d %d %d",&n,&m,&k);
	for (int i = 0 ; i < n ; ++i) {
		scanf("%s",str);
		for(int j = 0 ; j < m ; ++j)  {
			grid[i][j] = str[j]-'a';
			dp[i][j] = grid[i][j] == 0;
			if(i > 0)
				dp[i][j] += dp[i - 1][j];
			if(j > 0) dp[i][j] += dp[i][j - 1];
			if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];

		}
	}


	// fix rows?
	long long res = 0;


	for (int i = 0 ; i < n ; ++i) {
		for (int j1 = 0; j1 < m ; ++j1) {
			for (int j2 = j1 + 1 ; j2 < m ; ++j2) {
				col_dp[i][j1][j2] = 0;
				int c = grid[i][j1];
				if (c == grid[i][j2]) {
					//cerr << i << " " << j1 << " " << j2 << "\n";
					col_dp[i][j1][j2] = 1 + see[c][j1][j2];
				}
			}
		}

		for (int j1 = 0; j1 < m ; ++j1) {
			for (int j2 = j1 + 1 ; j2 < m ; ++j2) {

				int c = grid[i][j1];
				if (c == grid[i][j2]) {
					see[c][j1][j2]++;

				}


			}
		}
	}

	for (int j1 = 0 ; j1 < m ; ++j1) {
		for (int j2 = j1 + 1 ; j2 < m ; ++j2) {
			int L = 0, R = 1;
			memset(rem,0,sizeof(rem));
			while (L < n && R < n) {
				while(query(L,j1,R,j2) <= k && R < n) {
					int lef = 0;
					if(L>0) lef = rem[grid[R][j1]];
					int p = (col_dp[R][j1][j2] - lef);
					if(R != L && grid[R][j1] == grid[R][j2] && p != 0) {
						//	cerr << L << " " << R << " " << j1 << " " << j2 <<  " "<<p<<"\n";
						res += p - 1;
					}
					++R;
				}
				while(R < n && query(L,j1,R,j2) > k && L < n) {
					if(grid[L][j1] == grid[L][j2]) {
						rem[grid[L][j1]]++;
					}
					++L;

				}

				if(L == R) ++R;
				//cerr << L << " " << R << "\n";

			}
		}
	}

	//cout << query(1,3,3,3) << "\n";
	cout << res << "\n";
}
