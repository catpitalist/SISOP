#if !defined(TOKEN_H)
#define TOKEN_H 1

#include <stdlib.h>
static const char label = 1;
static const char command = 2;
static const char immediate_op = 3;
static const char direct_op = 4;
struct token{
    char* content;
    char type;
};
// token functions
void token_init(struct token *t, char* content, char type);
void dealloc_token(struct token *t);
#endif

