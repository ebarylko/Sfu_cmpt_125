#include "bounded_stack.hpp"
#include <stddef.h>
using namespace std;
#include <iostream>

node::node(int val) {
    set_val(val);
    set_next(NULL);
    set_prev(NULL);

}

int node::get_val() {
    return val;
}

void node::set_val(int target) {
    val = target;
}

void node::set_next(node* nd) {
    _next = nd;
}

void node::set_prev(node* nd) {
    _prev = nd;
}

node* node::prev() {
    return _prev;
}

node* node::next() {
    return _next;
}

node::~node() {
}


linked_list::linked_list() {
head = NULL;
tail = NULL;
size = 0;
}

// copy elements over from other list
// while node is valid, I will grab the value and add to tail
linked_list::linked_list(const linked_list& lst) 
:linked_list() {
    node* nd = lst.tail;
    while (nd) {
        this->add_to_head(nd->get_val());
        nd = nd->prev();
    }
}

void linked_list::add_to_head(int val) {
    node* nd = new node(val);
    nd->set_next(this->head);
    head = nd;
    size++;

    if (size != 1) {
        head->next()->set_prev(head);
    } else {
        tail = head;
    }
}

bool linked_list::is_empty() {
    return !size;
}

int linked_list::rest() {
    if (this->is_empty())
        throw "Can't perform rest on an empty list";

    node* old_head = head;
    head = head->next();
    int val = old_head->get_val();
    delete old_head;
    size--;
    if (!size) {
        tail = NULL;
    } else {
        head->set_prev(NULL);
    }
    return val;
}

int linked_list::remove_from_tail() {
    if (this->is_empty())
        throw "Can't perform rest on an empty list";

    node* old_tail = tail;
    tail = tail->prev();
    int val = old_tail->get_val();
    delete old_tail;
    size--;
    if (!size) {
        head = NULL;
    } else {
        tail->set_next(NULL);
    }
    return val;
}

linked_list::~linked_list() {
    while (!this->is_empty())
        this->rest();
}

bounded_stack::bounded_stack(int limit) {
    capacity = limit;
}

bounded_stack::bounded_stack(const bounded_stack& st) 
   :bounded_stack(st.capacity) {     
   container = st.container;
}

bool bounded_stack::is_empty() {
    return size == 0;
}

bool bounded_stack::reached_max_size() {
    return size == capacity;
}

void bounded_stack::push(int val) {
    if (reached_max_size()) {
        container.remove_from_tail();
    }
    container.add_to_head(val);
}

int bounded_stack::pop() {
    container.rest();
}

// there is nothing to free
bounded_stack::~bounded_stack() {
}


int main() {
    bounded_stack st (5);

    return 0;
}