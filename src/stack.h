#ifndef STACK_H
#define STACK_H

#include<iostream>

namespace CSCIBetz
{
	class FullStack{};
	class EmptyStack{};

	template<typename T>
	class Stack
	{
    	public:
        	Stack();
        	~Stack()

        	void push(T &) throw(FullStack);
        	T & pop() throw(EmptyStack);

        	bool isEmpty();
        	bool isFull();
        	int size();

	};
}


#endif
