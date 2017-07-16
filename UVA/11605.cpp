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
#define ll  double
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
int t;
typedef vector<double> vi;
typedef vector<vector<double> > matrix;
double px[105],py[105],pz[105];
int N,M,P,MOVES;
int main()
{

	scanf("%d",&t);
	int tc = 1;
	while(t--)
	{
		scanf("%d %d %d %d",&N,&M,&P,&MOVES);
		for(int i = 1; i <= N; i++)
		{
			px[i] = (i * (N - i + 1) * 2 - 1) / (1.0*N * N);
		}
		for(int i = 1; i <= M; i++)
		{
			py[i] = (i * (M - i + 1) * 2 - 1) / (1.0*M * M);
		}
		for(int i = 1; i <= P; i++)
		{
			pz[i] = (i * (P - i + 1) * 2 - 1) / (double)(P * P);
		}
			double tot = 0;
		for(int i = 1 ; i <= N ; ++i)
		{
			for(int j = 1 ; j <= M ; ++j)
			{
				for(int k = 1 ; k <= P ; ++k)
				{
					double prob = 1.0*px[i] * py[j] * pz[k];
					//tot += calc(k,prob,0);
					matrix mat(2,vi(2));
					mat[0][0] = 1.0 - prob;
					mat[0][1] = prob;
					mat[1][0] = prob;
					mat[1][1] = 1.0 - prob;
					matrix res = matrixPow(mat,MOVES);
					tot += 1.0*res[0][1];

				}
			}
		}

		printf("Case %d: %.10f\n",tc++,tot);

	}

}


