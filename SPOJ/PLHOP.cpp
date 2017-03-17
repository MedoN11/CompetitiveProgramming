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
#include <unordered_map>
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
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vi;
vvi matrixUnit(int n) {
	vvi res(n, vi(n));
	for (int i = 0; i < n; i++)
		res[i][i] = 1;
	return res;
}

vvi matrixAdd(const vvi &a, const vvi &b) {
	int n = a.size();
	int m = a[0].size();
	vvi res(n, vi(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = (a[i][j] + b[i][j]);
	return res;
}

vvi matrixMul(const vvi &a, const vvi &b) {
	int n = a.size();
	int m = a[0].size();
	int k = b[0].size();
	vvi res(n, vi(k));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			res[i][j] = 1LL << 55;
			for (int p = 0; p < m; p++)
			{
				res[i][j] = min((res[i][j]) ,(long long) (a[i][p]) + (b[p][j]));
			}
		}
	}
	return res;
}

vvi matrixPow(const vvi &a, ll p) {
	if (p == 1)
		return a;
	if (p & 1)
		return matrixMul(a, matrixPow(a, p - 1));
	return matrixPow(matrixMul(a, a), p / 2);
}


int main()
{

	int t;
	scanf("%d",&t);
	int tc = 1;
	int n,k;
	while(t--)
	{
		scanf("%d %d",&k,&n);
		vvi mat(n,vi(n,0));
		vvi floyd(n,vi(n,1LL << 55));
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < n ; ++j)
			{
				scanf("%lld",&mat[i][j]);

				floyd[i][j] = mat[i][j];
			}
		}
		for(int k = 0 ; k < n ; ++k)
		{
			for(int i = 0 ; i < n ; ++i)
			{
				for(int j = 0 ; j < n ; ++j)
				{
					floyd[i][j] = min(floyd[i][j],floyd[i][k] + floyd[k][j]);
				}
			}
		}
		vvi trans = matrixPow(mat,k - 1);
		vvi res = matrixMul(trans,floyd);
		printf("Region #%d\n",tc++);
		for(int i = 0 ; i < n ; ++i)
		{
			printf("%lld",res[i][0]);
			for(int j = 1 ; j < n ; ++j)
			{
				printf(" %lld",res[i][j]);
			}
			puts("");
		}
	}
}
