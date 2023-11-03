#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, i, j;
	cin >> n;
	string s;
	getline(cin, s);
	vector< vector <int> > tabl(n, vector <int> (n));
	for(i = 0; i < n; i++)
	{
		getline(cin, s);
		for(j = 0; j < s.size(); j++)
		{
			int x;
			x = s[j];
			if(x > 47 and x < 58)
			{
				x -= 48;
				if(x != 0) tabl[i][x - 1] = 1; 
			}
		}
	}
	stack <int> st;
	for(i = 0; i < n; i++) tabl[i][i] = 1;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(tabl[i][j] == 1 and i != j) st.push(j);
		}
		while(st.size() != 0)
		{
			int x;
			x = st.top();
			st.pop();
			for(j = 0; j < n; j++)
			{
				if(tabl[x][j] == 1)
				{
					if(tabl[i][j] == 0)
					{
						tabl[i][j] = 1;
						st.push(j);
					}
				}
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout << tabl[i][j] << " ";
		}
		cout << endl;
	}
}