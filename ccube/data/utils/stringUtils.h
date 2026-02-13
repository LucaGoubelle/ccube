//@author: LucaGoubelle 🦊
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** (*split)(const char*,const char*,int*);
    void (*freeSplit)(char**,int);
    char* (*concat)(char*,char*);
} STRING_UTILS;

char** _split(const char* str, const char* delim, int* count){
    char *copy = strdup(str);          // Copier la chaîne (strtok modifie)
    char *token = strtok(copy, delim);
    char **result = NULL;
    int capacity = 0;
    *count = 0;

    while(token!=NULL){
        // Agrandir le tableau si nécessaire
        if (*count >= capacity) {
            capacity = capacity == 0 ? 4 : capacity * 2;
            result = (char**)realloc(result, capacity * sizeof(char *));
        }
        result[*count] = strdup(token);  // Copier chaque token
        (*count)++;
        token = strtok(NULL, delim);
    }
    free(copy);
    return result;
}

void _freeSplitted(char** tokens, int count){
    int i;
    for(i=0;i<count;i++)
        free(tokens[i]);
    free(tokens);
}

char* _concat(char* str1, char* str2){
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = (char*)malloc(len1+len2+1);
    memcpy(result, str1, len1);
    memcpy(result + len1, str2, len2 + 1);
    return result;
}

STRING_UTILS StringUtils(){
    STRING_UTILS su;
    su.split = _split;
    su.freeSplit = _freeSplitted;
    su.concat = _concat;
    return su;
}
