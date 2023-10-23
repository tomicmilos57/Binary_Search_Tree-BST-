#include <iostream>
#include "bintree.hpp"
#include "stack.hpp"
#include <vector>
using namespace std;



int main(){
    cout <<"Application start..."<< endl;
    while(1){
        cout << "\n0 - Exit \n1 - Create Tree" << endl;
        int decision;
        cin >> decision;
        if(decision == 1){
            cout << "Enter number of elements" << endl;
            int n;
            cin >> n;
            int *arr = new int[n];
            cout << "Enter elements" << endl;
            for(int i = 0; i < n; i++){
                cin >> arr[i];
            }
            cout << "AVL TREE: " << endl; 
            Node<int>* root = Node<int>::create_tree(arr, n);
            Node<int>::tree_print(root);

            while(1){
                cout << "0 - Delete Tree\n1 - Search for element\n2 - Find difference" << endl;
                int subDecision;
                cin >> subDecision;
                if(subDecision == 1){
                    cout << "Enter value for search" << endl;
                    int val;
                    cin >> val;
                    if(Node<int>::BST_search_by_value(root, val) != nullptr)cout << "Element found" << endl;
                    else cout << "Element not found" << endl;
                }
                if(subDecision == 2){
                    cout << "Enter number of elements for second tree" << endl;
                    int n;
                    cin >> n;
                    int *arr = new int[n];
                    cout << "Enter elements" << endl;
                    for(int i = 0; i < n; i++){
                        cin >> arr[i];
                    }
                    cout << "SECOND AVL TREE: " << endl; 
                    Node<int>* root2 = Node<int>::create_tree(arr, n);
                    Node<int>::tree_print(root2);
                    cout << "Difference:" << endl;
                    int *diff = Node<int>::diff(root2, root);
                    for(int i = 0; i < 100; i++){
                        if(diff[i])cout << diff[i] << " ";
                    }
                    Node<int>::delete_tree(root2);
                    cout << endl;
                }
                if(!subDecision){
                    Node<int>::delete_tree(root);
                    break;
                }
            }
        }
        if(!decision)break;
    }

    cout <<"Project ended succesfully..."<< endl;
    return 0;
}
