#ifndef BINTREE_HPP
#define BINTREE_HPP

/********************************************************************************
TODO
Redo everything with references&
Implement functions: Predecessor(), Successor(), BST_Remove(), Append_element(no
BST)...
TODO
********************************************************************************/

#include <cstdlib>
#include <iostream>

template <typename info> class Node {
    public:

	// Constructor
	Node(info var = 0, Node *otac = nullptr, Node *levi = nullptr,
	     Node *desni = nullptr, int balance = 0);

	Node *get_father();
	Node *get_left_child();
	Node *get_right_child();
	info get_info();
	bool is_nullptr();
	bool is_right_child();
	bool is_left_child();

	static void swap_two_nodes(Node *x, Node *y);
	static void tree_print(Node *root);
    static void balance_print(Node *root);
	void BST_append_elem(Node *elem);
	static bool BST_validate(Node *root);
	static Node *search_by_value(Node *root, info value);
    static Node *BST_search_by_value(Node *root, info value);
    static void delete_tree(Node* root);
    static info* diff(Node* elem1, Node* elem2);
    void AVL_append_elem(Node *elem);
    private:
	info var;
    int balance;
	Node *father;
	Node *left_son;
	Node *right_son;

	static int get_height(Node *node);
	static void print_table(Node *node);
	static void print_balance(Node *node);
	void set_right_child(Node *node);
	void set_left_child(Node *node);

	static Node *add_child(Node *pointer_to_son, Node *node);
};

#include "bintree.cpp"

#endif
