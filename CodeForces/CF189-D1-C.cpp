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
int a,b,n;
const int maxn = 3e5 + 5;
vector<int> goal;
vector<int> v;
int pos[maxn];

/*
 Find largest j such that the subarray[0:j] of the first permutation is a subsequence in the second permutation.

 Correctness: In order to move the first element in permutation one we must move all elements after it, since we may only swap the latest
 element each time. So it is greedily optimal to try, and keep as most elements as possible from front unchanged.

 Now into why we need it to be a subsequence. Assume elements from 0 to i form a subsequence in permutation 2 then we can move elements between them
 without changing any of them, otherwise one must at least move.


 */
int main() {
	scanf("%d",&n);
	v.resize(n),goal.resize(n);
	for(int i = 0 ; i < n ; ++i) {
		scanf("%d",&v[i]);
	}
	for(int i = 0 ; i < n ; ++i) {
		scanf("%d",&goal[i]);
		pos[goal[i]] = i;
	}
	int lst = -1;
	int q = 0;
	for(int i = 0 ; i < n ; ++i) {
		if(pos[v[i]] > lst)
		{
			++q;
			lst = pos[v[i]];
		}
		else break;
	}
	cout << n  - q;

}
