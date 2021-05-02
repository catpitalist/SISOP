//----------------------
// MOVE TO HEADER
//----------------------
//#include <string.h>
//#include <stdio.h>
//#include <stdbool.h>
#include <stdlib.h>
#include "file_iterator.h"

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