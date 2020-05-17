#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

namespace hash {

std::vector<long long> GetPow(int max_len, int base, int mod) {
	std::vector<long long> pow;
	pow.resize(max_len + 1);
	pow[0] = 1;
	for (int i = 1; i < max_len; ++i) {
		pow[i] = ((pow[i - 1]) * base) % mod;
	}
	return pow;
}

// Assumes strings are lower case ('a' to 'z').
// collison probability n^2 / 2m where n is length of strings, and m is mod.
class Hasher {

public:
	explicit Hasher(const std::string& s, const std::vector<long long>& pow,
			int max_len, int base, long long mod) :
			s_(s), pow_(pow), max_len_(max_len), base_(base), mod_(mod) {
		StartRollingHash();

	}
	// returns hash of substring [i,j]
	long long GetSubstringHash(int i, int j) {

		int len = j - i + 1;
		long long val = h_[j] - (i > 0 ? (h_[i - 1] * pow_[len]) % mod_ : 0);
		if (val < mod_) {
			val += mod_;
			val %= mod_;
		}
		return val;
	}

private:
	const std::string s_;
	const std::vector<long long> pow_;
	const int max_len_;
	const int base_;
	const long long mod_;
	std::vector<long long> h_;

	void StartRollingHash() {
		int size = (int) (s_.size());
		h_.resize(max_len_ + 1);
		// add 1 so a & aa has different hashes.
		h_[0] = (s_[0] - 'a' + 1);
		for (int i = 1; i < size; ++i) {
			h_[i] = h_[i - 1] * base_ + (s_[i] - 'a' + 1);
			h_[i] %= mod_;
		}
	}

};

}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int base = 31, mod = 1000 * 1000 * 1000 + 7, max_len = 5 * 10000 + 5;
	std::string main;
	std::string pat;
	std::cin >> main >> pat;

	int pat_size = pat.size();
	int main_size = main.size();

	long long pat_hash = 0;
	for (int i = 0; i < pat.size(); ++i) {
		pat_hash *= base;
		pat_hash += (pat[i] - 'a' + 1);
	}

	hash::Hasher tool(main, hash::GetPow(max_len, base, mod), max_len, base,
			mod);
	for (int i = 0; i + pat_size - 1 < main_size; ++i) {
		if (tool.GetSubstringHash(i, i + pat_size - 1) == pat_hash)
			printf("%d ", i);
	}

}
