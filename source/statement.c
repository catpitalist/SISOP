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
	printf("]");
}