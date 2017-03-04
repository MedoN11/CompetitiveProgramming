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
#include<algorithm>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include<cstring>
#include <cmath>
#include <complex>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
using namespace std;
#define ll long long
#define MAXN 1000001
int len1,len2;
char num1[MAXN];
char num2[MAXN];

// regular base addition
// test cases for this problem are weak
int res1[MAXN],res2[MAXN];
int add(int base,int *arr)
{
    int n = 0;
    int carry = 0;
    for(int i = len1 - 1, j = len2 - 1 ; i >= 0 || j >= 0 ; --j,--i,++n)
    {
        int a = i >= 0 ? num1[i] - '0' : 0;
        int b = j >= 0 ? num2[j] - '0' : 0;
        arr[n] = (a + b + carry) % base;
        carry = (a + b + carry) / base;
    }
    while(carry > 0)
    {
        arr[n++] = carry % base;
        carry /= base;
    }
    --n;
    
    while(!arr[n--]);
    
    return n;
}

bool same(int n)
{
    for(int i = 0 ; i <= n ; ++i)
    {
        if(res1[i] != res2[i])
        return 0;
    }
    return 1;
}
int main()
{
    int t;
    int b1,b2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s %d %d",num1,num2,&b1,&b2);
        len1 = strlen(num1);
        len2 = strlen(num2);
        int n = add(b1,res1);
        int m = add(b2,res2);
        if(n == m && same(n))
        puts("yes");
        else puts("no");
    }
}
