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
const int maxn = 101;
ll mod = 1000*1000*1000 + 7;
string str;
int q;
// sort the give array
// pick an element at random with UNIFORM probability
// rand() gets WA!
int main() {
	ios
	 std::default_random_engine generator;
	cin >> q;
	for (int k = 0 , n = 2; k < q ; ++k, ++n) {
		string s; cin >> s;
		for (int i = 1; i <= n ; ++i) {
			for (int j = 1 ; j < n ; ++j) {
				cout << "? " << (j) << " " << (j + 1) << "\n";
			}
		}
		 std::uniform_int_distribution<int> distribution(1,n - 1);


        int a = distribution(generator);

		cout << "! " << a << " " << (a + 1) << "\n";

	}



}
