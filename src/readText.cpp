#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

#include "../include/test.hpp"
#include "../include/sortComparator.hpp"

size_t read_text(char** buffer, const char* filename){
    FILE* file;
    struct stat buff;
    
    file = fopen(filename, "r");
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

void get_sentences(char** arr, char* const buffer, size_t cnt, int len){
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

void complete_work_with_text_straight(const char* INPUT_FILENAME){
    char* buffer = NULL;
    size_t len = read_text(&buffer, INPUT_FILENAME);
    char* start_of_buffer = buffer;

    size_t cnt = modify_text(buffer, &len);

    char** arr = (char**) calloc(cnt, sizeof(char**));
    get_sentences(arr, buffer, cnt, len);

    qsort_comparator(arr, straight_comparator, 0, cnt - 1);
    present(arr, cnt);
        
    free(buffer);
}

void complete_work_with_text_reversed(const char* INPUT_FILENAME){
    char* buffer = NULL;
    size_t len = read_text(&buffer, INPUT_FILENAME);
    char* start_of_buffer = buffer;

    size_t cnt = modify_text(buffer, &len);

    char** arr = (char**) calloc(cnt, sizeof(char**));
    get_sentences(arr, buffer, cnt, len);

    qsort_comparator(arr, reversed_comparator, 0, cnt - 1);
    present(arr, cnt);
        
    free(buffer);
}