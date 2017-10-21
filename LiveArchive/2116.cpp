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
typedef pair<long double,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
typedef long double ld;


int main()
{

	ios
	ll n;
	bool f = 0;
	while( cin >> n ){
		if(n == -1)
			break;
		if(f)
			cout << "\n";
		f = 1;
		cout << "M("<<n<<") = ";
		if(n == 1) {
			cout << "1\n";
			continue;
		}
		int p = 0;
		int facs = 0;
		int st = 0;
		for(int i = 2 ; i * i <= n ; ++i) {
			if(n % i == 0) {
				n /= i;
				++facs;
				if(n % i == 0) {
					p = 0;
					st = 1;
					break;
				}
			}
		}
		if(!st) {
			if(facs % 2 == 0) p = -1;
			else p = 1;
		}
		cout << p << "\n";
	}

}


