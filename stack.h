#ifndef Stack_H
#define Stack_H
template<typename T, int MAX = 1024>
class Stack{
    int top;
    T arr[MAX];
public:
    Stack(){ this->top = 0;};
    void push(T item);
    T pop();
    bool empty();
};
using namespace std;
template<typename T, int MAX>
void Stack<T,MAX>::push(T item){
    if(this->top == MAX){
        cout<< "STACK IS FULL. EXITING THE PROGRAM..." << endl;
        exit(0);
    }
    this->arr[this->top++] = item; 
}
template<typename T, int MAX> 
T Stack<T,MAX>::pop(){
    if(this->top == 0){
        cout<< "STACK IS EMPTY. EXITING THE PROGRAM..." << endl;
        exit(0);
    }
    return this->arr[--this->top];
}
template<typename T, int MAX>
bool Stack<T,MAX>::empty(){
    return !this->top;
}

#endif