#ifndef TREE_TRAVERSAL
#define TREE_TRAVERSAL
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node* parent;
    struct node* left;
    struct node* right;
} node;

// should I typedef binary_tree to just be a node?
typedef struct {
    node* root;
} binary_tree;


typedef struct new_node{
    node* data;
    struct new_node *next;
} new_node;

typedef struct {
    new_node* head;
    new_node* tail;
    int elems;
} linked_list;

typedef new_node* linked_list_iterator;

typedef linked_list stack;


binary_tree* create_tree(int val); 

void destroy_tree(binary_tree* tree); 

void add_left_child(node* tree, int val); 

void add_right_child(node* tree, int val); 

int inorder_traverse(binary_tree* tree, int arr[], int size);

int postorder_traverse(binary_tree* tree, int arr[], int size);

bool equal_trees(binary_tree* tr1, binary_tree* tr2); 

void mirror_tree(binary_tree* tree);

void print_tree(binary_tree* tree); 

int tree_depth(binary_tree* tree); 

linked_list* create_list(); 

new_node* make_node(node* val); 

int get_size(linked_list* list); 

void add_to_head(linked_list* list, node* val); 

node* rest(linked_list* list); 

void free_list(linked_list* list); 

stack* create_stack();

void free_stack(stack* stack);

int stack_size(stack* stack);

void push(stack* stack, node* val);

node* pop(stack* stack); 

int iter_tree_depth(binary_tree* tree); 


// linked list full of nodes, with pointer to next node



// contract: binary tree will have children and parent. will be a collection of
// nodes, will not be sorted and not be balanced.
// will be able to search for parents, and children
// create tree, add children, destroy tree
// should I make function for accessing children? (should not changee regardless 
// of implementation)
// if adding children, must take a node
// could have a function that creates a node


#endif