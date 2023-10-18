#include<iostream>
#include "bintree.hpp"
#include "stack.hpp"
using namespace std;
/************************************
This is just test file for BST class
************************************/
int main(){
    cout <<"Application start..."<< endl;
    cout <<"Generating Example Binary Tree" << endl;
    Node<int>* root = new Node<int>(20);
    
    int indeksi[] = {10, 5, 18, 1, 6, 17, 19, 14, 11};
    for (int i = 0; i < 9; i++)
    {
        Node<int>* elem = new Node<int>(indeksi[i]);
        root->AVL_append_elem(elem);
    }
    Node<int>::tree_print(root);
    Node<int>::balance_print(root);
    int indeksi2[] = {35, 27, 25, 22, 29};
    for (int i = 0; i < 5; i++)
    {
        Node<int>* elem = new Node<int>(indeksi2[i]);
        root->AVL_append_elem(elem);
        cout << "Adding elem_________________" << endl;
        Node<int>::tree_print(root);
        Node<int>::balance_print(root);
    }

    Node<int>::tree_print(root);
    Node<int>::balance_print(root);
    Node<int>* test = Node<int>::BST_search_by_value(root, 10);
//    Node<int>::balance_print(root);
//    Node<int>::tree_print(test);
    int *arr;
    arr = Node<int>::diff(test, root);
    for(int i = 0; i < 10; i++){
        if(arr[i] != 0)
            cout<<arr[i]<<' ';
    }
    cout << endl;
/*    Node<int>::tree_print(root);
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
    Node<int>* a = Node<int>::search_by_value(root, 1);
    cout << "Swaping root: " << endl;
    Node<int>::swap_two_nodes(Node<int>::search_by_value(root, 20), Node<int>::search_by_value(root, 1));
    Node<int>::tree_print(a);
    cout<<"______________________" << endl;
    cout << "Validation = " << Node<int>::BST_validate(root) << endl;*/
    cout <<"Project ended succesfully..."<< endl;
    return 0;
}
