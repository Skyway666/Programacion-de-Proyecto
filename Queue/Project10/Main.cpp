#include "Queue.h"

int main()
{
	Queue<int> intqueue(10);

	intqueue.enqueue(7);
	intqueue.enqueue(3);
	intqueue.enqueue(10);
	intqueue.dequeue();
	cout<<intqueue.size()<< endl;
	intqueue.print();
	intqueue.dequeue();
	intqueue.dequeue();
	intqueue.enqueue(7);
	intqueue.enqueue(3);
	intqueue.enqueue(10);
	intqueue.enqueue(7);
	intqueue.enqueue(3);
	intqueue.enqueue(10);
	intqueue.print();
	if (intqueue.empty())
	{
		cout << "THE QUEUE IS EMTY BECAUSE THE SIZE IS " <<intqueue.size()<< endl;
	}
	return 0;
}