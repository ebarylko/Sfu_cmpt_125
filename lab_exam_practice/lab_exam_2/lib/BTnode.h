#ifndef BTNODE_H
#define BTNODE_H


struct BTnode {
  int value;
  struct BTnode* left;
  struct BTnode* right;
  struct BTnode* parent;
};

typedef struct BTnode BTnode_t;

BTnode_t* create_node(int value);

void set_left_child(BTnode_t* parent, BTnode_t* left_child);

void set_right_child(BTnode_t* parent, BTnode_t* right_child);

void print_pre_order(BTnode_t* root);

void print_in_order(BTnode_t* root);

void print_post_order(BTnode_t* root);


#endif