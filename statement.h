#include "token.h"
struct statement{
    struct token *label;
    struct token *command;
    struct token *op;
    //TO-DO: add command func
};
void statement_init(struct statement *st, struct token *label, struct token *command, struct token *op);
void dealloc_statement(struct statement *st);
void print_statement(struct statement *st);
struct statement_node{
	struct statement *data;
	struct statement_node *next;
}

struct statement_node* alloc_st_node(statement *data);
void dealloc_st_node(struct statement_node *st_n);

struct statement_node* build_st_list_from_file(char* filename);