#include<set>
#include<map>
#include<list>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<iomanip>
#include<cmath>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include<stack>
#define ll long long
using namespace std;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int dp[41][41][16500][2];
int n,ones,z;
string str;
int tc;
int sz;
int solve(int ind,int zeros,int rem,int lst)
{
	if(rem < 0 || zeros > 40)
		return 0;
	if(ind == sz)
		return rem == 0 && zeros == z ? 1 : 0;
	int &ret = dp[ind][zeros][rem][lst];
	if(ret != -1)
		return ret;
	ret = 0;
	if(str[ind] == '0')
		ret += solve(ind + 1,zeros + 1,rem,0);
	else
	{
		ll curr = 0;
		for(int j = ind ; j < sz ; ++j)
		{
			if(curr > rem)
				break;
			curr <<= 1; curr += str[j] - '0';
			if(!lst && j - ind + 1 > 2)
				ret += solve(j + 1,zeros, rem - curr,1);
			else
			{
				if(j == ind && !lst)
				{
					ret += solve(j + 1,zeros,rem - 1,1);
				}
				else
				{
					if(!lst && str[j] == '1' && str[j - 1] == '1')
					{
						ret += solve(j + 1,zeros,rem - 3,1);
						ret += solve(j + 1,zeros,rem - 2,1);
					}
				}
			}
		}
	}
	return ret;


}
int main()
{
	fast
	tc = 1;
	while(cin >> n >> ones)
	{
		if(!n && !ones)
			break;
		z = n - ones;
		cin >> str;
		sz = sz(str);
		memset(dp,-1,sizeof(dp));
		cout << "Case #"<<(tc++)<<": ";
		int ans = solve(0,0,ones,0);
		if(ans == 0)
			cout << "NO";
		else if(ans == 1)
			cout <<"YES";
		else cout << "NOT UNIQUE";
		cout << "\n";
	}
}
