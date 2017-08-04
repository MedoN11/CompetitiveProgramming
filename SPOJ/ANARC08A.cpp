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
#include <unordered_map>
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
int a,b;


inline string rotateAcw(string &a)
{
	string ret  = "";
	int num0[] = {4,1,3,5,2,6,7,8,9};
	for(int i = 0 ; i < 9 ; ++i) ret += a[num0[i] - 1];
	return ret;
}
inline string rotateAccw(string &a)
{
	string ret  = "";
	int num00[] = {2,5,3,1,4,6,7,8,9};
	for(int i = 0 ; i < 9 ; ++i) ret += a[num00[i] - 1];
	return ret;

}
int num00[] = {2,5,3,1,4,6,7,8,9};
int num0[] = {4,1,3,5,2,6,7,8,9};
int num1[] = {1,5,2,4,6,3,7,8,9};
int num2[] = {1,3,6,4,2,5,7,8,9};
int num3[] = {1,2,3,7,4,6,8,5,9};
int num4[] = {1,2,3,5,8,6,4,7,9};
int num5[] = {1,2,3,4,8,5,7,9,6};
int num6[] = {1,2,3,4,6,9,7,5,8};

inline string rotateBcw(string &a)
{
	string ret  = "";

	for(int i = 0 ; i < 9 ; ++i) ret += a[num1[i] - 1];

	return ret;
}

inline string rotateBccw(string &a)
{
	string ret  = "";
	for(int i = 0 ; i < 9 ; ++i) ret += a[num2[i] - 1];
	return ret;
}

inline string rotateCcw(string &a)
{
	string ret  = "";
	for(int i = 0 ; i < 9 ; ++i) ret += a[num3[i] - 1];
	return ret;
}
inline string rotateCccw(string &a)
{
	string ret  = "";

	for(int i = 0 ; i < 9 ; ++i) ret += a[num4[i] - 1];
	return ret;
}

inline string rotateDcw(string &a)
{
	string ret  = "";

	for(int i = 0 ; i < 9 ; ++i) ret += a[num5[i] - 1];
	return ret;
}
inline string rotateDccw(string &a)
{
	string ret  = "";

	for(int i = 0 ; i < 9 ; ++i) ret += a[num6[i] - 1];
	return ret;
}
#define fast std::ios_base::sync_with_stdio(false);

map<ll,int> mp;

ll base = 11;
char s[12];
ll getHash(string &a)
{
	ll h = 0;
	REP(i,a) h *=11, h += a[i] - '0';
	return h;
}
int main()
{

	string str = "123456789";
	int tc = 1;
	queue<string> q;
	q.push(str);
	int ans = 1 << 30;
	mp[getHash(str)] = 0;
	vector<string> nextStates;
	while(!q.empty())
	{
		string p = q.front();q.pop();
		//cerr << p << "\n";
		int cost = mp[getHash(p)];
		if(cost > 10)
			break;
		nextStates.clear();
		nextStates.pb(rotateAcw(p));
		nextStates.pb(rotateAccw(p));
		nextStates.pb(rotateBcw(p));
		nextStates.pb(rotateBccw(p));
		nextStates.pb(rotateCcw(p));
		nextStates.pb(rotateCccw(p));
		nextStates.pb(rotateDcw(p));
		nextStates.pb(rotateDccw(p));
		REP(i,nextStates)
		{
			ll h = getHash(nextStates[i]);
			if(mp.find(h) == mp.end())
			{
				mp[h] = cost + 1;
				q.push(nextStates[i]);
			}
		}
	}
	while(scanf("%s",s))
	{

		bool z = 1;
		for(int i = 0 ; i < 10 ; ++i) if(s[i] != '0') z = 0;
		str = s;
		if(z) break;

		printf("%d. ",tc++);
		int steps = str[0] - '0';
		string t = str.substr(1,sz(str) - 1);
		ll h = getHash(t);
		if(mp.find(h) == mp.end())
			ans = -1;
		else ans = mp[h];
		if(ans > steps)
			ans = -1;
		printf("%d\n",ans);

	}
}

