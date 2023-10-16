#include "stack.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T, int MAX> Stack<T, MAX>::Stack()
{
	this->top = 0;
};

template <typename T, int MAX> void Stack<T, MAX>::push(T item)
{
	if (this->top == MAX) {
		cout << "STACK IS FULL. EXITING THE PROGRAM..." << endl;
		exit(0);
	}
	this->arr[this->top++] = item;
}
template <typename T, int MAX> T Stack<T, MAX>::pop()
{
	if (this->top == 0) {
		cout << "STACK IS EMPTY. EXITING THE PROGRAM..." << endl;
		exit(0);
	}
	return this->arr[--this->top];
}
template <typename T, int MAX> bool Stack<T, MAX>::empty()
{
	return !this->top;
}