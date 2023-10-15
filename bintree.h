#ifndef BinaryTree_H
#define BinaryTree_H
/******************************************************************************** 
TODO
Redo everything with references&
Implement functions: Predecessor(), Successor(), BST_Remove(), Append_element(no BST)...
TODO
********************************************************************************/
#include "stack.h"
#include<iostream>
using namespace std;
template<typename info>
class Node{
    info var;
    Node *father;
    Node *left_son;
    Node *right_son;

    Node* add_child(Node* pointer_to_son, Node* node){
        if(pointer_to_son == nullptr){
            return node;
        }else{
            cout<<"Child allready exists" << endl << "Exiting the program..." << endl;
            exit(0);
        }
    }
    static int get_height(Node* node){ //For some reason, cannot define function inside other function
        int num = 0;
        for (Node* i = node; i->get_father() != nullptr; num++, i = i->get_father());
        return num;
    }
    static void print_table(Node* node){//Very expensive operation, but it is here for debugging i.e. printing purpuses
        int tab = get_height(node);
        //cout << tab << endl;
        for (int i = 0; i < tab; i++)
        {
            cout<< "   ";
        }
        cout<< node->get_info()<< endl;
    }
    void set_right_child(Node* node){this->right_son = add_child(this->right_son, node);node->father = this;}
    void set_left_child(Node* node){this->left_son = add_child(this->left_son,node);node->father = this;}


    public:
    Node(info var = 0, Node* otac = nullptr, Node* levi = nullptr, Node* desni = nullptr){
        this->father = otac;
        this->left_son = levi;
        this->right_son = desni;
        this->var = var;
    }
    Node* get_father(){return this->father;}
    Node* get_left_child(){return this->left_son;}
    Node* get_right_child(){return this->right_son;}
    info get_info(){return this->var;}
    bool is_nullptr(){ 
        return this == nullptr;
    }
    bool is_right_child(){//can be done without father pointer by providing 2 nodes as parameters
        return this->father->right_son == this;
    }
    bool is_left_child(){
        return this->father->left_son == this;
    }
    static void swap_two_nodes(Node* x, Node* y){
        //Reconnecting children pointers and fathers pointers
        if(!x->left_son->is_nullptr())x->left_son->father = y; //use set_right_child?
        if(!x->right_son->is_nullptr())x->right_son->father = y;
        if(!y->left_son->is_nullptr())y->left_son->father = x; 
        if(!y->right_son->is_nullptr())y->right_son->father = x; 
        if(x->is_left_child()){
            x->father->left_son = y;
        }else{ 
            x->father->right_son = y;
        }
        
        if(y->is_left_child()){
            y->father->left_son = x;
        }else{ 
            y->father->right_son = x;
        }
        //Saving x's children
        Node* xrightchild = x->right_son;
        Node* xleftchild = x->left_son;
        //Swaping x and y
        x->right_son = y->right_son;
        x->left_son = y->left_son;
        y->right_son = xrightchild;
        y->left_son = xleftchild;
        //Reconecting pointers to fathers
        Node* xfather = x->father;
        x->father = y->father;
        y->father = xfather;
    }  
    static void tree_print(Node* root){//Preorder is implemented for printing purpuse
    Stack<Node*> stack;
    stack.push(root);
    while (!stack.empty()){
        root = stack.pop();
        while(root != NULL){
            print_table(root);
            if(root->get_right_child() != NULL){
                stack.push(root->get_right_child());
            }
            root = root->get_left_child();
        }
    }
}
    void BST_append_elem(Node* elem){
        Node* root = this;
        while(1){
            if(root->get_info() > elem->get_info()){
                if(root->get_left_child() == nullptr){
                    root->set_left_child(elem);
                    break;
                }else{
                    root = root->get_left_child();
                }
            }else{
                if(root->get_right_child() == nullptr){
                    root->set_right_child(elem);
                    break;
                }else{
                    root = root->get_right_child();
                }
            }
        }
    }
    static bool BST_validate(Node* root){
        Stack<Node*> stack;
        for (Node* i = root; i != nullptr; stack.push(i), i = i->get_left_child());
        while(!stack.empty()){ 
            Node* node = stack.pop();
            if(node->get_father() != nullptr){ 
                if(node->get_father()->get_left_child() == node){
                    if(!(node->get_info() < node->get_father()->get_info()))return 0;
                }else{
                    if(!(node->get_info() >= node->get_father()->get_info()))return 0;
                }
            }
            for (Node* i = node->get_right_child(); i != nullptr; stack.push(i), i = i->get_left_child());
        }
        return root;
    }  
    static Node* search_by_value(Node* root, info value){
        Stack<Node*> stack;
        for (Node* i = root; i != nullptr; stack.push(i), i = i->get_left_child());
        while(!stack.empty()){ 
            Node* tmp = stack.pop();
            if(tmp->get_info() == value)return tmp;
            for (Node* i = tmp->get_right_child(); i != nullptr; stack.push(i), i = i->get_left_child());
        }
        return nullptr;
    }
};

#endif