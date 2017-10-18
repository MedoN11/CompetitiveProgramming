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


// Line sweep
// Sweep on X while maintaing maximum y with a multiset
typedef pair<double, double> point;

struct Event {
	int x,h,t;
	Event () {}
	Event(int x,int h,int t )  {
		this->h = h;
		this->x = x;
		this->t = t;
	}
	bool operator<(const Event& o) const
	{
		if(this->x == o.x) {
			return this->t < o.t;
		}
		return this->x < o.x;

	}
};

int main() {
	ios
	int x1,h,x2;
	vector<Event> events;
	while(cin >> x1 >> h >> x2 ) {
		if(x1 + h + x2 == 0)
			break;
		events.pb(Event(x1,h,0));
		events.pb(Event(x2,h,1));
	}
	sort(all(events));
	multiset<int> active;
	active.insert(0);
	int lst = 0;
	int n = sz(events);
	bool f = 1;
	for(int i = 0 ; i < sz(events) ; ++i) {
		Event e = events[i];
		if(e.t == 0) {
			active.insert(events[i].h);
		}
		else active.erase(active.lower_bound(events[i].h));
		++i;
		while(i < n && e.x == events[i].x) {
			if(!events[i].t) {
				active.insert(events[i].h);
			}
			else  {
				active.erase(events[i].h);
			}
			++i;
		}
		--i;
		int larg = *active.rbegin();
		if(larg == lst)
			continue;
		if(larg > lst) {

			if(f)
				cout << e.x << " " << larg;
			else
				cout << " " << e.x << " " << larg ;
			lst = larg;
			f= 0;
		}
		else {
			cout << " " << e.x << " " << larg ;
			lst = larg;
		}
	}
	cout << "\n";
	return 0;
}
