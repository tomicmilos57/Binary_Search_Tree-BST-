#include "bintree.hpp"
#include "stack.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

//Constructor
template <typename info>
Node<info>::Node(info var, Node *father, Node *left, Node *right, int height, int myheight)
{
		this->father = father;
		this->left_son = left;
		this->right_son = right;
		this->var = var;
    	this->height = height;
		this-> myheight = myheight;
}

template <typename info> 
Node<info> *Node<info>::get_father()
{
	return this->father;
}

template <typename info> 
Node<info> *Node<info>::get_left_child()
{
	return this->left_son;
}

template <typename info> 
Node<info> *Node<info>::get_right_child()
{
	return this->right_son;
}

template <typename info> 
info Node<info>::get_info()
{
	return this->var;
}

template <typename info> 
bool Node<info>::is_nullptr()
{
	return this == nullptr;
}


template <typename info> 
bool Node<info>::is_right_child()
{
    if(!this->father->is_nullptr())
	    return this->father->right_son == this;
    return 0;
}

template <typename info> 
bool Node<info>::is_left_child()
{
    if(!this->father->is_nullptr())
	    return this->father->left_son == this;
    return 0;
}

//Swaps two nodes by rearranging all the pointers (not just switching values)
template <typename info> 
void Node<info>::swap_two_nodes(Node *x, Node *y)
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
	} else if(x->is_right_child()){
		x->father->right_son = y;
	}

	if (y->is_left_child()) {
		y->father->left_son = x;
	} else if(y->is_right_child()){
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

// Preorder is implemented for printing purpuses
template <typename info> 
void Node<info>::tree_print(Node *root)
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

template <typename info> 
void Node<info>::balance_print(Node *root)
{
	Stack<Node *> stack;
	stack.push(root);
	while (!stack.empty()) {
		root = stack.pop();
		while (root != NULL) {
			print_balance(root);
			if (root->get_right_child() != NULL) {
				stack.push(root->get_right_child());
			}
			root = root->get_left_child();
		}
	}
}
//Adds element onto the tree and keeps BST order
template <typename info> 
void Node<info>::BST_append_elem(Node *elem)
{
	Node *root = this;
    int height = 0;
	while (1) {
        height++;
		if (root->get_info() > elem->get_info()) {
			if (root->get_left_child() == nullptr) {
                elem->myheight = height;
                elem->height = height;
                root->set_left_child(elem);
	            for (Node *i = elem; i != nullptr; i = i->get_father()){
                    if(i->height < height) i->height = height;
                }
				break;
			} else {
				root = root->get_left_child();
			}
		} else {
			if (root->get_right_child() == nullptr) {
                elem->myheight = height;
                elem->height = height;
                root->set_right_child(elem);
	            for (Node *i = elem; i != nullptr; i = i->get_father()){
                    if(i->height < height) i->height = height;
                }
				break;
			} else {
				root = root->get_right_child();
			}
		}
	}
    //return root_tree;
}
template<typename info>
Node<info>* Node<info>::BST_search_by_value(Node* root, info value){
	while (root != nullptr) {
		if (root->get_info() > value){ 
			root = root->get_left_child();
		} else if(root->get_info() < value){
			root = root->get_right_child();
		}else{
            return root;
        }
    }
    return nullptr;
}

template<typename info>
void Node<info>::delete_tree(Node* root){
    
	Stack<Node *> stack;
	for (Node *i = root; i != nullptr; stack.push(i), i = i->get_left_child());
	while (!stack.empty()) {
		Node *node = stack.pop();
		for (Node *i = node->get_right_child();
                i != nullptr;stack.push(i), i = i->get_left_child());
        delete node;
    }
}


template<typename info>
info* Node<info>::diff(Node* elem1, Node* elem2){
    info *array = new info[100];
    int i = 0;
    
	Stack<Node *> stack;
	for (Node *i = elem2; i != nullptr; stack.push(i), i = i->get_left_child());
	while (!stack.empty()) {
		Node *node = stack.pop();
		if(Node<info>::BST_search_by_value(elem1, node->get_info()) == nullptr){
            array[i++] = node->get_info();
        }
	    for (Node *i = node->get_right_child(); i != nullptr;stack.push(i), i = i->get_left_child());
    }
    return array;
}
template<typename info>
void Node<info>::calc_height(){
	
    if(!this->left_son->is_nullptr() && !this->right_son->is_nullptr()){
        this->height = (this->left_son->height > this->right_son->height)? this->left_son->height : this->right_son->height;
    }else if(this->left_son->is_nullptr() && this->right_son->is_nullptr()){
        this->height = this->myheight;
    }else if(this->left_son->is_nullptr()){
        this->height = this->right_son->height;
    }else if(this->right_son->is_nullptr()){
        this->height = this->left_son->height;
    }

}
template<typename info>
Node<info>* Node<info>::left_rotation(){
    Node* x = this;
    Node* y = this->right_son;
    Node* temp = y->left_son;
    y->left_son = x;
    x->right_son = temp;
    if(temp != nullptr)temp->father = x;

    if(x->is_left_child())x->father->left_son = y;
    if(x->is_right_child())x->father->right_son = y;
    
    if(!y->right_son->is_nullptr())y->right_son->myheight = y->myheight;
    int xmyheight = x->myheight;
    x->myheight = y->myheight;
    y->myheight = xmyheight;

	Node *xfather = x->father;
	x->father = y;
	y->father = xfather;
    
	x->calc_height();
	if(!y->right_son->is_nullptr())y->right_son->calc_height();
	y->calc_height();

	for (Node *i = y->father; i != nullptr; i = i->father){
        i->calc_height();
    }
    return y;
}
template<typename info>
Node<info>* Node<info>::right_rotation(){
    Node* x = this;
    Node* y = this->left_son;
    Node* temp = y->right_son;
    y->right_son = x;
    x->left_son = temp;
    if(temp != nullptr)temp->father = x;

    if(x->is_left_child())x->father->left_son = y;
    if(x->is_right_child())x->father->right_son = y;

    if(!y->left_son->is_nullptr())y->left_son->myheight = y->myheight;
    int xmyheight = x->myheight;
    x->myheight = y->myheight;
    y->myheight = xmyheight;
    //swap fathers
	Node *xfather = x->father;
	x->father = y;
	y->father = xfather;

	x->calc_height();
	if(!y->left_son->is_nullptr())y->left_son->calc_height();
	y->calc_height();

	for (Node *i = y->father; i != nullptr; i = i->father){
        i->calc_height();
    }
    return y;
}
template<typename info>
int Node<info>::balance(){
    if(!this->left_son->is_nullptr() && !this->right_son->is_nullptr()){
        return this->left_son->height - this->right_son->height;
    }else if(this->left_son->is_nullptr() && this->right_son->is_nullptr()){
        return 0;
    }else if(this->left_son->is_nullptr()){
        return this->myheight - this->right_son->height;
    }else if(this->right_son->is_nullptr()){
        //cout << endl << "levi sin visina " << left_son->height << ", moja visina " << this->myheight << endl;
        return this->left_son->height - this->myheight;
    }

    return 0;
    //return (!this->left_son->is_nullptr()? this->left_son->height : 0 )- 
    //    (!this->right_son->is_nullptr()? this->right_son->height : 0);
}
template<typename info>
Node<info>* Node<info>::AVL_append_elem(Node* root, Node* elem){
    root->BST_append_elem(elem);
   
    elem = elem->father;
    while(elem != nullptr){
        if(elem->balance() >= 2){
            if(elem->left_son->balance() == 1) elem->right_rotation();
            else if(elem->left_son->balance() == -1){
                elem->left_son->left_rotation();
                elem->right_rotation();
            }else{
                cout << "Unknown case" << endl;
                exit(0);
            }
        }
        else if(elem->balance() <= -2){
            if(elem->right_son->balance() == -1)elem->left_rotation();
            else if(elem->right_son->balance() == 1){
                elem->right_son->right_rotation();
                elem->left_rotation();
            }else{
                cout << "Unknown case" << endl;
                exit(0);
            }
        }
    elem = elem->father;
    }
        
	for (; root->father != nullptr; root = root->father);
    return root;
}
template<typename info>
Node<info>* Node<info>::create_tree(info* arr, int n){
    Node<info>* root = new Node<info>(arr[0]);    
    for(int i = 1; i < n; i++){
        Node<info>* elem = new Node<info>(arr[i]);
        root = Node<info>::AVL_append_elem(root, elem);
        Node<info>::tree_print(root);
        cout << "_____________________" << endl;
        Node<info>::balance_print(root);
        cout << "_____________________" << endl;
    }
    return root;
}
//Returns 1 if tree is BST 
template <typename info> 
bool Node<info>::BST_validate(Node *root)
{
	Stack<Node *> stack;
	for (Node *i = root; i != nullptr; stack.push(i), i = i->get_left_child());
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
		for (Node *i = node->get_right_child(); i != nullptr;stack.push(i), i = i->get_left_child());
	}
	return root;
}

//Searches the tree for a node with provided value and returns that node
template <typename info>
Node<info> *Node<info>::search_by_value(Node *root, info value)
{
	Stack<Node *> stack;
	for (Node *i = root; i != nullptr;stack.push(i), i = i->get_left_child());
	while (!stack.empty()) {
		Node *tmp = stack.pop();
		if (tmp->get_info() == value)
			return tmp;
		for (Node *i = tmp->get_right_child(); i != nullptr; stack.push(i), i = i->get_left_child());
	}
	return nullptr;
}

//Returns height of the node(from the original root)
template <typename info> 
int Node<info>::get_height(Node *node)
{
	int num = 0;
	for (Node *i = node; i->get_father() != nullptr; num++, i = i->get_father());
	return num;
}

// Very expensive operation, but it is here for debugging i.e. printing purpuses
template <typename info> 
void Node<info>::print_table(Node *node)
{
	int tab = get_height(node);
    for (int i = 0; i < tab; i++) {
		cout << "   ";
	}
	cout << node->get_info() << endl;
	//cout << node->myheight << endl;
	//cout << node->balance() << endl;
}

template <typename info> 
void Node<info>::print_balance(Node *node)
{
	int tab = get_height(node);
    for (int i = 0; i < tab; i++) {
		cout << "   ";
	}
	cout << node->height << ", " << node->myheight << endl;
}
template <typename info>
void Node<info>::set_right_child(Node *node)
{
	this->right_son = add_child(this->right_son, node);
	node->father = this;
}

template <typename info>
void Node<info>::set_left_child(Node *node)
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
		exit(0); //Throw exception instead of exiting
	}
}
