#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include <deque>
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
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
int c[6] = {1,5,10,50,100,500};
int main() {
	int n;
	while (scanf("%d",&n)) {
		if (!n) {
			break;
		}
		n = 1000 - n;
		int ans = 0;
		for (int j = 5 ; j >= 0 ; --j) {
			ans += n / c[j];
			n %= c[j];
		}
		cout << ans << "\n";
	}
}
