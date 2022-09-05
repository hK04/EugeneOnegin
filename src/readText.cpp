/// \file

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

#include "../include/test.hpp"

char* FILENAME = "text/Onegin.txt";

size_t read_text(char** buffer){
    FILE* file;
    struct stat buff;
    
    file = fopen(FILENAME, "r");
    ASSERT(file != NULL);

    fstat(fileno(file), &buff);
    *buffer = (char*) calloc((buff.st_size + 1), sizeof(char));
    ASSERT(buffer != NULL);

    size_t len = fread(*buffer, sizeof(char), buff.st_size, file);
    fclose(file);

    return len;
}

size_t modify_text(char* const buffer, size_t* len){
    int delta  = 0;
    int Line   = 0;
    size_t cnt = 0;

    for (size_t i = 0; i < *len; i++){
        if (Line){
            if (*(buffer + i) == '\0' || *(buffer + i) == '\n'){
                *(buffer + i) = '\0';
                cnt++;
                Line = 0;  
            }
            *(buffer + i - delta) = *(buffer + i);
        } else {
            if (*(buffer + i) == ' ' || *(buffer + i) == '\0' || *(buffer + i) == '\n' || *(buffer + i) == '\t' || *(buffer + i) == '*'){
                delta++;
            } else {
                *(buffer + i - delta) = *(buffer + i);
                Line = 1;
            }
        }
    }

    *len -= delta;

    return cnt;
}

void set(char** arr, char* buffer, size_t cnt, int len){
    int iter = 0;
    int Line = 0;

    for (int i = 0; i < len && iter < cnt; i++){
        if (Line) {
            *(arr + iter++) = buffer + i;
            Line = 0;
        }
        if (*(buffer + i) == '\0'){
            Line = 1;
        }
    }
}