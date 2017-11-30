
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
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;;
typedef vector<int> VI;
int n,m,k;
// Dynamic Programming + Binary Search
// Sort on ending time
// binary search the earliest time inside dp
// use it, and recur
char s[101];
string rev[101];
int subjectTime[101];
map<string,int> mp;
int id = 0;
int convert(int d,int h,int m ) {
	return d * 24 * 60  + h * 60 + m;
}
const int maxt = 30 * 24 * 60 + 24*60 + 60 + 10;
struct Entry {
	int subject;
	int deadline;
	int takes;
	int price;
	int index;
	Entry(int subject,int deadline,int price,int index) {
		this->subject = subject;
		this->deadline = deadline;
		this->price = price;
		this->takes = subjectTime[subject];
		this->index = index;
	}
	bool operator<(const Entry& o) const {
		if(deadline == o.deadline)
			return index < o.index;
		return deadline < o.deadline;
	}

};
int F[maxt];
int busy[maxt];
vector<Entry> tasks;
int dp[101][maxt];
int getDelay(int start,int plus) {

	int lo = start, hi = maxt - 1;
	int ans = 1 << 30;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int tot = mid - start + 1;
		tot -= busy[mid];
		if(start != 0) tot += busy[start - 1];
		if(tot >= plus) ans = mid,hi = mid - 1;
		else lo = mid + 1;
	}
	return ans;
}

int solve(int ind,int curr_t) {
	if(curr_t > maxt)
		return -(1 << 28);
	if(ind == sz(tasks) )
		return 0;
	int &ret = dp[ind][curr_t];
	if(ret != -1)
		return ret;
	ret = 0;
	// leave current task
	ret = max(ret,solve(ind + 1,curr_t));
	// take current task

	int d = getDelay(curr_t,tasks[ind].takes);
	//cerr << d << " " << tasks[ind].deadline << "\n";
	if(d < tasks[ind].deadline) {
		ret = max(ret,tasks[ind].price + solve(ind + 1,d + 1));
	}
	return ret;
}
struct Response {
	int ind;
	int end,start;
	int start_day,start_hour,start_min;
	int end_day,end_hour,end_min;
	int a;

	Response(int ind,int start,int end) {
		this->ind  = ind;
		this-> end = end;
		this->start = start;
		a = start;
		go();
	}
	void go() {

		start_day = start/(1440);
		start %= 1440;
		start_hour = start / 60;
		start_min = start % 60;

		end_day = end/(1440);
		end %= 1440;
		end_hour = end / 60;
		end_min = end % 60;
	}

	bool operator<(const Response& o) const {
		if(a == o.a)
			return ind < o.ind;
		return start < o.start; }

};
vector<Response> responses;
void trace(int ind,int curr_t) {

	if(ind == sz(tasks) )
		return;
	int ret = dp[ind][curr_t];
	ret = 0;
	int opt = solve(ind,curr_t);
	// leave current task
	ret = max(ret,solve(ind + 1,curr_t));
	if(opt == ret) {
		trace(ind + 1, curr_t);
		return;
	}
	// take current task
	int d = getDelay(curr_t,tasks[ind].takes);
	//cerr << d << " " << tasks[ind].deadline << "\n";
	if(d < tasks[ind].deadline) {

		ret = max(ret,tasks[ind].price + solve(ind + 1,d + 1));
		responses.pb(Response(tasks[ind].index,F[curr_t],d));
		trace(ind + 1, d + 1);
	}

}
int main() {

	scanf("%d %d %d",&n,&m,&k);
	for (int i = 0 ; i < n ; ++i) {
		string str;
		cin >> str;
		//cerr << str << "\n";
		mp[str] = i;
		rev[i] = str;
	}
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d",&subjectTime[i]);
	}
	int h1,m1,h2,m2;
	// scan off time
	for(int i = 0 ; i < 4;  ++i) {
		scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2);
		for(int k = 0 ; k < 30 ; ++k) {
			// insert bad timings
			int L = convert(k,h1,m1);
			int R = convert(k,h2,m2);
			busy[L]++;
			busy[R + 1]--;
		}
	}
	for(int i = 1 ; i < maxt ; ++i) {
		busy[i] += busy[i - 1];
	}
	//cerr << "here" << "\n";
	int lst = -1;
	for(int i = maxt - 1 ; i >= 0 ; --i) {
		if(!busy[i]) lst = i;
		if(lst != -1)  {
			F[i] = lst;
		}
	}
	for(int i = 1 ; i < maxt ; ++i) busy[i] += busy[i - 1];

	scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2);
	int p;
	int day;
	for(int i = 0 ; i < m ; ++i) {
		string str;
		cin >> str;

		scanf("%d %d:%d %d",&day,&h1,&m1,&p);
		--day;

		if(mp.find(str) == mp.end())
			continue;
		int t = convert(day,h1,m1);
		tasks.pb(Entry(mp[str],t,p,i));
	}
	sort(all(tasks));

	memset(dp,-1,sizeof(dp));
	cout << solve(0,0) << "\n";
	trace(0,0);
	printf("%d\n",sz(responses));
	REP(i,responses) {
		printf("%d %d %02d:%02d %d %02d:%02d\n",responses[i].ind + 1,responses[i].start_day + 1,responses[i].start_hour,
				responses[i].start_min,responses[i].end_day + 1,responses[i].end_hour,responses[i].end_min);
	}
}
