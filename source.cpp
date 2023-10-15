#include<iostream>
#include "bintree.h"
#include "stack.h"
using namespace std;

int main(){
    cout <<"Application start..."<< endl;
    cout <<"Generating Example Binary Tree" << endl;
    Node<int>* root = new Node<int>(20);
    
    int indeksi[] = {10, 5, 18, 1, 6, 17, 19};
    for (int i = 0; i < 7; i++)
    {
        Node<int>* elem = new Node<int>(indeksi[i]);
        root->BST_append_elem(elem);
    }
    int indeksi2[] = {35, 14, 27, 11, 25, 22, 29};
    for (int i = 0; i < 7; i++)
    {
        Node<int>* elem = new Node<int>(indeksi2[i]);
        root->BST_append_elem(elem);
    }
    Node<int>::tree_print(root);
    cout<<"______________________" << endl;
    cout << "Validation = " << Node<int>::BST_validate(root) << endl;
    Node<int>::swap_two_nodes(Node<int>::search_by_value(root, 18), Node<int>::search_by_value(root, 1));
    Node<int>::tree_print(root);
    cout<<"______________________" << endl;
    Node<int>::swap_two_nodes(Node<int>::search_by_value(root, 29), Node<int>::search_by_value(root, 1));
    Node<int>::tree_print(root);
    cout<<"______________________" << endl;
    Node<int>::swap_two_nodes(Node<int>::search_by_value(root, 19), Node<int>::search_by_value(root, 11));
    Node<int>::tree_print(root);
    cout<<"______________________" << endl;
    cout << "Validation = " << Node<int>::BST_validate(root) << endl;
    cout <<"Project ended succesfully..."<< endl;
    return 0;
}