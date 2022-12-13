// first, need node.
// then linked list,
// then stack.
// node: create/destroy, get val, change val, get next node, change next node
// ll: create ll, destroy, add to head, remove frrom head
// remove from tail, get size

#ifndef BOUNDED_STACK
#define BOUNDED_STACK
using namespace std;
#include <list>

class node
{
private:
    int val;
    node* _next;
    node* _prev;

public:
    node(int val);
    int get_val();
    void set_val(int val);
    node* next();
    node* prev();
    void set_prev(node* nd);
    void set_next(node* nd);
    ~node();
};

class linked_list {
private:
    int size;
    node* head;
    node* tail;

public:
    linked_list();
    void add_to_head(int val);
    bool is_empty();
    int rest();
    int remove_from_tail();
    ~linked_list();

};

class bounded_stack {
   private:
    linked_list container;
    int capacity;
    int size;

   public:
    bounded_stack(int limit);
    bounded_stack(const bounded_stack& st);
    bool is_empty();
    bool reached_max_size();
    void push(int val);
    int pop();
    ~bounded_stack();
};

#endif