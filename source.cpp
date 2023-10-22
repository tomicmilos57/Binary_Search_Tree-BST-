#include <iostream>
#include "bintree.hpp"
#include "stack.hpp"
using namespace std;



int main(){
    cout <<"Application start..."<< endl;

    int arr[] = {15, 43, 2, 35, 33, 8, 6, 13, 17, 3, 16, 21};
    int n = 12;
    Node<int>* root = Node<int>::create_tree(arr, n);
    Node<int>::tree_print(root);
    cout <<"Project ended succesfully..."<< endl;
    return 0;
}
