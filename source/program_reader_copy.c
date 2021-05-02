//----------------------
// MOVE TO HEADER
//----------------------
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include file_iterator.h

const char label = 1;
const char command = 2;
const char immediate_op = 3;
const char direct_op = 4;
const char *commands[11] = {"ADD", "SUB", "MULT", "DIV", "LOAD", "STORE", "BRANY", "BRPOS", "BRZERO", "BRNEG", "SYSCALL"};

struct token{
    char* content;
    char type;
};
// token functions
void token_init(struct token *t, char* content, char type);
void dealloc_token(struct token *t);


struct file_iter{
    FILE *fp;
    int index;
    int end;
};
// file iterator functions
void file_iter_init(struct file_iter *iter, char* filename, int start, int end);
bool file_iter_next(struct file_iter *iter, struct token *t);
void dealloc_file_iter(struct file_iter *iter);

struct statement{
    struct token *label;
    struct token *command;
    struct token *op;
    //TO-DO: add command func
};
void statement_init(struct statement *st, struct token *label, struct token *command, struct token *op);


// Utility 
bool is_label(const char* x, const size_t s);
bool is_immediate(const char* x, const size_t s);
bool is_command(const char* x, const size_t s);


// Saves the word-positions of the start/end of sections in the code
bool find_sections(char* filename, int *save_here);



//------------------------------------------
//----------------------
//---------------------- IMPLEMENTATIONS ---
//---------------------- 
//------------------------------------------


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

//-----------------------------------------------------
//----------------------
//---------------------- FILE ITERATOR FUNCTIONS    ---
//---------------------- 
//-----------------------------------------------------
void file_iter_init(struct file_iter *iter, char* filename, int start, int end){
    iter->fp = fopen(filename, "r");
    if(iter->fp == NULL){
        printf("Could not open file");
        return;
    }
    iter->end = end;
    int i;
    for(i = 0; i <= start; i++){
        char buffer[258];
        if (fscanf(iter->fp, "%s", buffer) != 1){
            fclose(iter->fp);
            iter->fp = NULL;
            printf("File format invalid");
            iter->index = -1;
            return;
        }
    }
    iter->index = i;
}

bool file_iter_next(struct file_iter *iter, struct token *t){
    if(iter->index >= iter->end || iter->index < 0){
        return false;
    }
    char buffer[258];
    if (fscanf(iter->fp, "%s", buffer) != 1){
        fclose(iter->fp);
        iter->fp = NULL;
        printf("File format invalid");
        iter->index = -1;
        return false;
    }
    char *s = malloc(strlen(buffer)*sizeof(char));
    strcpy(s, buffer);
    char type = 0;
    if(is_label(s, strlen(s))){
        type = label;
    }
    else if(is_command(s, strlen(s))){
        type = command;
    }
    else if(is_immediate(s, strlen(s))){
        type = immediate_op;
    }else{
        type = direct_op;
    }
    token_init(t, s, type);
    iter->index++;
    return true;
}

void dealloc_file_iter(struct file_iter *iter){
    if(iter == NULL){
        return;
    }
    if(iter->fp != NULL){
        fclose(iter->fp);
    }
    free(iter);
}
//--------------------

//------- STATEMENT FUNCTIONS
void statement_init(struct statement *st, struct token *label, struct token *command, struct token *op){
    st->label = label;
    st->command = command;
    st->op = op;
}

//------- UTILITY FUNCTIONS

bool is_label(const char* x, const size_t s){
    return x[s-1] == ':';
}

bool is_immediate(const char* x, const size_t s){
    return x[0] == '#';
}

bool is_command(const char* x, const size_t s){
    bool flag = false;
    for(int i = 0; i < 11; i++){
        if(strcmp(x, commands[i])==0){
            flag = true;
            break;
        }
    }
    return flag;
}
bool find_sections(char* filename, int *save_here)
{
    const char code_start[] = ".code";
    const char code_end[] = ".endcode";
    const char data_start[] = ".data";
    const char data_end[] = ".enddata";

    FILE *fp = fopen(filename, "r");
    if(fp==NULL){
        printf("Could not open the file %s\n", filename);
        return false;
    }
    // The biggest string we are searching for is 8 chars long
    // So this buffer is all we need. [9 chars + null makes sure
    // that we didn't just find a suffix].
    char buffer[10];
    memset(buffer, 0, 10);
    int count = 0;
    while(fscanf(fp, "%s", buffer) == 1){
        if(strcmp(code_start, buffer) == 0){
            save_here[0] = count;
        }
        if(strcmp(code_end, buffer) == 0){
            save_here[1] = count;
        }
        if(strcmp(data_start, buffer) == 0){
            save_here[2] = count;
        }
        if(strcmp(data_end, buffer) == 0){
            save_here[3] = count;
        }
        count++;
    }
    fclose(fp);
    return true;
}
//----------------------
int main(){
    //char s[] = "ADD";
    //char s2[] = "BAD";
    //printf("s:%s\n", is_command(s, strlen(s))? "true":"false");
    //printf("s2:%s\n", is_command(s2, strlen(s2))? "true":"false");
    int indexes[4] = {0, 0, 0, 0};
    find_sections("test.txt", indexes);
    printf("%d %d %d %d\n", indexes[0], indexes[1], indexes[2], indexes[3]);
    struct file_iter *iter = malloc(sizeof(struct file_iter));
    file_iter_init(iter, "test.txt", indexes[0], indexes[1]);
    struct token *t = malloc(sizeof(struct token));
    printf("Next test:\n");
    while(file_iter_next(iter, t)){
        printf("%s - %d\n", t->content, t->type);
    }
    dealloc_token(t);
    dealloc_file_iter(iter);
    return 0;
}