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
int pre[5001][5001];
int sum[5001][5001];
int grid[5001][5001];
int n,m,b,q;
typedef pair<int,int> ii;
map<ii,ii> mp;
void rotate(int &x,int &y)
{
	int a = x, b = y;
	x = a + b, y = a - b + m;
}

int getSum(int x1,int y1,int x2,int y2)
{
	//cerr << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
	int sum = grid[x2][y2];
	sum -= grid[x1 - 1][y2];
	sum -= grid[x2][y1 - 1];
	sum += grid[x1 - 1][y1 - 1];
	return sum;
}
int main()
{


	fast
	int tc = 1;
	while(cin >> n >> m >> b >> q)
	{
		if(!(n + m + b + q))
			break;
		memset(grid,0,sizeof(grid));
		for(int j = 0 ; j < b ; ++j)
		{
			int x,y; cin >> x >> y;
			rotate(x,y);
			grid[x][y] = 1;
		}
		for(int x = 1 ; x <= n + m; ++x)
		{

			for(int y = 1 ; y <= n + m ; ++y)
			{
//
				grid[x][y] += grid[x - 1][y];

				grid[x][y] += grid[x][y - 1];

				grid[x][y] -= grid[x - 1][y - 1];
				//cerr << grid[x][y];

			}
			//cerr << "\n";
		}



cout <<"Case " <<(tc)<<":\n";
		while(q--)
		{
			int d; cin >> d; d = min(d,2000);
			int ans = 0;
			pair<int,int> p = make_pair(1,1);
			for(int y = 1 ; y <= m ; ++y)
			{
				for(int x = 1 ; x <= n ; ++x)
				{
					int i = x, j = y; rotate(i,j);
					int up = max(1,i - d),down = min(n + m,i + d),left = max(1,j - d) ,right = min(n + m,j + d);
					int res = getSum(up,left,down,right);

					 if(ans < res) ans = res , p = make_pair(x,y);

				}
			}

			cout << ans << " (" << p.first << "," << p.second <<")" << "\n";

		}
		tc++;

	}

}



