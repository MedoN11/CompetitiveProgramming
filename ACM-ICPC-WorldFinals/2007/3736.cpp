#include<set>
#include<map>
#include<list>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<iomanip>
#include<cmath>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include<stack>
#define ll long long
using namespace std;
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
typedef pair<int,int> ii;
int n;
map<string,vector<char> > mp;
map<string,string> get_;

void get(char a,char b,int negs,set<string> &s)
{

	string t = "";

	if(a < b)
	{

		string tmp = get_[t + a + b];

		s.insert(tmp+'+'),s.insert(tmp+"-");
	}
	else
	{
		string tmp = get_[t + b + a];
		s.insert(tmp+'+'),s.insert(tmp+"-");
	}
}

bool ok(string &test, string&dad,string&res)
{

	vector<char> u = mp[test];
	vector<char> v = mp[dad];
	;

	REP(i,u)
	{
		REP(j,v)
						{
			string s = "";
			if(u[i] < v[j]) s +=u[i], s += v[j];
			else s+= v[j], s += u[i];
			//cerr << get_[s] << " " << res << "\n";
			if(get_[s] == res)
				return 1;
						}
	}
	return 0;
}
int main()
{


	fast
	string dad,mom,son;
	mp["A"].push_back('A');
	mp["AB"].push_back('A');
	mp["AB"].push_back('B');
	mp["A"].push_back('O');
	mp["B"].push_back('B');
	mp["B"].push_back('O');
	mp["O"].push_back('O');
	get_["AA"] = "A";
	get_["AB"] = "AB";
	get_["AO"] = "A";
	get_["BB"] = "B";
	get_["BO"] = "B";
	get_["OO"] = "O";
	vector<string> keys;
	for(map<string,vector<char> >::iterator it = mp.begin() ; it != mp.end() ; it++)
		keys.push_back(it->first);


	int tc = 1;
	while(1)
	{
		cin >> dad >> mom >> son;
		if(dad == "E" && mom == "N" && son == "D")
			break;
		bool f = 0;
		if(dad == "?")
		{
			swap(dad,mom);
			f = 1;
		}

		if(son =="?")
		{
			set<string> s;
			int ones = 0;
			if(dad.at(sz(dad) - 1) == '+') ++ones;
			if(mom.at(sz(mom) - 1) == '+') ++ones;
			string a = "";
			REP(i,dad)
			if(dad[i] == '-' || dad[i] == '+') break;
			else a += dad[i];
			string b = "";
			REP(i,mom)
			if(mom[i] == '-' || mom[i] == '+') break;
			else b += mom[i];
			vector<char> u = mp[a];
			vector<char> v = mp[b];
			//cerr << ones << "\n";
			REP(i,u)
			{
				REP(j,v)
																					{
					string pos = "";
					char c1 = u[i]; char c2 = v[j];
					if(c1 > c2)
						swap(c1,c2);
					pos += c1; pos += c2;
					pos = get_[pos];
					if(ones)
					{
						s.insert(pos + '+');
						s.insert(pos + '-');
					}
					else s.insert(pos + '-');

																					}
			}
			string res = "";

			res += '{';
			int sz = sz(s);
			if(sz == 0)
				res = "IMPOSSIBLE";
			else
			{
				if(sz(s) == 1) res = *s.begin();
				else
				{
					for(set<string>::iterator it = s.begin(); it != s.end() ; it++)
					{
						sz--;
						res += (*it);
						if(sz)
							res += ',',res += ' ';

					}
					res += '}';
				}
			}
			cout << "Case " << (tc++) <<": ";
			son = res;
			cout <<dad <<" " << mom << " " << res;
			cout << "\n";
		}
		else
		{
			string a = "",b = "";
			REP(i,son)
			if(son[i] == '-' || son[i] == '+') break;
			else a += son[i];
			bool negson = son[sz(son) - 1] == '-';
			REP(i,dad)
			if(dad[i] == '-' || dad[i] == '+')
				break;
			else b += dad[i];
			int negpr = dad[sz(dad) - 1] == '-';
			vector<char> roots = mp[a];
			set<string> s;

			REP(i,keys)
			{
				if(ok(keys[i],b,a))
				{

						s.insert(keys[i]+'+');
					if(!(!negson && (negpr)))
						s.insert(keys[i]+'-');
				}
			}

			string res = "";

			res += '{';
			int sz = sz(s);
			if(sz == 0)
				res = "IMPOSSIBLE";
			else
			{
				if(sz(s) == 1) res = *s.begin();
				else
				{
					for(set<string>::iterator it = s.begin(); it != s.end() ; it++)
					{
						sz--;
						res += (*it);
						if(sz)
							res += ',',res += ' ';

					}
					res += '}';
				}
			}
			mom = res;
			if(f) swap(dad,mom);
			cout << "Case " << (tc++) <<": ";
			cout << dad <<" " << mom << " " << son;
			cout << "\n";
		}
	}



}
