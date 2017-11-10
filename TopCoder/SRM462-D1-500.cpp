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
typedef pair<ll,ll> pii;
typedef pair<pii,int> state;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;

int N,C;

struct CandyBox {
 vector<double> expectedScore(int C,vector<int> score,int S);
};

double dp[2][10001];

 double solve(int state,int S) {
	if(S == 0) {
		return state == 1 ? 1 : 0;
	}
	if(dp[state][S] != -1)
		return dp[state][S];
	double tot = (N * C) * (N * C - 1) / 2;
	double p = 1.0 - (N*C - 1) / tot;
	double ret = p * solve(state,S - 1);


	// swap in current box
	double pairs = C - 1;
	ret  += (1.0*pairs/tot) * solve(state,S - 1);

	if(state == 0) {
		// move to goal box
		pairs = C;
		ret += pairs / tot * solve(1,S - 1);
		// totally new box
		pairs = (N - 2) * C;
		ret += pairs / tot * solve(0,S - 1);
	}
	else {
		// move to a non goal box
		pairs = (N - 1) * C;
		ret += pairs / tot * solve(0, S - 1);
	}


	return dp[state][S] = ret;
}

vector<double> CandyBox::expectedScore(int c,vector<int> score,int S) {
	C  = c;
	N = sz(score);
	vector<double> sol(N,0.0);
	int n = sz(score);

	for(int i = 0 ; i < 2 ; ++i) {
		fill(dp[i],dp[i] + 10001,-1.0);
	}
	for (int i = 0 ; i < n ; ++i) {

		for (int j = 0 ; j < n ; ++j) {

			sol[i] += ((score[j] * solve(i == j ? 1 : 0,S)));
		}

	}
	return sol;

}

int main() {

}




