#include <bits/stdc++.h>
#define pi pair<pair<int,int>,int >
#define mk make_pair
using namespace std;

char dir[200000 + 5];
int R,C, len;

int canRow(int x)
{

	int steps = 0;
	for(int k = 0 ; k < len ; ++k)
	{
		if(dir[k] == '^' || dir[k] == 'v') continue;
		int xc = x;
		if(dir[k] == '<') --xc;
		else ++xc;
		if(xc <= 0 || xc > C)
		{
			++steps;
			continue;
		}
		x = xc;


	}
	return steps;
}

int canCol(int y)
{

	int steps = 0;
	for(int k = 0 ; k < len ; ++k)
	{
		if(dir[k] == '<' || dir[k] == '>') continue;
		int yc = y;
		if(dir[k] == '^') --yc;
		else ++yc;
		if(yc <= 0 || yc > R)
		{
			++steps;
			continue;
		}
		y = yc;

	}
	return steps;
}

int getRow()
{
	int ans = 1 << 30, lo = 1, hi = C;
	while(hi - lo > 3)
	{

		int d = (hi - lo) / 3;
		int m1 = lo + d, m2 = hi - d;
		int f1 = canRow(m1), f2 = canRow(m2);
		if(f1 > f2)
			lo = m1;
		else if(f1 < f2)
			hi = m2;
		else
		{
			lo = m1;
			hi = m2;
		}
	}
	for(int i = lo ; i <= hi ; ++i)
	{
		ans = min(ans, canRow(i));
	}
	return ans;
}
int getCol()
{


	int ans = 1 << 30, lo = 1, hi = R;
	while(hi - lo > 3)
	{

		int d = (hi - lo) / 3;
		int m1 = lo + d, m2 = hi - d;
		int f1 = canCol(m1), f2 = canCol(m2);
		if(f1 > f2)
			lo = m1;
		else if(f1 < f2)
			hi = m2;
		else
		{
			lo = m1;
			hi = m2;
		}
	}
	for(int i = lo ; i <= hi ; ++i)
		ans = min(ans, canCol(i));
	return ans;
}

int main(){


	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d", &R, &C);
		scanf("%s", dir);
		len = strlen(dir);
		printf("%d\n", getRow() + getCol());
	}

}
