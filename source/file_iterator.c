#include "file_iterator.h"

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