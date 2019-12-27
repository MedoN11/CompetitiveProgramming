#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include <deque>
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
#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<numeric>
using namespace std;
typedef vector<int> vi;
vector<int> v[100001];
int arr[300001];

// Randomization, probability

// Since a majority element has to occur more than n / 2 times
// the probability of not getting the majority element if it exists if we pick a random element is 1 - ((n/2) / n) = 1 - 1/2
// if we do this 32 times, the probability is 1 - (1/2)^32 which is extremely low
int main() {
	int n, c;
	cin >> n >> c;
	int x;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		arr[i] = x;
		v[x].push_back(i);
	}
	int q, l, r;
	cin >> q;
	while (q--) {
		scanf("%d %d", &l, &r);
		--l;
		--r;
		int ans = -1;
		for (int i = 0; i < 32; ++i) {
			int e = arr[l + (rand() % (r - l + 1))];
			int cnt = (int) (upper_bound(v[e].begin(), v[e].end(), r)
					- lower_bound(v[e].begin(), v[e].end(), l));
			if ((cnt) > (r - l + 1) / 2) {
				ans = e;
				break;
			}
		}
		if (ans != -1)
			printf("yes %d\n", ans);
		else
			puts("no");
	}

}
