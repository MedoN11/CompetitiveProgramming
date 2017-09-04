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
#define ll  long long
#define pb push_back
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
typedef pair<int,int> pii;
#define ios std::ios_base::sync_with_stdio(false);
using namespace std;
#define F first
#define S second

// XOR Properties + Very Easy/Standard Trie
// Editorial : http://codeforces.com/blog/entry/54179
struct Trie
{
	Trie* left;
	Trie* right;
	Trie()
	{
		this->left = 0, this->right = 0;
	}
	void insert(int ind,int num)
	{
		if(ind == -1)
			return;
		if((num & (1 << ind)) == 0)
		{
			if(!this->left) this->left = new Trie();
			this->left->insert(ind - 1,num);

		}
		else
		{
			if(!this->right) this->right = new Trie();
			this->right->insert(ind - 1,num);

		}
	}

	int getMax(int ind,int x)
	{
		if(ind == -1)
			return 0;
		int currBit = (1 << ind) & x ? 1 : 0;
		if(currBit == 0)
		{
			if(this->left)
			{
				return this->left->getMax(ind - 1,x);
			}
			else return (1 << ind) | (this->right->getMax(ind - 1,x));
		}
		else
		{
			if(this->right)
				return this->right->getMax(ind - 1,x);
			else return (1 << ind) | (this->left->getMax(ind - 1,x));
		}
	}
};
int n,q;
const int maxn = 1000*1000 + 5;
bool f[maxn + 1];
int main()
{
	scanf("%d %d",&n,&q);
	int x;
	Trie *root = new Trie();
	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%d",&x);
		f[x] = 1;
	}
	for(int i = 0 ; i <= maxn ; ++i)
	{
		if(!f[i])
		{
			root->insert(20,i);
		}
	}
	int foo = 0;
	while(q--)
	{
		scanf("%d",&x);
		foo ^= x;
		printf("%d\n",root->getMax(20,foo));
	}
}

