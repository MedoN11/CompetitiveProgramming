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
using namespace std;

// Factorial number system + DS
// Check editorial for more details.

const int maxn = 200005;
int order_p[maxn], order_q[maxn];
int res[maxn];
int bit[maxn];
int n;
void add(int ind, int x) {
  ind++;
  while (ind < maxn) {
    bit[ind] += x;
    ind += ind & -ind;
  }
}

int get(int ind) {
  ind++;
  int s = 0;
  while (ind > 0) {
    s += bit[ind];
    ind -= ind & -ind;
  }
  return s;
}

int getKth(int k) {
  int lo = 0, hi = n - 1;
  int ans = -1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (get(mid) < k) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  return ans + 1;
}

int main() {
  cin >> n;
  int x;
  for (int i = 0; i < n; ++i) add(i, 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    order_p[i] = get(x - 1);
    add(x, -1);
  }
  memset(bit, 0, sizeof(bit));
  for (int i = 0; i < n; ++i) add(i, 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    order_q[i] = get(x - 1);
    add(x, -1);
  }
  memset(bit, 0, sizeof(bit));
  for (int i = 0; i < n; ++i) add(i, 1);
  int carry = 0;
  vector<int> v;
  for (int i = n - 1; i >= 0; --i) {
    int f = order_p[i] + order_q[i] + carry;
    carry = f / (n - i);
    f %= (n - i);
    v.push_back(f);
  }
  for (int i = v.size() - 1; i >= 0; --i) {
    int f = getKth(v[i] + 1);
    printf("%d ", f);
    add(f, -1);
  }
}
