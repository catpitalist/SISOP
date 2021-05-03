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