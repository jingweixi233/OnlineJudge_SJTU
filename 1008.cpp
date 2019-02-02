#include <iostream>
#include <cstring>

using namespace std;

const int dayofmonth[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

void getDate(int &y, int &m, int &d){
	string date;
	cin >> date;
	y = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
	m = (date[5] - '0') * 10 + (date[6] - '0');
	d = (date[8] - '0') * 10 + (date[9] - '0');
}

int getWeekDay(int y, int m, int d){
	if(m == 1 || m == 2){
		y--;
		m += 12;
	}
	int w = (d + m * 2 + (m + 1) * 3 / 5 + y + y / 4 - y / 100 + y / 400) % 7;
	w++;
	return w;
}

bool isLeap(int y){
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool isEqual(int y1, int m1, int d1, int y2, int m2, int d2)
{
	return (y1 == y2 && m1 == m2 && d1 == d2);
}

bool isDeal(int y, int m, int d)
{
	if (getWeekDay(y, m, d) == 6 || getWeekDay(y, m, d) == 7)
		return false;
	if ((m == 1 && d == 1) || (m == 5 && d >= 1 && d <= 3) || (m == 10 && d >= 1 && d <= 7))
		return false;
	return true;
}


void getNextDate(int &y, int &m, int &d)
{
	if (d < dayofmonth[isLeap(y)][m])
		d++;
	else if (m < 12)
	{
		m++;
		d = 1;
	}
	else
	{
		y++;
		m = 1;
		d = 1;
	}
}

int dealDayear(int y)
{
	int v1 = 0;
	if (isLeap(y))
		v1 = isDeal(y, 12, 30) + isDeal(y, 12, 31);
	else
		v1 = isDeal(y, 12, 31);
	int v2 = 52 * 7;
	int v3 = 11;
	int v4 = 52 * 2;
	int v5 = 0;
	if (getWeekDay(y, 1, 1) == 6 || getWeekDay(y, 1, 1) == 7)
		v5++;
	for (int i = 1; i < 4; i++)
		if (getWeekDay(y, 5, i) == 6 || getWeekDay(y, 5, i) == 7)
			v5++;
	for (int i = 1; i < 8; i++)
		if (getWeekDay(y, 10, i) == 6 || getWeekDay(y, 10, i) == 7)
			v5++;
	return v1 + v2 - v3 - v4 + v5;
}
void solve()
{
	int y1, m1, d1, y2, m2, d2;
	getDate(y1, m1, d1);
	getDate(y2, m2, d2);
	int dealday = 0;
	getNextDate(y2, m2, d2);
	if (y1 == y2)
	{
		while (!isEqual(y1, m1, d1, y2, m2, d2))
		{
			if (isDeal(y1, m1, d1))
				dealday++;
			getNextDate(y1, m1, d1);
		}
	}
	else
	{
		int flag = y1;
		while (!isEqual(y1, m1, d1, flag + 1, 1, 1))
		{
			if (isDeal(y1, m1, d1))
				dealday++;
			getNextDate(y1, m1, d1);
		}
		for (int i = y1; i < y2; i++)
			dealday += dealDayear(i);
		y1 = y2; m1 = 1; d1 = 1;
		while (!isEqual(y1, m1, d1, y2, m2, d2))
		{
			if (isDeal(y1, m1, d1))
				dealday++;
			getNextDate(y1, m1, d1);
		}
	}
	cout << dealday << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		solve();
	}
	return 0;
}
