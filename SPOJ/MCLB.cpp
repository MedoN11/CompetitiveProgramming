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
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
using namespace std;
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
int main()
{

	fast
	int t;
	cin >> t;
	int tc = 1;
	string forb = ""; for(int i = 0 ; i < 64 ; ++i) forb += 'R';
	while(t--)
	{
		string a,b; cin >> a >> b;

		unsigned long long x  = 0 , y = 0;
		for(int i = 0 ; i < a.size() ; ++i)
			if(a[i] == 'R') x |= (1ULL << (a.size() - i - 1));
		for(int i = 0 ; i < b.size() ; ++i)
			if(b[i] == 'R') y |= (1ULL << (a.size() - i - 1));
		if(forb == a || forb == b || x < y)
			cout << "Case " << (tc++)<<": The goal state will never be reached!" << "\n";
		else
		cout << "Case " << (tc++) <<": The goal state could be reached after " << (unsigned long long)((x - y)) <<" laser beams." << "\n";

	}
}

