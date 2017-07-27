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
#include<complex>
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

// Adhoc withe little greedy
vector<int> sortArray(vector<int> v)
		{

	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	REP(i,v) pq.push(v[i]);
	int pos = 0;
	int n = sz(v);
	vector<int> arr;
	//arr.resize(n);
	arr.pb(pq.top());
	pq.pop();
	std::priority_queue<int, std::vector<int>, std::greater<int> > banned;
	queue<int> carry;

	while(sz(pq) > 0 || sz(banned) > 0)
	{
		// put all bad numbers into queue
		while(!pq.empty() && (sz(arr) > 0 && arr.back() + 1 == pq.top())) banned.push(pq.top()),pq.pop();
		if(sz(pq) > 0)
		{
			arr.pb(pq.top()); pq.pop();
			// re-add banned members
			while(!banned.empty()) pq.push(banned.top()),banned.pop();
		}
		else
		{
			// arr[pos] is a wrong decision
			int curr = arr.back(); arr.pop_back();
			// carry on banned members, and rest re-activate
			while(!banned.empty())
			{
				int x = banned.top(); banned.pop();
				;
				if(x == curr)
					carry.push(x);
				else pq.push(x);

			}

			while(!carry.empty())
			{

				banned.push(carry.front()),carry.pop();
			}
			banned.push(curr);
		}
	}
	return arr;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0 ; i < n ; ++i)
	{
		int x; cin >> x;
		v.pb(x);
	}
	v = sortArray(v);
	REP(i,v)
	cout << v[i] << " ";
}

