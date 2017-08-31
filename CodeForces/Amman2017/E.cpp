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
using namespace std;
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
int f1[26],f2[26];
int main()
{
	ios;
	int tc;
	cin >> tc;
	while(tc--)
	{
		string a,b;
		cin >> a >> b;
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		REP(i,b) f2[b[i] - 'a']++;
		int ans = 0;
		for(int i = 0 ; i < sz(a) ; ++i)
		{
			int ind = a[i] - 'a';
			if(f2[ind] > 0)
			{
				++ans;
				f2[ind]--;
			}
			else
			{

				break;
			}
		}
		cout << ans << "\n";

	}
}
