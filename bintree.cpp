#include "bintree.hpp"
#include "stack.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename info>
Node<info>::Node(info var, Node *otac, Node *levi, Node *desni)
{
	this->father = otac;
	this->left_son = levi;
	this->right_son = desni;
	this->var = var;
}

template <typename info> Node<info> *Node<info>::get_father()
{
	return this->father;
}

template <typename info> Node<info> *Node<info>::get_left_child()
{
	return this->left_son;
}

template <typename info> Node<info> *Node<info>::get_right_child()
{
	return this->right_son;
}

template <typename info> info Node<info>::get_info()
{
	return this->var;
}

template <typename info> bool Node<info>::is_nullptr()
{
	return this == nullptr;
}

// Can be done without father pointer by providing 2 nodes as parameters
template <typename info> bool Node<info>::is_right_child()
{
	return this->father->right_son == this;
}

template <typename info> bool Node<info>::is_left_child()
{
	return this->father->left_son == this;
}

template <typename info> void Node<info>::swap_two_nodes(Node *x, Node *y)
{
	// Reconnecting children pointers and fathers pointers
	if (!x->left_son->is_nullptr())
		x->left_son->father = y; // use set_right_child?
	if (!x->right_son->is_nullptr())
		x->right_son->father = y;
	if (!y->left_son->is_nullptr())
		y->left_son->father = x;
	if (!y->right_son->is_nullptr())
		y->right_son->father = x;
	if (x->is_left_child()) {
		x->father->left_son = y;
	} else {
		x->father->right_son = y;
	}

	if (y->is_left_child()) {
		y->father->left_son = x;
	} else {
		y->father->right_son = x;
	}
	// Saving x's children
	Node *xrightchild = x->right_son;
	Node *xleftchild = x->left_son;
	// Swaping x and y
	x->right_son = y->right_son;
	x->left_son = y->left_son;
	y->right_son = xrightchild;
	y->left_son = xleftchild;
	// Reconecting pointers to fathers
	Node *xfather = x->father;
	x->father = y->father;
	y->father = xfather;
}

// Preorder is implemented for printing purpuse
template <typename info> void Node<info>::tree_print(Node *root)
{
	Stack<Node *> stack;
	stack.push(root);
	while (!stack.empty()) {
		root = stack.pop();
		while (root != NULL) {
			print_table(root);
			if (root->get_right_child() != NULL) {
				stack.push(root->get_right_child());
			}
			root = root->get_left_child();
		}
	}
}

template <typename info> void Node<info>::BST_append_elem(Node *elem)
{
	Node *root = this;
	while (1) {
		if (root->get_info() > elem->get_info()) {
			if (root->get_left_child() == nullptr) {
				root->set_left_child(elem);
				break;
			} else {
				root = root->get_left_child();
			}
		} else {
			if (root->get_right_child() == nullptr) {
				root->set_right_child(elem);
				break;
			} else {
				root = root->get_right_child();
			}
		}
	}
}

template <typename info> bool Node<info>::BST_validate(Node *root)
{
	Stack<Node *> stack;
	for (Node *i = root; i != nullptr;
	     stack.push(i), i = i->get_left_child())
		;
	while (!stack.empty()) {
		Node *node = stack.pop();
		if (node->get_father() != nullptr) {
			if (node->get_father()->get_left_child() == node) {
				if (!(node->get_info() <
				      node->get_father()->get_info()))
					return 0;
			} else {
				if (!(node->get_info() >=
				      node->get_father()->get_info()))
					return 0;
			}
		}
		for (Node *i = node->get_right_child(); i != nullptr;
		     stack.push(i), i = i->get_left_child())
			;
	}
	return root;
}

template <typename info>
Node<info> *Node<info>::search_by_value(Node *root, info value)
{
	Stack<Node *> stack;
	for (Node *i = root; i != nullptr;
	     stack.push(i), i = i->get_left_child())
		;
	while (!stack.empty()) {
		Node *tmp = stack.pop();
		if (tmp->get_info() == value)
			return tmp;
		for (Node *i = tmp->get_right_child(); i != nullptr;
		     stack.push(i), i = i->get_left_child())
			;
	}
	return nullptr;
}

// For some reason, cannot define function inside other function
template <typename info> int Node<info>::get_height(Node *node)
{
	int num = 0;
	for (Node *i = node; i->get_father() != nullptr;
	     num++, i = i->get_father())
		;
	return num;
}

// Very expensive operation, but it is here for debugging i.e. printing purpuses
template <typename info> void Node<info>::print_table(Node *node)
{
	int tab = get_height(node);
	// cout << tab << endl;
	for (int i = 0; i < tab; i++) {
		cout << "   ";
	}
	cout << node->get_info() << endl;
}

template <typename info> void Node<info>::set_right_child(Node *node)
{
	this->right_son = add_child(this->right_son, node);
	node->father = this;
}

template <typename info> void Node<info>::set_left_child(Node *node)
{
	this->left_son = add_child(this->left_son, node);
	node->father = this;
}

template <typename info>
Node<info> *Node<info>::add_child(Node *pointer_to_son, Node *node)
{
	if (pointer_to_son == nullptr) {
		return node;
	} else {
		cout << "Child allready exists" << endl
		     << "Exiting the program..." << endl;
		exit(0);
	}
}
