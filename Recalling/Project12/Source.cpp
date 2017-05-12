#include <iostream>
#include <stdio.h>
using namespace std;
void countUp(unsigned int val)
{
	if (val == 0)
	{
		cout << "Base case: 0" << endl;
	}
	else
	{
		countUp(val - 1);
		cout << val << endl;
	}
}
void countUp2Rec(unsigned int val, unsigned int maxVal)
{
	if (val == maxVal)
	{
		cout << "BASO CASO: " << val << endl;
	}
	else
	{
		cout << val << endl;
		countUp2Rec(val + 1, maxVal);
	}
}
void countUp2(unsigned int maxVal)
{
	countUp2Rec(0, maxVal);
}

int main()
{
	countUp2(7);
	return 0;
}
