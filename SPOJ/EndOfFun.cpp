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
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#define ll  long long
#define EPS (1e-8);
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define neg(x) memset(x,-1,sizeof(x));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define endl "\n"
using namespace std;
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
typedef pair<int,int> ii;
#define MAXN 500
int n;
ll A[MAXN][MAXN];
ll B[MAXN][MAXN];
ll sum = 0;

void mul()
{

	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ; ++j)
		{
			for(int k = 0 ; k < n ; ++k)
			{
				sum += 1LL*A[i][k] * 1LL*B[k][j];
			}
		}
	}
}
ll preColA[MAXN];
ll preRowB[MAXN];

int main()
{
	fast
	cin >> n;
	for(int i = 0 ; i < n ; ++i)
	{

		for(int j = 0 ; j < n ; ++j)
		{
			cin >> A[i][j];

			preColA[j] += 1LL*A[i][j];


		}
	}

	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ; ++j)
		{
			cin >> B[i][j];
			preRowB[i] += 1LL*B[i][j];


		}
	}
	mul();
	//cout << sum << endl;
	int q;
	cin >> q;
	while(q--)
	{
		char c;
		int i,j;
		ll v;
		cin >> c >> i >> j >> v;
		if(c == 'A')
		{

			sum -= 1LL*A[i][j] * preRowB[j];
			preColA[j] -= A[i][j];
			A[i][j] = v;
			sum += 1LL*A[i][j] * preRowB[j];
			preColA[j] += 1LL*A[i][j];
			cout << sum << endl;
		}
		if(c == 'B')
		{

			sum -= 1LL*B[i][j] * preColA[i];
			preRowB[i] -= B[i][j];
			B[i][j] = v;
			sum += 1LL*B[i][j] * preColA[i];
			preRowB[i] += 1LL*B[i][j];

			cout << sum << endl;
		}
	}

}
