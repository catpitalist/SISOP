#include "token.h"

//------------------------------------------
//----------------------
//---------------------- TOKEN FUNCTIONS ---
//----------------------
//------------------------------------------

void token_init(struct token *t, char* content, char type){
    t->content = content;
    t->type = type;
}
void dealloc_token(struct token *t){
    if(t == NULL){
        return;
    }
    if(t->content != NULL){
        free(t->content);
    }
    free(t);
}
//--------------------
