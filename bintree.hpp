#ifndef BINTREE_HPP
#define BINTREE_HPP

/********************************************************************************
TODO
Redo everything with references&
Implement functions: Predecessor(), Successor(), BST_Remove(), Append_element(no
BST)...
TODO
********************************************************************************/


#include <iostream>

template <typename info> class Node {
    public:

	// Constructor
	Node(info var = 0, Node *otac = nullptr, Node *left = nullptr,
	     Node *right = nullptr, int height = 1);

	Node *get_father();
	Node *get_left_child();
	Node *get_right_child();
	info get_info();
	bool is_nullptr();
	bool is_right_child();
	bool is_left_child();
	static void tree_print(Node *root);
    static void balance_print(Node *root);
	void BST_append_elem(Node *elem);
    static Node *BST_search_by_value(Node *root, info value);
    static void delete_tree(Node* root);
    static info* diff(Node* elem1, Node* elem2);
    static Node* AVL_append_elem(Node* root, Node *elem);
    static Node* create_tree(info* arr, int n);
    private:
	info var;
    int height;
    
	Node *father;
	Node *left_son;
	Node *right_son;
	
    
    Node* left_rotation();
    Node* right_rotation();
	int get_height();
	void update_height();
	static int get_height_from_bottom(Node *node);
	static void print_table(Node *node);
	static void print_balance(Node *node);
	void set_right_child(Node *node);
	void set_left_child(Node *node);
    int balance();
	static Node *add_child(Node *pointer_to_son, Node *node);
};

#include "bintree.cpp"

#endif
