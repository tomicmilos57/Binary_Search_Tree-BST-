#ifndef STACK_HPP
#define STACK_HPP

template <typename T, int MAX = 1024> class Stack {
	int top;
	T arr[MAX];

    public:
	Stack();
	void push(T item);
	T pop();
	bool empty();
};

#include "stack.cpp"

#endif