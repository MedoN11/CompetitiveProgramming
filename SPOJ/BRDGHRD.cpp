#include <iostream>
#include <cstdio>
#include<list>
#include<sstream>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<numeric>
#include<utility>
#include<memory.h>
#include<iomanip>
#include<cmath>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int t;
int n;
vector<ii> v;
vector<int> arr;
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] > key)
        r = m;
    else
        l = m;
    }

    return r;
}

int LongestIncreasingSubsequenceLength(std::vector<int> &v) {
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1;

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length-1])

            tail[length++] = v[i];
        else

            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }

    return length;
}
int main()
{
	fast
	cin >> t;
	while(t--)
	{
		v.clear();
		cin >> n;
		arr.clear();
		for(int i = 0 ; i < n ; ++i)
		{
			int x; cin >> x;
			v.push_back(make_pair(x,-1));
		}
		for(int i = 0 ; i < n ; ++i)
			cin >> v[i].second;
		sort(v.begin(),v.end());
		REP(i,v)
		{
			arr.push_back(v[i].second);
		}
		cout << LongestIncreasingSubsequenceLength(arr) << "\n";

	}

}
