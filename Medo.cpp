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
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define pb push_back
const int maxn = 1000*1005;
char s[maxn];
char tmp[maxn];
int n;
bool changes()
{

	for(int i = 0 ; i < n ;++i)
		tmp[i] = s[i];

	bool f = 0;
	for(int i = 0 ; i < n - 1; ++i)
	{
		if(s[i] == '1' && s[i + 1] == '0')
		{
			tmp[i] = '0';
			tmp[i + 1] = '1';
			f = 1;
		}
	}
	for(int i = 0 ; i < n ; ++i) s[i] = tmp[i];
	return f;
}

int slow()
{
	int x = 0;
	while(changes())
	{
//		for(int i = 0 ; i < n ; ++i)
//			cout << s[i];
//		cout << "\n";
		++x;
	}
	return x;
}
char c[501];
int main()
{
	scanf("%s",s);
	n = strlen(s);
	for(int i = 0 ; i < n ; ++i)
	{
		if(s[i] == 'M') s[i] = '1';
		else s[i] = '0';
		c[i] = s[i];
	}
	int ones = 0;
	int ind = n;
	for(int i = 0 ; i < n ; ++i)
	{
		if(c[i] == '1')
		{
			++ones;
			if(ind == n) ind = i;
		}
	}
	int pos = n - ones ;
	int st = 1;
	int pay = 0;
	cerr << ind << " " << pos << "\n";
	for(int i = ind + 1; i <= pos; ++i)
	{
		if(c[i] == '1') ++st;
		else
		{

			pay += st -1;
			st = 0;


		}
		++pay;


	}
	printf("%d ",pay); cout << slow();


}
