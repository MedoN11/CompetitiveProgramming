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
int n,m;
vector<ll> v;
 ll gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// Probability + math
 // summation of powers of two from 1 to n is 2^(n + 1) - 1
 //2^(n + 1) > 2^(n + 1) - 1
 // so the probability is determined only by the last round
 // now turns to a simple probability problem
int main()
{
	fast

	while(cin >> n >> m)
	{
		if(n + m == 0)
			break;

		v.clear();
		ll sum = 0;
		for(int i = 0 ; i < n ; ++i)
		{
			int x;
			for(int i = 0 ; i < m - 1 ; ++i)
			{
				 cin >> x;
			}
			cin >> x;
			v.push_back(x); sum += x;
		}
		for(int i = 0 ; i < n ; ++i)
		{
			int up = v[i], down = sum;
			if(!up)
			{
				cout << "0 / 1" << "\n";
				continue;
			}

			int g = gcd(up,down); up /= g, down /= g;
			cout << up <<" / "<< down << "\n";
		}
	}

}
