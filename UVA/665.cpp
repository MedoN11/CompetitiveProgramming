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
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define ll  long long
using namespace std;
bool mark[101];
int tc;
void no()
{
	puts("0");
	if(tc)
		puts("");
}
void yes(int x)
{
	printf("%d\n",x);
	if(tc)
		puts("");
}
typedef vector<int> vi;

int main()
{

	cin >> tc;
	while(tc--)
	{
		set<int> tL,tR;
		memset(mark,0,sizeof(mark));
		int n,k;
		cin >> n >> k;
		vector<pair<vi,vi> > checks;
		for(int j = 0 ; j < k ;++j)
		{
			int m; cin >> m;

			vector<int> left,right; left.resize(m); right.resize(m);
			for(int i = 0 ; i < m ; ++i)
			{
				cin >> left[i];
			}
			for(int i = 0 ; i < m ; ++i)
			{
				cin >> right[i];
			}
			char res;
			cin >> res;
			if(res == '=')
			{
				REP(j,right)
													mark[right[j]] = 1;

				REP(j,left)
				mark[left[j]] = 1;
			}
			else
			{
				if(res == '>')
					swap(left,right);
				checks.push_back(make_pair(left,right));
				REP(i,left)
				tL.insert(left[i]);
				REP(i,right)
				tR.insert(right[i]);
			}

		}
		int ans = 0;
		int c = 0;
		int emp = 0;
		int chEmp = 0;
		for(int i = 1 ; i <= n ; ++i)
		{
			if(mark[i])
				continue;
			if(tL.find(i) == tL.end() && tR.find(i) == tR.end())
			{
				emp++;
				chEmp = i;
				continue;
			}
			if(tL.find(i) != tL.end() && tR.find(i) != tR.end())
			{

				continue;
			}
			if(tL.find(i) == tL.end() && tR.find(i) != tR.end())
			{
				++c;
				ans = i;
			}
			if(tR.find(i) == tR.end() && tL.find(i) != tL.end())
			{
				++c;
				ans = i;
			}
		}
		if(c == 1)
		{
			yes(ans);

		}
		else
		if(c == 0 && emp == 1)
		{
			yes(chEmp);
		}
		else no();


	}
}

