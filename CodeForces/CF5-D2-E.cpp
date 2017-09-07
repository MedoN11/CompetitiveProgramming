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
#include <complex>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
int n,m;
const int maxn = 1005000;

vector<int>  seq;
int L[maxn],R[maxn];
int tmp_dp[maxn];
int main_dp[maxn];
map<int,int> cord;
int a[maxn];

//Reduce the problem to a straight line instead of circularity by finding the maximum element, and rotating the sequence so that it’s first. 
//Now add that element to the end. ( Trace few samples if you don’t see why this is correct modeling)
//Now for all of the elements do a co-ordinate compression, and let’s calculate for each element 
//the first element greater than it from left, and right.
// This is a standard problem that is solved by a stack.
//More details here : https://stackoverflow.com/questions/22542004/for-each-element-finding-the-closest-greater-element
//.. again very standard you will find many information on google.
//For maximum element handle it alone. Answer is easily frequency*(frequency-1)/2
//Now maintain a dp for each element of the sequence which contains how many elements equal to it are in the stack.
// this is done by maintaining two dp arrays one which contains how many elements i are in the stack, and the other contains the answer for each index
// simply when you pop an element decrements the tmp dp, and increment it when you push. That's why we did co-ordinate compression.
//Now each element will contribute dp[i] + 2.
//Special cases are when L[I] == 0 && R[I] == n..in this case you subtract 1 so you don’t over count.
int main()
{
	scanf("%d",&n);
	seq.resize(n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d",&seq[i]),cord[seq[i]] =1;
	int ind = 0;
	for(map<int,int>::iterator it = cord.begin() ; it != cord.end() ; it++) it->second = ind++;
	rotate(seq.begin(),max_element(all(seq)),seq.end());
	int cnt = 0;
	int mx = *max_element(all(seq));
	seq.pb(mx);
	for(int i = 0 ; i < n ; ++i)
		if(seq[i] == mx)
			cnt++;

	for(int i = 0 ; i < n ; ++i) a[i] = cord[seq[i]];

	for(int i = 0; i <= n ; ++i)
	{
		R[i] = n ,L[i] = 0;
	}
	stack<int> s;
	for(int i = 0 ; i <= n ; ++i)
	{

		main_dp[i] = tmp_dp[a[i]];
		tmp_dp[a[i]]++;
		while(!s.empty() && seq[s.top()] < seq[i])
		{
			R[s.top()] = i;
			tmp_dp[a[s.top()]]--;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()) s.pop();
	for(int i = n ; i >= 0 ; --i)
	{


		while(!s.empty() && seq[s.top()] < seq[i])
		{
			L[s.top()] = i;

			s.pop();
		}
		s.push(i);
	}

	long long res = 0;
	for(int i = 0 ; i < n ; ++i)
	{
		if(seq[i] == seq[0])
			continue;
		//cerr << (i + 1) <<" " << (cntR[i] + 1) << "\n";
		res += main_dp[i];
		res += 2;
		if(L[i] == 0 && R[i] == n)
		{
			res--;
		}

	}
	res += (1LL*cnt*(cnt - 1))/2LL;

	printf("%lld\n",res);
}
