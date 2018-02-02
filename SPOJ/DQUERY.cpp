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
using namespace std;
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define ll  long long
#define EPS (1e-8);
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define neg(x) memset(x,-1,sizeof(x));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define INF (1LL << 61)
#define endl "\n"
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> ii;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
const int maxn = 30015;
const int inf = 1 << 30;
int nxt[maxn],arr[maxn];
int n,m;
int q;

// Persitent Segment Tree
// Problem can be reduced to numbers > r
// simply for each number we calculate it's nxt occurence to the right
// then build segment tree over these values
// for a range [l,r] we want to count all values < r
// can be done by merge sort tree in nlog^2n or persitence in just logn!
map<int,int> lst;

struct Vertex {
	Vertex *l,*r;
	int sum;
	Vertex(int sum) {
		this->sum = sum;
		l = nullptr, r = nullptr;
	}
	Vertex(Vertex *l, Vertex *r) {
		this->l = l;
		this->r = r;
		if(l) sum += l->sum;
		if(r) sum += r->sum;
	}
};

Vertex* build(int l,int r) {
	if(l == r) {
		return new Vertex(0);
	}
	int mid = l + (r - l) / 2;
	return new Vertex(build(l,mid),build(mid + 1,r));
}
Vertex* update(Vertex *v,int l,int r,int p,int val) {
	if(p < l || p > r) return v;
	if (l == r) {
		return new Vertex(val + v->sum);
	}
	int mid = l + (r - l) / 2;
	return new Vertex(update(v->l,l,mid,p,val),update(v->r,mid + 1,r,p,val));

}
int query(Vertex* left,Vertex *right,int l,int r,int ql,int qr) {

	if(ql > r || qr < l)
		return 0;
	if(ql <= l && r <= qr) {
		return right->sum - left->sum;
	}

	int mid = l + (r - l) / 2;
	return query(left->l,right->l,l,mid,ql,qr) + query(left->r,right->r,mid + 1,r,ql,qr);
}

Vertex* tree_root[maxn];


int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n ; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = n ; i >= 1 ; --i) {
		if(lst.find(arr[i]) == lst.end())
			nxt[i] = n + 1;
		else nxt[i] = lst[arr[i]];
		lst[arr[i]] = i;
	}
	tree_root[0] = build(0,n + 5);
	for (int i = 1 ; i <= n ; ++i) {
		tree_root[i] = update(tree_root[i - 1],0,n + 5,nxt[i],1);
	}
	// count indices with value > r
	scanf("%d",&q);
	while(q--) {
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",query(tree_root[l - 1],tree_root[r],0,n + 5,r + 1,n + 1));

	}
}
