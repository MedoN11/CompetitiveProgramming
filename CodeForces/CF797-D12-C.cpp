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
const int maxn = 100005;
char best[maxn];
char s[maxn];
int n;
int main()
{
	scanf("%s",s); n = strlen(s);
	for(int i = n - 1 ; i >= 0; --i)
	{
		if(i == n - 1) best[i] = s[i];
		else best[i] = min(best[i + 1],s[i]);
	}
	stack<char> stk;
	for(int i = 0 ; i < n ; ++i)
	{
		stk.push(s[i]);
		while(i + 1 < n && !stk.empty() && stk.top() <= best[i + 1])
		{
			printf("%c",stk.top()); stk.pop();
		}


	}

	while(!stk.empty())
	{
		printf("%c",stk.top()); stk.pop();
	}
}
