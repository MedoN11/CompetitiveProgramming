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
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;;
typedef vector<int> VI;
int n;
// greedily assign each piglet
struct Piglets {
	int choose(string s);
};

int Piglets::choose(string s) {
	if(s[0] == '-')
		return 0;
	n = sz(s);
	if(s[n - 1] == '-')
		return n - 1;
	for(int i = n - 1 ; i >= 1 ; --i) {
		if(s[i] == '-' && s[i - 1] == '-')
			return i - 1;
	}
	for(int i = 0 ; i < n ; ++i) {
		if(s[i] == '-')
			return i;
	}
	return -1;

}
int main() {
	Piglets p;
	string s; cin >> s;
	cout << p.choose(s) << "\n";
}
