#if !defined(UTIL_H)
#define UTIL_H 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
static const char *commands[11] = {"ADD", "SUB", "MULT", "DIV", "LOAD", "STORE", "BRANY", "BRPOS", "BRZERO", "BRNEG", "SYSCALL"};

// Utility 
bool is_label(const char* x, const size_t s);
bool is_immediate(const char* x, const size_t s);
bool is_command(const char* x, const size_t s);

// Saves the word-positions of the start/end of sections in the code
bool find_sections(char* filename, int *save_here);
#endif

