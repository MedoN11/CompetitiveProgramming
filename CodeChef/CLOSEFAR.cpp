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
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define time __time
typedef pair<int,int> pii;
typedef pair<int,pii> entry;
 int block = 200;
const int maxn = 40001;
vector<int> tree[maxn];
int n;
struct Query {
	int L,R,t,ind;
	int lca;
	Query(int l,int r,int t,int ind) {
		this->L = l;
		this->R = r;
		this->t = t;
		this->ind = ind;
		lca = -1;
	}
};
vector<Query> queries;
int tin[maxn],tout[maxn],node_val[maxn],lvl[maxn],dp[maxn][30],arr[3*maxn],pr[maxn];
int tim = 0;

bool MO_CMP(Query &a, Query &b)
{
	if(a.L/block != b.L/block) {
		return a.L/block < b.L/block;

	}
	else {
		return a.R < b.R;
	}
}
void dfs(int u,int l) {
	arr[tim] = node_val[u];
	tin[u] = tim++;
	lvl[u] = l;
	REP(i,tree[u]) {
		int v = tree[u][i];
		if(v == pr[u])
			continue;
		pr[v] = u;
		dfs(v,l + 1);
	}
	arr[tim] = node_val[u];
	tout[u] = tim++;
}
map<int,int> freq;
int solve(int u,int p) {
	if(p == 0) return pr[u];
	int &ret = dp[u][p];
	if(ret != -1)
		return ret;
	return ret = solve(solve(u,p - 1),p - 1);
}
map<int,int> cord;
int LCA(int u,int v) {
	if(lvl[u] < lvl[v])
		swap(u,v);
	int log = 26;
	for(int k = log ; k >=0 ; --k) {
		int tmp_u = solve(u,k);
		if(lvl[tmp_u] >= lvl[v])
			u = tmp_u;
	}
	if(u == v) return u;
	for(int k = log ; k >= 0 ; --k) {
		int nxt_u = solve(u,k);
		int nxt_v = solve(v,k);
		if(nxt_u != nxt_v)
			u = nxt_u,v = nxt_v;
	}
	return pr[u];
}
int lo[4*maxn],hi[4*maxn];

struct Segment {
	int left_,right,ans;
	Segment() {

	}
	Segment(int left,int right,int ans) {
		this->left_ = left;
		this->right = right;
		this->ans = ans;
	}
	Segment merge(Segment &o) {
		Segment ret = Segment(1<<30,-(1<<30),1<<30);
		ret.left_ = min(left_,o.left_);
		ret.right = max(o.right,right);
		ret.ans = min(o.ans,ans);
		if(this->right != -(1 << 30) && o.left_ != (1 << 30))
		ret.ans = min(abs(this->right-o.left_),ret.ans);
		return ret;
	}
};
Segment ans[4*maxn];
void build(int ind,int l,int r) {
	lo[ind] = l, hi[ind] = r;
	if(lo[ind] == hi[ind]) {
		ans[ind] = Segment(1<<30,-(1<<30),1<<30);
		return;
	}
	int mid = l + (r - l) / 2;
	build(ind*2,l,mid);
	build(ind*2+1,mid + 1,r);
	ans[ind] = ans[ind*2].merge(ans[ind*2+1]);

}

void update_st(int ind,int p,int v) {
	if(p < lo[ind] || p > hi[ind])
		return;
	if(p == lo[ind] && p == hi[ind]) {
		if(v == 0) ans[ind] = Segment(1<<30,-(1<<30),1<<30);
		else ans[ind] = Segment(node_val[p],node_val[p],1<<30);
		return;
	}
	update_st(ind*2,p,v);
	update_st(ind*2+1,p,v);
	ans[ind] = ans[ind*2].merge(ans[ind*2+1]);

}
Segment query(int ind,int l,int r) {
	if(r < lo[ind] || l > hi[ind])
		return Segment(1<<29,-(1<<29),1<<29);
	if(l <= lo[ind] && hi[ind] <= r)
		return ans[ind];
	Segment a = query(ind * 2,l,r);
	Segment b = query(ind * 2 + 1,l,r);
	return a.merge(b);

}
set<int> s;
void put(int ind) {
	//cerr << "Add " << arr[ind] << "\n";
	update_st(1,cord[arr[ind]],1);
	s.insert(arr[ind]);

}
void erase(int ind) {
	//cerr << "Remoe " << arr[ind] << "\n";

	update_st(1,cord[arr[ind]],0);
	//cerr << query(1,0,tim - 1).ans << "\n";
	s.erase(arr[ind]);
}
int query_one() {
	if(sz(s) > 0)
		return abs(*s.rbegin() - *s.begin());
	else return 0;
}
int query_two() {
	//cerr << "Query" << "\n";
	Segment seg = query(1,0,n - 1);
	return seg.ans;
}
void add(int ind) {
	freq[arr[ind]]++;
	if(freq[arr[ind]] == 1) {
		put(ind);
	} else {
		erase(ind);
	}
}
void remove(int ind) {
	freq[arr[ind]]--;
	if(freq[arr[ind]] == 1) {
		put(ind);
	} else {
		erase(ind);
	}
}
int res[maxn];
int main() {

	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d",&node_val[i]);
		cord[node_val[i]] = 1;
	}
	int idx = 0;
	for(map<int,int>::iterator it = cord.begin(); it != cord.end() ;it++) {
		it->second = idx++;

	}
	// read queries
	int u,v;
	for (int i = 0 ; i < n - 1 ; ++i) {
		scanf("%d %d",&u,&v);
		--u,--v;
		tree[u].pb(v);
		tree[v].pb(u);
	}

	char c;
	// build dfs order

	pr[0] = 0;
	dfs(0,0);
	// process queries
	sort(node_val,node_val + n);
	build(1,0, n - 1);
	int q;
	cin >> q;
	block = (int)(sqrt(q)) + 1;
	cerr << block;
	vector<Query> queries;
	for(int i = 0 ; i < q ; ++i) {
		scanf(" %c %d %d",&c,&u,&v);
		--u,--v;
		int t = 0;
		if(tin[v] < tin[u]) swap(u,v);
		if(c == 'C') t = 1;
		int lca = LCA(u,v);
		if(lca == u) {
			queries.pb(Query(tin[u],tin[v],t,i));
		} else {
			queries.pb(Query(tout[u],tin[v],t,i));
			queries.back().lca = tin[lca];
		}
	}

	int currentL = 0; int currentR = -1, L,R;
	sort(all(queries),MO_CMP);
	REP(i,queries) {
		L = queries[i].L; R = queries[i].R;
		while (currentR < R) {
			currentR++;
			add(currentR);

		}
		while (currentR > R) {

			remove(currentR);
			currentR--;
		}
		while (currentL < L) {
			remove(currentL);
			currentL++;

		}
		while (currentL > L) {
			currentL--;
			add(currentL);
		}
		if(queries[i].lca != -1) add(queries[i].lca);
		if(queries[i].t) {
			res[queries[i].ind] = query_two();
		} else {
			res[queries[i].ind] = query_one();
		}
		if(queries[i].lca != -1) {
			remove(queries[i].lca);
		}

	}
	for (int i = 0 ;i < q ; ++i) {
		printf("%d\n",res[i]);
	}
}

