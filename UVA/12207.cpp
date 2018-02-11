
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
int n,k;
queue<int> q;
set<int> s;
stack<int> ex;

// ADHOC
struct CustomQueue {
	vector<int> v;

	int pop() {
		if(sz(v) == 0) assert(0);
		//cerr << v[0] << "\n";
		int x = v[0];
		v.erase(v.begin());
		//cerr << v[0] << "\n";
		return x;
	}
	void push(int x) {
		v.pb(x);
	}
	void moveToFront(int x) {
		int ind = 0;
		REP(i,v) {
			if(v[i] == x) ind = i;
		}
		v.erase(v.begin() + ind);
		v.insert(v.begin(),x);
	}
};
int main() {

	int t = 1;
	while(scanf("%d %d",&n,&k)) {
		if(!(n + k))
			break;
		s.clear();
		while(!q.empty()) q.pop();
		while(!ex.empty()) ex.pop();
		printf("Case %d:\n",t++);
		if(n > k) {
			// simulate
			queue<int> q;
			for (int i = 1 ; i <= 20000 ; ++i) q.push(i);
			set<int> s;
			char c;
			while(k--) {
				scanf(" %c",&c);
				if(c == 'N') {
					if(sz(ex) == 0) {
						while(s.find(q.front()) != s.end()) {
							s.erase(s.lower_bound(q.front()));
							q.pop();
						}
						printf("%d\n",q.front());
						q.push(q.front());
						q.pop();
					} else {
						printf("%d\n",ex.top());
						q.push(ex.top());
						ex.pop();
					}
				} else {
					int x;
					scanf("%d",&x);
					if(s.find(x) != s.end()) {
						stack<int> tmp;
						while(!ex.empty()) {
							if(x != ex.top())
							tmp.push(ex.top());
							ex.pop();
						}
						while(!tmp.empty()) ex.push(tmp.top()),tmp.pop();
						ex.push(x);
					} else {
						s.insert(x);
						ex.push(x);
					}
				}
			}
		} else {

			CustomQueue q;
			char c;
			for (int i = 1 ; i <= n ; ++i) q.push(i);
			while(k--) {
				scanf(" %c",&c);
				if(c == 'N') {
					int x = q.pop();
					printf("%d\n",x);
					q.push(x);
				}
				else {
					int x;
					scanf("%d",&x);
					q.moveToFront(x);
				}
			}

		}
	}

}

