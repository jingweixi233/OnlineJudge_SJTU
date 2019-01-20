#include<iostream>
#include<cmath>
#include<algorithm>
int sum;
using namespace std;
bool f(int m)
{
	if (m == 1||m==0)return 0;
	else
	{
		for (int i = 2; i <= sqrt(m); i++)
		{
			if (m%i == 0)return 0;
		}
	}
	return 1;
}
void x(int m,int n)
{
	if (m == 0)sum = sum + 1;
	for (int i = n+1; i <=m; i++)
	{
		if (f(i))x(m - i, i);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		sum=0; 
		for (int p = 0; p < m; p++)
		{
			if (f(p))x(m-p, p);
		}
		cout << sum << endl;
	}
	return 0;
}
