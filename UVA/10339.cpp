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
#define ll unsigned long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define pb push_back

int main()
{

	int m1,m2;
	//freopen("out.txt","w",stdout);
	while(scanf("%d %d",&m1,&m2) != EOF)
	{
		ll diff = m1 > m2 ? m1 - m2 : m2 - m1;

		long double meet = 43200.0 / diff;

		long double curr = (1.0*meet*24.0*60*60 - 1.0*m1*meet);
		ll mn = (ll)(curr / 60.0 + 0.5);
		ll hr = mn / 60LL;
		mn %= 60; hr %= 12;
		if(hr == 0) hr = 12;
		printf("%d %d %02d:%02d\n",m1,m2,(int)hr,(int)mn);
	}



}

