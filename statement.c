#include "statement.h"
void statement_init(struct statement *st, struct token *label, struct token *command, struct token *op){
    st->label = label;
    st->command = command;
    st->op = op;
}
void dealloc_statement(struct statement *st){
	if(st == NULL){
		return;
	}
	if(st->label != NULL){
		free(st->label);
	}
	if(st->command != NULL){
		free(st->command);
	}
	if(st->op != NULL){
		free(st->op);
	}
	free(st);
}

void print_statement(struct statement *st){
	if(st == NULL){
		printf("NULL\n");
		return;
	}
	printf("[");
	if(st->label != NULL){
		if(st->label->content == NULL){
			printf("NULL ");
		}else{
			printf("%s", st->label->content);
		}
	}
	
	if(st->command != NULL){
		if(st->command->content == NULL){
			printf("NULL ");
		}else{
			printf("%s", st->command->content);
		}
	}
	
	if(st->op != NULL){
		if(st->op->content == NULL){
			printf("NULL ");
		}else{
			printf("%s", st->op->content);
		}
	}
}

struct statement_node* alloc_st_node(statement *data){
	struct statement_node *st_n = malloc(sizeof(statement_node));
	if(st_n == NULL){
		printf("ERROR:\nNOT ENOUGH MEMORY TO CREATE STATEMENT NODE\nABORTING");
		abort();
	}
	st_n->data = data;
	st_n->next = NULL;
	return st_n;
}
void dealloc_st_node(struct statement_node *st_n){
	if(st_n == NULL){
		return;
	}
	if(stn->data != NULL){
		free(stn->data);
	}
	dealloc_st_node(st_n->next);
	free(st_n);
}

struct statement_node* build_st_list_from_file(char* filename){
	int indexes[4] = {0, 0, 0, 0};
    find_sections(filename, indexes);
	struct file_iter *iter = malloc(sizeof(struct file_iter));
    file_iter_init(iter, "test.txt", indexes[0], indexes[1]);
	struct token *t = malloc(sizeof(struct token));
	while(file_iter_next(iter, t)!=false){
		// TODO
	}
}