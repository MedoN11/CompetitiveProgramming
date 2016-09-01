#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
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
#define fst first
#define snd second
#define pb push_back
#define fast std::ios_base::sync_with_stdio(false);
#define LL long long
#define endl "\n"
#define lp(i,n) for(int i=0;i<(int)n;i++)
#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);i++)
#define neg(v)       memset(v,-1,sizeof(v))
#define emp(v)       memset(v,0,sizeof(v))
#define lp1(i,n)    for(int i=1;i<=(int)n;i++)
using namespace std;
#define FOR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vii;
typedef pair<int,int> ii;
#define readfile freopen("input.txt","r",stdin);
#define writefile ("output.txt","w",stdout);
#define PI 3.1415926536
typedef pair<LL,LL> pLL;

LL gcd(LL a, LL b) { if(b==0) return a;   return gcd(b,a%b);  }
LL lcm (LL a, LL b) {   return a*(b/(gcd(a,b)));  }
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline LL toLL(string s){LL v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

// Dynamic Programming with Profiles
// all of these defines are only for Competitive Programming.

class DengklekPaintingSquares {
    
    
public:
    int numSolutions(int,int);
    
};

int getBit(int num, int idx) {
    if( ((num >> idx) & 1) == 1) return 1;
    else return 0;
}


int mod = 1000000007;
int DP[101][6561];
int N;
int M;

int pow3[9];
int get3[6561][9];
int set3[6561][9][3];

void pre()
{
    // template for generating get and set of base 3...0 1 2.
    pow3[0] = 1;
    for(int i=1; i <= 8; i++)
        pow3[i] = 3 * pow3[i-1];
    
    for(int i=0; i < pow3[8]; i++)
        for(int j=0; j <= 8; j++)
            get3[i][j] = (i/pow3[j]) % 3;
    
    for(int i=0; i < pow3[8]; i++)
        for(int j=0; j <=8; j++)
            for(int k=0; k <= 2; k++)
                set3[i][j][k] = i + (k - get3[i][j]) * pow3[j];
}


int solve(int idx,int msk){
    
    if(idx == N){
        bool goodmsk = true;
        for(int i = 0 ; i < M; i++) if(get3[msk][i]==1){
            goodmsk = false;
            break;
        }
        return goodmsk? 1 : 0;
    }
    if(DP[idx][msk] != -1) return DP[idx][msk];
    int res = 0;
    for(int config = 0 ; config < (1<<M) ; config++){
        bool bad = false;
        for(int i = 0; i < M ; i++){
            if(((getBit(config,i)==1)&&(get3[msk][i]==2))||(getBit(config,i)==0&&get3[msk][i]==1)){
                bad = true;
                break;
            }
        }
        if(!bad){
            
            int newmsk = 0;
            for(int i = 0 ; i < M ; i++){
                if(getBit(config,i)==1){
                    int degree = 0;
                    
                    if(i>0) if (getBit(config,i-1)==1) degree++;
                    
                    if(i<M-1) if(getBit(config,i+1)==1) degree++;
                    
                    if(get3[msk][i]!=0) degree++;
                    
                    if((degree&1)==1) newmsk = set3[newmsk][i][1];
                    
                    else  newmsk = set3[newmsk][i][2];
                }
                else newmsk = set3[newmsk][i][0];
                
            }
            res  = ((res%mod) +(solve(idx+1,newmsk)%mod))%mod;
        }
        
    }
    return DP[idx][msk] = res;
}

int DengklekPaintingSquares::numSolutions(int R,int C){
    N = R; M = C;
    clr(DP,-1);
    pre();
    return solve(0,0);
}
