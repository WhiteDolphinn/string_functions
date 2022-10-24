#ifndef MY_STRING_FUNCTIONS_H
#define MY_STRING_FUNCTIONS_H
#include <stdio.h>
#include <stddef.h>
void my_puts(const char* string);
const char* my_strchr(const char* cs, int s);
int my_strlen(const char* string);
char* my_strcpy(char* s, const char* ct);
char* my_strncpy(char* s, const char* ct, size_t n);
char* my_strcat(char* s, const char* ct);
char* my_strncat(char* s, const char* ct, size_t n);
char* my_fgets(char* line, int maxline, FILE* fp);
char* my_strdup(const char* s);
ssize_t my_getline(char** lineptr, size_t* n, FILE* stream);
#endif
