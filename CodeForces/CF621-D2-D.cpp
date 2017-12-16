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
#include <complex>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
pair<double,string> eval[11];

// double Log Normalization then sort values normally
// tricky case one of the numbers is less than 1
// if any numbers is less than < 1, double log normalization will cause nan values
// as long is undefined
// In this case we do single log normalization as we can have at most pow(200,200) which is inf in c++
// but if that occurs it's maximum term so we will never compare 2 infs

int main() {
	double x,y,z;
	cin >> x >> y >> z;
	if(x == 1 && y == 1 && z == 1) {
		cout << "x^y^z";
		return 0;
	}

	if(x < 1 || y < 1 || z < 1) {
		eval[0].first = pow(y,z) * log(x); eval[0].second = "x^y^z";
		eval[1].first = pow(z,y) * log(x); eval[1].second = "x^z^y";
		eval[2].first = z * y * log(x); eval[2].second = "(x^y)^z";
		eval[3].first = z * y * log(x); eval[3].second = "(x^z)^y";
		///
		eval[4].first = pow(x,z) * log(y); eval[4].second = "y^x^z";
		eval[5].first = pow(z,x) * log(y); eval[5].second = "y^z^x";
		eval[6].first =  x* z * log(y); eval[6].second = "(y^x)^z";
		eval[7].first =  x * z * log(y); eval[7].second = "(y^z)^x";
		///
		eval[8].first = pow(x,y) * log(z); eval[8].second = "z^x^y";
		eval[9].first = pow(y,x) * log(z); eval[9].second = "z^y^x";

		eval[10].first =  x * y * log(z); eval[10].second = "(z^x)^y";
		eval[11].first =  x * y * log(z); eval[11].second = "(z^y)^x";
	}
	else {
		eval[0].first = z * log(y) + log(log(x)); eval[0].second = "x^y^z";
		eval[1].first = y * log(z) + log(log(x)); eval[1].second = "x^z^y";
		eval[2].first = log(z * y) + log(log(x)); eval[2].second = "(x^y)^z";
		eval[3].first = log(z * y) + log(log(x)); eval[3].second = "(x^z)^y";
		///
		eval[4].first = z * log(x) + log(log(y)); eval[4].second = "y^x^z";
		eval[5].first = x * log(z) + log(log(y)); eval[5].second = "y^z^x";
		eval[6].first = log(x * z) + log(log(y)); eval[6].second = "(y^x)^z";
		eval[7].first = log(x * z) + log(log(y)); eval[7].second = "(y^z)^x";
		///
		eval[8].first = y * log(x) + log(log(z)); eval[8].second = "z^x^y";
		eval[9].first = x * log(y) + log(log(z)); eval[9].second = "z^y^x";

		eval[10].first = log(x * y) + log(log(z)); eval[10].second = "(z^x)^y";
		eval[11].first = log(x * y) + log(log(z)); eval[11].second = "(z^y)^x";
	}
	double ans = -500;
	for(int i = 0 ; i < 12 ; ++i){
		ans = max(ans,eval[i].first);
	}

	for(int i = 0 ; i < 12 ; ++i) {
		//cerr << eval[i].first << "\n";
		if(abs(ans - eval[i].first) <= 1e-9) {
			cout << eval[i].second << "\n";
			return 0;
		}
	}

}
