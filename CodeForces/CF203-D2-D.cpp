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
typedef pair<long double,long double> pii;
typedef pair< long double,long double> pdd;
#define F first
#define S second
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define mp make_pair
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define for1LL(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define fornLL(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define ld long double
ld a,b,m;
ld vx,vy,vz;
// Physics..
// 3 dimensions are indepedent because of no loss of energy assumption
// solve for Y, then solve for X and Y using the derived T, get the cycle, and the extra moved part
int main() {
	cin >> a >> b >> m >> vx >> vy >> vz;
	ld x,y,z;
	cout << fixed;
	cout << setprecision(12);
	ld T = 1.0*-m/vy;
	x = a / 2.0, y = m, z = 0;
	if(vx != 0) {
	if(vx <= 0) {
		vx = -vx;
		ld take = (a / 2.0) / vx;
		if(T > take) {
			T -= take;
			ld pos = T*vx;
			ld cyc = 1.0*pos / a;
			if((int)(floor(cyc)) % 2 == 0)
				cout << ( (cyc - (floor(cyc))) * a);
			else cout << a - ( (cyc - (floor(cyc))) * a);
		} else {
			cout << a / 2.0 - vx * T;
		}
	} else {

		ld take = (a / 2.0) / vx;
		if(T > take) {
			T -= take;
			ld pos = T*vx;
			ld cyc = 1.0*pos / a;
			if((int)(floor(cyc)) % 2 == 1)
				cout << ( (cyc - (floor(cyc))) * a);
			else cout << a - ( (cyc - (floor(cyc))) * a);
		} else {

			cout << a / 2.0 + vx * T;
		}
	}
	} else {
		cout << (a/2.0);
	}
	cout << " ";
	T = 1.0*-m/vy;
	ld pos = T*vz;
	ld cyc = 1.0*pos / b;
	if((int)(floor(cyc)) % 2 == 0)
		cout << ( (cyc - (floor(cyc))) * b);
	else cout << b - ( (cyc - (floor(cyc))) * b);



}
