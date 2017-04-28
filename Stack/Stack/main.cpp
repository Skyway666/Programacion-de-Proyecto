#include "Stack.h"

int main()
{
	Stack <int> intstack(10);

	intstack.push(69);
	intstack.push(40);
	intstack.push(99);

	intstack.print();

	intstack.pop();

	cout << intstack.top();

	intstack.pop();
	intstack.pop();

	if (intstack.empty())
	{
		cout << "No stack";
	}

	intstack.push(69);
	intstack.push(40);
	intstack.push(99);
	intstack.push(69);
	intstack.push(40);
	intstack.push(99);
	intstack.push(69);
	intstack.push(40);
	intstack.push(99);

	cout << intstack.size();
	return 0;
}