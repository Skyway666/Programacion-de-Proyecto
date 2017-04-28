#include <stdio.h>
#include <iostream>

using namespace std;
template<class Type>

class Queue
{
public:
	Queue(int pMaxElems)
	{
		maxElems = pMaxElems;
		idEndElem = -1;
		idFrontElem = 0;
		queueElems = new Type[maxElems];
		first = false;
	}
	~Queue()
	{
		delete[] queueElems;
	};

	void enqueue(const Type& elem)
	{
		
		++idEndElem;
		
		if (idEndElem == maxElems)
		{
			idEndElem = 0;
		}

		if (idEndElem == idFrontElem  && first == true)
		{
			--idEndElem;
			first = false;
		}

		else
		{ 
		queueElems[idEndElem] = elem;
		}
		
	}
	Type dequeue()
	{
		++idFrontElem;

		if (idFrontElem == maxElems)
		{
			idFrontElem = 0;
		}

		if (idEndElem + 1 == idFrontElem)
		{
			--idFrontElem;
			return 0;
		}
	
		return queueElems[idFrontElem];
		

	}

	bool empty() const
	{
		return idFrontElem == idEndElem;
	}

	int size() const
	{
		int counter= 0;
		for (int i = idFrontElem; i != idEndElem; i++)
		{
			if (i == maxElems)
			{
				i = 0;
			}
			counter++;
		}

		return counter;
	}

	void print()
	{

		for (int i = idFrontElem; i != idEndElem+1; i++)
		{
			if (i == maxElems)
			{
				idFrontElem = 0;
			}
			if (i != -1)
			{ 
			cout  << queueElems[i] << endl;
			}
		}
	}
	
private:
	Type* queueElems;
	int maxElems;
	int idEndElem;
	int idFrontElem;
	bool first;
	

};

