#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int childNum, i;
	cin >> childNum;
	int *child = new int[childNum];
	for (i = 0;i < childNum; i++)
	{
		cin >> child[i];
	}
	sort(child, child + childNum);
	vector<int> vect(childNum);
	vect[0] = 0;
	vect[1] = child[1];
	for (i = 2; i < childNum; i++)
	{
		vect[i] = min(vect[i-1] + child[0] + child[i],vect[i-2] + child[0] + child[i]+2 * child[1]);
	}
	cout << vect[childNum - 1];
 
	return 0;
}