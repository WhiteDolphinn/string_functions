#include "my_string_functions.h"
#include <assert.h>
#include <malloc.h>

void my_puts(const char *string)
{
    assert(string != 0);

    for(int i = 0; putchar(*(string + i)) != '\0'; i++)
        continue;

    putchar('\n');
}

const char* my_strchr(const char* cs, int s)
{
    assert(cs != 0);

    for(int i = 0; *(cs + i) != '\0'; i++)
        if(s == *(cs + i))
            return cs+i;

    return NULL;
}

int my_strlen(const char* string)
{
    assert(string != 0);

    int i = 0;
    while(*(string + i) != '\0')
        i++;

    return i;
}

char* my_strcpy(char* s, const char* ct)
{
    assert(s != 0 && ct != 0);
    int i = 0;
    for(i; *(ct + i) != '\0'; i++)
    {
        *(s + i) = *(ct + i);
    }
    *(s + i) = *(ct + i);
    return s;
}

char* my_strncpy(char* s, const char* ct, size_t n)
{
    assert(s != 0 && ct != 0);
    int i = 0;
    for(i; i < n && *(ct + i) != '\0'; i++)
    {
        *(s + i) = *(ct + i);
    }
    *(s + i) = '\0';

    return s;
}

char* my_strcat(char* s, const char* ct)
{
    assert(s != 0 && ct != 0);

    int i = 0;
    for(i; *(s+i) != '\0'; i++)
        continue;

    int j = 0;
    for(j; *(ct + j) != '\0'; j++)
        *(s + i + j) = *(ct + j);

    *(s + i + j) = *(ct + j);


    return s;
}

char* my_strncat(char* s, const char* ct, size_t n)
{
    assert(s != 0 && ct != 0);

    int i = 0;
    for( ; *(s+i) != '\0'; i++)
        continue;

    int j = 0;
    for( ; *(ct + j) != '\0' && j < n; j++)
        *(s + i + j) = *(ct + j);

    *(s + i + j) = '\0';


    return s;
}

char* my_fgets(char* line, int maxline, FILE* fp)
{
    int i = 0;
    for(char ch; i < maxline - 1 ; i++)
    {
        ch = getc(fp);
        if(ch == EOF)
            break;
        else
            *(line + i) = ch;
    }
    *(line + i) = '\0';
    return line;
}

char* my_strdup(const char* s)
{
    assert(s);

    int n = 10;
    char* s2 = nullptr;
    s2 = (char*)calloc(n, sizeof(char));

    if(s2 == nullptr)
    {
        free(s2);
        return nullptr;
    }

    int i = 0;
    for( ; *(s + i) != '\0'; i++)
    {
        if(i + 1 == n)
        {
            n *= 2;
            char* temp = (char*)realloc(s2, sizeof(char) * n);

            if(temp)
                s2 = temp;
            else
            {
                free(s2);
                return nullptr;
            }

        }

        *(s2 + i) = *(s + i);
    }

    *(s2 + i) = '\0';
    char* temp2 = (char*)realloc(s2, sizeof(char) * i);
    if(temp2)
        s2 = temp2;
    else
    {
        free(s2);
        return nullptr;
    }

    return s2;
}

ssize_t my_getline(char** lineptr, size_t* n, FILE* stream)
{
    *n = 10;
    if(*lineptr != 0)
        *lineptr = (char*)calloc(*n, sizeof(char));
    else
    {
        *n = -1;
        return EOF;
    }

    if(*lineptr == 0)
    {
        free(*lineptr);
        return EOF;
    }

    int i = 0;
    char ch = getc(stream);
    for( ; ch != EOF && ch != '\n'; ch = getc(stream), i++)
    {
        if(i == *n)
        {
            *n *= 2;
            char* temp = nullptr;
            temp = (char*)realloc(*lineptr, sizeof(char) * (*n));

            if(temp)
                *lineptr = temp;
            else
            {
                free(*lineptr);
                *n = -1;
                return EOF;
            }
        }
        *(*lineptr + i) = ch;

    }
    char* temp2 = nullptr;
    temp2 = (char*)realloc(*lineptr, sizeof(char) * i);

    if(temp2)
        *lineptr = temp2;
    else
        return EOF;
    *n = i;

    return *n;
}

