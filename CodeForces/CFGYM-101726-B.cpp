#include <bits/stdc++.h>
#include <tr1/unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define clr(ma) memset(ma,-1,sizeof ma)
#define INF 10000000000000001ll
#define vi vector<int>
#define pi pair<int ,ll >
#define T pair<pi,double>
#define mk make_pair
#define getBit(m,i) ((m&(1ll<<i))==(1ll<<i))
#define setBit(m,i) (m|(1<<i))
#define setBit2(m,i) (m|(1ll<<i))
#define cont(i,ma) ((ma.find(i))!=(ma.end()))
#define in(i) scanf("%d",&i)
#define in2(i,j) scanf("%d%d",&i,&j)
#define in3(i,j,k) scanf("%d%d%d",&i,&j,&k)
#define in4(i,j,k,l) scanf("%d%d%d%d",&i,&j,&k,&l)
#define itr map<int,int>::iterator
#define itr2 set<int>::iterator
#define id(k) scanf("%9lf",&k)
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sc(s) scanf("%s",s)
#define clean(vis)  memset(vis,0,sizeof vis)
#define  bitcount(x)  (__builtin_popcount(x))
#define rep0(x) for(int i=0;i<x;i++)
#define rep1(x) for (int i=1;i<x;i++)
#define xx first
#define yy second
#define LOG 23
#define  null 0
using namespace std;
const int N = 1000000+5;
double p [2][11][40];
vector<vi> attack [2];
vi sz;
int good=0;
void get(vi & v , int pos, int k){
    if (k<0) return ;
    if (pos==v.size()) {
        good+=(k==0);
    }
    else{
        for (int i=1;i<=v[pos];i++){
            get(v,pos+1,k-i);
        }
    }
}
double dp [2][305][305];
double solve(int t, int v1 ,int v2){
    if (v1<=0) return 0;
    if (v2<=0) return 1;
    double & res = dp[t][v1][v2];
    if (res==res) return res;
    res=t;
    for (int i=0;i<sz[t];i++) {
        double tmp = 0;
        for (int j = 1; j < 40; j++){
            tmp+=p[t][i][j]*solve(1-t,t==0?v1:v1-j,t==1?v2:v2-j);
        }
        if (t) {
            if (res>tmp) res=tmp;
        }
        else{
            if (res<tmp) res=tmp;
        }
    }
    return res;


}
int va,vb,na,nb;
int main (){
 int t;
    in(t);
    while (t--){
        in2(va,vb);
        in2(na,nb);
        attack[0].assign(na,vi());
        attack[1].assign(nb,vi());
        sz ={na,nb};
        for (int i=0;i<na;i++){
            int d,x;
            in(d);
            while (d--) {
                in(x);
              //  cout<<d<<x<<endl;
                attack[0][i].push_back(x);
            }
        }
        for (int i=0;i<nb;i++){
          //  cout<<"kkk"<<endl;
            int d,x;
            in(d);
            while (d--) {
                in(x);
                attack[1][i].push_back(x);
            }
        }
     //cout<<"kkk"<<endl;
        for (int i=0;i<2;i++)
            for (int j=0;j<sz[i];j++)
                for (int val = 0;val<40;val++){
                    int tot=1;
                     good=0;
                    get(attack[i][j],0,val);
                    for (auto it : attack[i][j]) tot*=it;
                    p[i][j][val]=1.0*good/tot;
                }
        clr(dp);
        cout<<fixed<<setprecision(7)<<solve(0,va,vb)<<endl;

    }
}
