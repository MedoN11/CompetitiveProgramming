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
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
int simulate(int n) {
	stack<int> s;

	for(int i = n ; i >= 1 ; --i) {
		s.push(i);
	}
	while(sz(s) > 1) {
		s.pop();
		stack<int> tmp;
		int c = s.top(); s.pop();

		while(!s.empty()) tmp.push(s.top()),s.pop();
		tmp.push(c);
		while(!tmp.empty()) s.push(tmp.top()), tmp.pop();
	}
	return s.top();
}
ll pow2[20];
int solve(int n) {
	if(n == 1)
		return 1;
	--n;
	int p = 1;
	while(1) {
		//cerr << n << "\n";
		int steps =  1 + (pow2[p] - 2) / 2;
		if(steps >= n)
			break;
		++p;
		n -= steps;
	}
	return 2 * n;
}
int main()
{
	pow2[0] = 1LL;
	for(int i = 1 ; i <= 30 ; ++i) {
		pow2[i] = pow2[i - 1] << 1;
	}
	ios
	int n;
	while(cin >> n) {
		if(!n)
			break;


		cout << solve(n) << "\n";
	}

}
