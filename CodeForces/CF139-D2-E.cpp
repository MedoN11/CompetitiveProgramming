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
#include <unordered_map>
using namespace std;
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
vector<pii> mushrom;
vector<pii> tree;
const int maxn = 100005;
double l[maxn],r[maxn],s[maxn];
int n,m;
int z[maxn];
double p[maxn];
int main() {
	ios
	cout << fixed;
	cout << setprecision(6);
	cin >> n >> m;
	for(int i = 0 ; i < n ; ++i) {
		int a,h;
		cin >> a >> h;
		tree.pb(pii(a,h));
		cin >> l[i] >> r[i];
		s[i] = 100 - (l[i] + r[i]);
		s[i] /= 100.0;
		l[i] /= 100.0, r[i] /= 100.0;
	}
	for(int i = 0 ; i < maxn ; ++i) p[i] = 1.0;
	for(int j = 0 ; j < m ; ++j) {
		int a,z;
		cin >> a >> z;
		mushrom.pb(pii(a,z));
	}
	mushrom.pb(pii(1 << 30,1 << 30));
	sort(all(mushrom));

	for (int i = 0 ; i < n ; ++i) {

		// does not hit left

		double prob = s[i] + r[i];


		vector<pii>::iterator it1 = lower_bound(all(mushrom),pii(tree[i].first - tree[i].second,-1));
		vector<pii>::iterator it2 = lower_bound(all(mushrom),pii(tree[i].first,-1));
		if(prob == 0.0) {
			z[it1 - mushrom.begin()]++;
			z[it2 - mushrom.begin()]--;
		} else {
			p[it1 - mushrom.begin()] *= prob;
			p[it2 - mushrom.begin()] /= prob;
		}

		// does not hit right
		prob = s[i] + l[i];

		it1  = lower_bound(all(mushrom),pii(tree[i].first + 1,-1));
		it2 = lower_bound(all(mushrom),pii(tree[i].first + tree[i].second + 1,-1));
		if(prob == 0.0) {
			z[it1 - mushrom.begin()]++;
			z[it2 - mushrom.begin()]--;
		} else {
			p[it1 - mushrom.begin()] *= prob;
			p[it2 - mushrom.begin()] /= prob;
		}

	}
	for(int i = 1 ; i < m ; ++i) p[i] *= p[i - 1],z[i] += z[i - 1];
	double s = 0.0;
	for (int i = 0 ; i < m ; ++i) {
		//cout << "coefs " << p[i] << "\n";
		if(z[i] == 0)
		s += 1.0*p[i] * mushrom[i].second;
	}
	cout << s << "\n";


}
