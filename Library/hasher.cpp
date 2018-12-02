#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include <deque>
#include<stack>
#include<sstream>
#include <cstdlib>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include<vector>
#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<numeric>
using namespace std;
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define ll  long long
using namespace std;
// Polynomial hashing
// Collision prob n^2 / 2m
// by CRT, if hash modulo m1,m2,m3, it makes capacity m1*m2*m3
struct Hasher {
	// Assumes that all strings are lower case
	int base,m1,before,after;
	string str;
	vector<long long> powm1,prefm1;
	vector<unsigned long long> prefm2,powm2;

	void init(int base,long long m1,int before,int after) {
		this->base = base;
		this->m1 = m1;
		this->before = before;
		this->after = after;
	}

	void preprocess() {
		powm1.pb(1);
		powm2.pb(1);
		for (int i = 1 ; i < sz(str) ; ++i) {
			powm1.pb((powm1[i - 1] * base) % m1);
			powm2.pb(powm2[i - 1] * base);
		}

		prefm1.pb(str[0] - 'a');
		prefm2.pb(str[0] - 'a');

		for (int i = 1 ; i < sz(str) ; ++i) {
			prefm1.pb((prefm1[i - 1] * 1LL*base + str[i] - 'a') % m1);
			prefm2.pb(prefm2[i - 1] * 1ULL*base + str[i] - 'a');
		}

	}

	pair<long long,unsigned long long> getHash(int i,int j)  {

		if (i == 0) {
			return make_pair(prefm1[j],prefm2[j]);
		}
		int len = j - i + 1;
		return make_pair((m1 + 1LL*prefm1[j] - (prefm1[i - 1] * powm1[len]) % m1) % m1, (1ULL*prefm2[j] - (prefm2[i - 1] * powm2[len])));
	}

	void setString(string s) {
		str = s;
	}

	int gen_rand_base(const int before, const int after) {
		long long seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		std::mt19937 mt_rand(seed);
		int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
		return base % 2 == 0 ? base - 1 : base;
	}

	void setRandomBase() {
		base = gen_rand_base(before,after);
	}

	void setBase(int b) {
		base = b;
	}

	void set(long long mod) {
		m1 = mod;
	}
};
int main() {
	srand (time(NULL));
	//int n;
	//cin >> n;
	//string s = genRandString(n);
	string s; cin >> s;
	Hasher h;
	h.init(27,1000*1000*1000 + 7,30,1000);
	h.setRandomBase();
	h.setString(s);
	cout << h.base << "\n";
	h.preprocess();
	while (1) {
		int i,j; cin >> i >> j;
		cout << h.getHash(i,j).first << " " << h.getHash(i,j).second << "\n";
	}


}
