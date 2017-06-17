#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<complex>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)

#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
vector<pair<string,int> > v;
int n;

bool dominates(string &a,string &b)
{
	int i = 0, j = 0;
	int sz1 = sz(a), sz2 = sz(b);
	if(sz2 > sz1)
		return 0;
	while(i < sz1 && j < sz2)
	{
		while(i < sz1 && j < sz2 && a[i] == b[j]) i++,++j;
		i++;
	}
	return j == sz2;
}
vector<pair<string,int> > ans;
bool bad[15001];
int main()
{
	fast
	int x = 0;
	string s;
	while(cin >> s) ans.push_back(make_pair(s,x)),sort(s.begin(),s.end()),v.push_back(make_pair(s,x)),x++;
	random_shuffle(v.begin(),v.end());
	n = sz(v);
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ; ++j)
		{
			if(i == j)
				continue;
			if(dominates(v[j].first,v[i].first))
			{

				bad[v[i].second] = 1;
				break;
			}
		}
	}
	vector<string> res;
	for(int i = 0 ; i < n ; ++i) if(!bad[i]) res.push_back(ans[i].first);
	sort(res.begin(),res.end());
	REP(i,res) cout << res[i] << "\n";

}
