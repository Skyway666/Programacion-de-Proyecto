#include <stdio.h>
#include <iostream>

using namespace std;
template <class Type>

class Stack {
public:

	Stack(int pmaxElems)
	{
		maxElems = pmaxElems;
		idTopElem = -1;
		stackElems = (Type*)malloc(sizeof(Type)*maxElems);
	}
	~Stack() {}

	void push(const Type& item)
	{
		++idTopElem;
		stackElems[idTopElem] = item;
	}
	void pop()
	{
		--idTopElem;
	};
	Type top() const
	{
		return stackElems[idTopElem];
	}

	bool empty() const
	{
		if (idTopElem <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int size() const
	{
		return idTopElem + 1;
	}

	void print() const
	{
		if (idTopElem > -1)
		{ 
			int i = 0;
			while ( i <= idTopElem)
			{
				cout << stackElems[i]<< endl;
				i++;
		    }
		  
		}
	}

private:
	Type* stackElems;
	int maxElems;
	int idTopElem;
};


