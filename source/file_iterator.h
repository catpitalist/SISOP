#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "token.h"
#include "util.h"


struct file_iter{
    FILE *fp;
    int index;
    int end;
};
// file iterator functions
void file_iter_init(struct file_iter *iter, char* filename, int start, int end);
bool file_iter_next(struct file_iter *iter, struct token *t);
void dealloc_file_iter(struct file_iter *iter);
