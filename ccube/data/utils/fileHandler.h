//@author: LucaGoubelle 🦊
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* (*read)(const char*);
    char* (*write)(const char*, char*);
} FILE_HANDLER;

char* _read(const char* filepath){
    FILE* f = fopen(filepath, "r");
    // size file
    fseek(f, 0, SEEK_END);
    long taille = ftell(f);
    rewind(f);
    // alloc
    char* buffer = (char*)malloc(taille + 1);
    // read
    fread(buffer, 1, taille, f);
    buffer[taille] = '\0'; // si fichier texte
    fclose(f);
    return buffer;
}

char* _write(const char* filepath, char* buffer){
    FILE* f = fopen(filepath, "w");
    fprintf(f, buffer);
    fclose(f);
    return "success !";
}

FILE_HANDLER FileHandler(){
    FILE_HANDLER fh;
    fh.read = _read;
    fh.write = _write;
    return fh;
}
