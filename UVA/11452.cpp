#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <unordered_map>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define ll  long long
#define EPS (1e-8);
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define neg(x) memset(x,-1,sizeof(x));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define endl "\n"
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;
#define MAXN 1000001
string str;
int tc;

int pi[MAXN];
int n;
void buildPI(string s)
{
	int m = s.size();
	pi[0] = 0;
	for(int i = 1 ; i < m ; i++)
	{
		int j = pi[i - 1];
		while(j > 0 && s[i] != s[j]) j = pi[j - 1];
		if(s[i] == s[j]) ++j;
		pi[i] = j;

	}
}

void print(string &s)
{
	int i = 0;
	int sz = s.size();
	for(int j = 0; j < 8 ; ++j)
	{
		cout << s[i];
		++i;
		i %= sz;
	}
	cout << "..." << endl;

}
int main()
{
	fast
	cin >> tc;
	while(tc--)
	{
		cin >> str;
		buildPI(str);
		string s = "";
		string per = "";
		n = sz(str);
		for(int i = 0 ; i < n ; ++i)
		{
			s = "";
			for(int j = i ; j < n ; ++j)
				s += str[j];
			buildPI(s);
			if(sz(s) % 2 == 0 && sz(s) / pi[sz(s) - 1] == 2)
			{
				for(int j = 0 ; j < pi[sz(s) - 1] ; ++j)
					per += s[j];

				break;

			}

		}
		print(per);
	}

}

