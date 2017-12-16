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
pair<complex<double>,pair<int,string> > eval[11];

int get (complex<double> x, complex<double> y) {
  if (x.imag() == 0 && y.imag() == 0)
    return x.real() > y.real();
  else if (x.imag() != 0 && y.imag() == 0)
    return false;
  else if (x.imag() == 0 && y.imag() != 0)
    return true;
  else if (x.imag() != 0 && y.imag() != 0)
    return x.real() < y.real();
  return 0;
}
typedef pair<complex<double>,pair<int,string> > PPP;
bool compare(PPP a,PPP b) {
	int x = get(a.first,b.first);
	if(x != 0) return x > 0;
	return a.second.first < b.second.first;
}

int main() {
	double a,b,c;
	cin >> a >> b >> c;
	complex<double> x(a,0),y(b,0),z(c,0);
	eval[0].first = z * log(y) + log(log(x)); eval[0].second.second = "x^y^z";
	eval[1].first = y * log(z) + log(log(x)); eval[1].second.second = "x^z^y";
	eval[2].first = log(z * y) + log(log(x)); eval[2].second.second = "(x^y)^z";
	eval[3].first = log(z * y) + log(log(x)); eval[3].second.second = "(x^z)^y";
	///
	eval[4].first = z * log(x) + log(log(y)); eval[4].second.second = "y^x^z";
	eval[5].first = x * log(z) + log(log(y)); eval[5].second.second = "y^z^x";
	eval[6].first = log(x * z) + log(log(y)); eval[6].second.second = "(y^x)^z";
	eval[7].first = log(x * z) + log(log(y)); eval[7].second.second = "(y^z)^x";
	///
	eval[8].first = y * log(x) + log(log(z)); eval[8].second.second = "z^x^y";
	eval[9].first = x * log(y) + log(log(z)); eval[9].second.second = "z^y^x";

	eval[10].first = log(x * y) + log(log(z)); eval[10].second.second = "(z^x)^y";
	eval[11].first = log(x * y) + log(log(z)); eval[11].second.second = "(z^y)^x";
	for(int i = 0 ; i < 12 ; ++i)
		eval[i].second.first = i;
	sort(eval,eval + 12,compare);
	cout << eval[0].second.second;
}



