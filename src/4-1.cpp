#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, i;
	map <string, int> mp;
	string s;
	string s1;
	getline(cin, s);
	s += " ";
	n = s.size();
	for(i = 0; i < n; i++)
	{
		if(s[i] == ' ' and s[i - 1] == ' ')
		{
			s.erase(i, 1);
			n--;
			i--;
		}
	}
	for(i = 0; i < s.size(); i++)
	{
		if(s[i] == ' ')
		{
			if(mp.find(s1) == mp.end()) mp[s1] = 1;
			else mp[s1]++;
			s1 = "";
		}
		else s1 += s[i];
	}
	map<string, int> :: iterator it;
	for(it = mp.begin(); it != mp.end(); it++)
	{
		cout << it -> first << " " << it -> second << endl;
	}
}