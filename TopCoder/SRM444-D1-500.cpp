#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<memory.h>
#include<bitset>
#include <stack>
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
#include <cmath>
#include <map>
using namespace std;
#define FOR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define readfile freopen("input.txt","r",stdin);
#define writefile ("output.txt","w",stdout);
#define lp(i,n) for(int i=0;i<(int)n;i++)
#define lp1(i,n)    for(int i=1;i<=(int)n;i++)
#define sz(v)				((int)((v).size()))
#define all(v)				((v).begin()), ((v).end())
#define neg(v)       memset(v,-1,sizeof(v))
#define emp(v)       memset(v,0,sizeof(v))
#define endl "\n"
#define pb push_back
#define fast std::ios_base::sync_with_stdio(false);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef long long LL;

int arr[10][25];
int N,M;
int dp[25][1<<10];
// 0 tiled as 1x1 block so profile can't be extended.
// 1 tiled as 2x2 block so profile can be extended.
int oo = -2000000;

class FourBlocks {
public:
    int maxScore(vector <string>);
};
	int getBit(int num, int idx) {
    if( ((num >> idx) & 1) == 1) return 1;
    else return 0;
}
 int setBit1(int num,int idx){

    return num|((1<<idx));

}

static bool validProfile(int col,int msk){

    for(int i=0;i<N;i++){
        if(getBit(msk,i)==1) if(arr[i][col]==1) return false;
    }

    return true;
}
static	int process(int col,int msk,int config){
    int fours = 0;
    int ones = 0;
    for(int i=0;i<N;i++){
        if(getBit(msk,i)==1&&(arr[i][col]==1||getBit(config,i)==1)) return oo;


        if(i<N-1&&(getBit(msk,i)==1)&&(arr[i][col]!=1&&arr[i+1][col]!=1&&getBit(msk,i+1)==1)&&getBit(config,i)==0&&getBit(config,i+1)==0){
            fours++;
            i++;
        }
        else if(getBit(config,i)==0) ones++;

    }
    //		if(fours>0){
    //			System.out.println(col+" "+Integer.toBinaryString(msk)+" "+Integer.toBinaryString(config));
    //		}
    return (16*fours)+ones;
}
static int countOnes(int msk){
    int cnt = 0;
    for(int i=0;i<N;i++) if(getBit(msk,i)==0) cnt++;
    return cnt;
}
static int solve(int col,int msk){
    if(col==M) return 0;
    if(dp[col][msk]!=-1) return dp[col][msk];
    if(col==0){
        int soln = 0;
        for(int config=0;config<(1<<N);config++){
            if(!validProfile(col,config)) continue;
            int ones = countOnes(config);
            soln = max(soln,ones+solve(col+1,config));


        }
        return dp[col][msk]= soln;
    }
    else{
        int soln = 0;
        for(int config =0;config<(1<<N);config++){
            if(!validProfile(col,config)) continue;
            int r = process(col,msk,config);


            soln = max(soln,r+solve(col+1,config));

        }
        return dp[col][msk]= soln;
    }
}

int FourBlocks::maxScore(vector <string> grid){

    neg(dp);
     N = sz(grid);
    M = sz(grid[0]);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j] =  grid[i].at(j)=='1'?1:0;
        }
    }
    int soln = solve(0,0);
    return soln;
}
