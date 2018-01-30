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
#define time __time
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
int n;
int arr[101];
/*  Let weights be sorted
 *  Induction
 *  Let's say we have a set of weights {a1,a2,a3..an}
 *  which can currently represent anything from 1 to (a1+a2+a3..an)
 *  let's add the next element, and there three cases
 *  next element <= sum..in this case it doesn't change anything in the answer, the answer is definitely > next element
 *  next element == sum + 1..Doesn't change anything as well because the first missing element is next element so answer > next element
 *  in these cases we safely add the current number to sum, and we can represent anything from 1 to s + next element since 1 to S was already representable by induction
 *  next element == sum + x and x > 1...answer is sum + 1..because we cannot cover sum + 1 by inductive rule.
 *  Base case if first element is not 1, then answer is easily seen as 1, otherwise base case is satisified 1 == 0 + 1, and we proceed by induction.
 */
int main() {
	scanf("%d",&n);
	int s = 1;
	int g = 0;
	scanf("%d",&arr[0]);
	if(arr[0] != 1) {
		cout << "1\n";
		return 0;
	}
	for (int i = 1 ; i < n ; ++i) {
		scanf("%d",&arr[i]);
		if(arr[i] - s > 1 && g == 0) g = s + 1;
		s += arr[i];
	}
	if(g == 0) g = s + 1;
	cout << g << "\n";
}
