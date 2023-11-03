#include <bits/stdc++.h>
using namespace std;

int main(){
	int i;
	double square_sum = 0, sum = 0, n = 0;
	double x;
	cin >> x;
	while(x != 0)
	{
		square_sum += x * x;
		sum += x;
		n++;
		cin >> x;
	}
	double ans = sqrt((square_sum - (sum * sum) / n) / (n - 1));
	cout.precision(12);
	cout << ans;
}