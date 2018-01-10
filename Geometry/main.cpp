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
#include <unordered_map>
using namespace std;
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
struct Point {
	ll x,y;
	Point(ll x,ll y) {
		this->x = x, this->y = y;
	}

};
ll operator*( Point const& lhs, Point const& rhs ) {
	return 1LL*lhs.x*rhs.x + lhs.y*lhs.y;
}
Point operator-(Point const& lhs, Point const& rhs ) {
	return Point(lhs.x - rhs.x,lhs.y - rhs.y);
}
Point operator+(Point const& lhs, Point const& rhs ) {
	return  Point(lhs.x + rhs.x,lhs.y + rhs.y);
}
int operator^( Point const& lhs, Point const& rhs ) {
	return  1LL*lhs.x*rhs.y - rhs.x*lhs.y;
}
