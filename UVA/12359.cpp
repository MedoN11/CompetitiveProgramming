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
#define ll  long long
#define EPS (1e-8);
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) ((int)(x.size()))
#define REP(i,v) for(int i = 0 ; i < sz(v) ; ++i)
#define neg(x) memset(x,-1,sizeof(x));
#define read(file) freopen (file,"r",stdin)
#define write(file) freopen (file,"w",stdout)
#define endl "\n"
#define all(v) ((v.begin()),v.end())
#define M(x,y) make_pair(x,y)
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;
int n,m;
int suf[27];
int tot = 0;
long long ans = 0;
struct Trie
{
	Trie *childs[26];
	int id;
	Trie()
	{

		memset(childs,0,sizeof(childs));
		id = 0;
	}
	void insert(string &s,int idx)
	{
		if(idx == s.size()) return;

		int ch = s[idx] - 'a';

		if(!this->childs[ch])
		{
			this->childs[ch] = new Trie();
		}
		this->childs[ch]->id = ch;
		this->childs[ch]->insert(s,idx + 1);
	}
	bool isLeaf()
	{
		for(int i = 0 ; i < 26 ; ++i)
		{
			if(this->childs[i]) return false;
		}
		return true;
	}
	void dfs(int dep)
	{
		if(dep == 0)
		{
			for(int i = 0 ; i < 26 ; ++i)
				if(this->childs[i])
					childs[i]->dfs(dep + 1);
		}
		else
		{
			if(dep > 1)
			{
				suf[id]++;
			}
			tot++;
			for(int i = 0 ; i < 26 ; ++i)
				if(this->childs[i])
					childs[i]->dfs(dep + 1);

		}
	}
	void dfs2(int dep)
	{
		if(dep == 0)
		{
			for(int i = 0 ; i < 26 ; ++i)
				if(this->childs[i])
					childs[i]->dfs2(dep + 1);
		}
		else
		{
			if(dep != 1)
				ans -= suf[id];
			ans += tot;
			for(int i = 0 ; i < 26 ; ++i)
				if(this->childs[i])
					childs[i]->dfs2(dep + 1);

		}
	}

};
Trie *prefix = NULL;
Trie *suffix = NULL;
int main()
{
	fast

	while(cin >> n >> m, (n + m))
	{
		prefix = new Trie();
		suffix = new Trie();
		memset(suf,0,sizeof(suf));
		tot = 0;
		string str;
		for(int i = 0 ; i < n ; ++i)
		{
			cin >> str;
			prefix->insert(str,0);
		}
		for(int j = 0 ; j < m ; ++j)
		{
			cin >> str;
			reverse(str.begin(),str.end());
			suffix->insert(str,0);
		}
		ans = 0;
		suffix->dfs(0);
		prefix->dfs2(0);
		cout << ans << endl;
	}
}

