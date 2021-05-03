#include <stdbool.h>
struct node{
    void *data;
    node *next;
};

void init_node(struct node *n, void *data);
void dealloc_node(struct node *n);

struct list{
    node *head;
    int size;
};

void init_list(struct list *ls, void *data);
void dealloc_list(struct list *ls);
void add_to_end(struct list *ls, void *data);
void add_to_beginning(struct list *ls, void *data);

struct list_iterator{
    struct list *ls;
    struct node *next;
};

void init_list_iterator(struct list_iterator *ls_i, struct list *ls);
void dealloc_list_iterator(struct list_iterator *ls_i);
bool list_iterator_next(struct list_iterator);