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
int tc;
string str;
double me,his;
double dp[21][21][2001];

// Cyclic recurrence
// Simulate up to a high depth, and precision will be good enough.
// Special cases that might cause WA :
// Judge might give empty lines instead of WLWLWLWL.
// If the probability of winning is 1.0, but you lose, this case is invalid. :)
double solve(int my_score,int his_score, int turn,int cyc)
{
	//turn = (my_score + his_score) % 10;
	turn %= 10;
	if(cyc < 0)
		return 0;
	if(my_score == 21)
		return 1.0;
	if(his_score == 21)
		return 0.0;
	double &ret = dp[my_score][his_score][cyc];
	if(ret == ret)
		return ret;
	if(my_score == 20 && his_score == 20)
	{
		if(cyc == 0)
			return 0;
		return ret = solve(15,15,turn,cyc - 1);
	}
	double p = turn < 5 ? me : his;
	return ret = 1.0 * p * solve(my_score + 1,his_score,turn + 1,cyc) + (1.0 - p) * 1.0 * solve(my_score,his_score + 1,turn + 1,cyc);


}
int main()
{
	ios
	cin >> tc;
	cout << fixed;
	cout << setprecision(6);
	int tst = 1;
	while(tc--)
	{
		cin.ignore();
		double bad = 0;
		getline(cin,str);
		cin >> me >> his;
		memset(dp,-1,sizeof(dp));
		int my_score = 0, his_score = 0;
		int tu = 0;
		REP(i,str)
		{

			if(str[i] == 'W') ++my_score;
			else ++his_score;
			if( (my_score == 21 || his_score == 21) && i != sz(str) - 1 )
				bad = 1;
			if(my_score == 20 && his_score == 20)
				my_score = 15,his_score = 15;
			if(tu < 5 && me == 1.0 && str[i] =='L') bad = 1;
			if(tu < 5 && me == 0.0 && str[i] =='W') bad = 1;
			if(tu >= 5 && his == 1.0 && str[i] =='L') bad = 1;
			if(tu >= 5 && his == 0.0 && str[i] =='W') bad = 1;

			tu++;
			tu %= 10;
		}

		cout << "Case " << (tst++) <<": ";
		if(bad)
			cout <<"-1.000000\n";
		else
		{
			cout << solve(my_score,his_score,tu,2000) << "\n";
		}


	}
}
