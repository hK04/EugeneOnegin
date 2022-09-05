/// \file

#include <math.h>
#include <stdio.h>
#include <locale.h>

#include "../include/headers.hpp"

char tolower(char character){
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
        if (character == UPPER_ALPHABET[i])
            return LOWER_ALPHABET[i];
    return character;
}

char* strchr(char* str, int character){
    while (*str != '\0'){
        if (*str == (char) character)
            return str;
        str++;
    }
    return NULL;
}

int straight_comparator(char* str1, char* str2){
    while (*str1 != '\0' && *str2 != '\0')
    {
        char lower_char1 = tolower(*str1);
        char lower_char2 = tolower(*str2);

        char* str_chect1  = strchr(STRAIGHT_CHECK,  (int) lower_char1);
        char* str_chect2  = strchr(STRAIGHT_CHECK,  (int) lower_char2);

        if (str_chect1 != str_chect2 != NULL && str_chect1 - str_chect2 < 0)
            return -1;
        if (str_chect1 != str_chect2 != NULL && str_chect1 - str_chect2 > 0)
            return 1;
        if (str_chect1 == NULL && str_chect2 != NULL)
            return -1; 
        if (str_chect1 != NULL && str_chect2 == NULL)
            return 1; 
        str1++;
        str2++;
    }
    return 0;
}

int reversed_comparator(char* str1, char* str2){
    while (*str1 != '\0' && *str2 != '\0')
    {
        char lower_char1 = tolower(*str1);
        char lower_char2 = tolower(*str2);

        char* str_chect1 = strchr(STRAIGHT_CHECK,  (int) lower_char1);
        char* str_chect2 = strchr(STRAIGHT_CHECK,  (int) lower_char2);

        if (str_chect1 != str_chect2 != NULL && str_chect1 - str_chect2 < 0)
            return 1;
        if (str_chect1 != str_chect2 != NULL && str_chect1 - str_chect2 > 0)
            return -1;
        if (str_chect1 == NULL && str_chect2 != NULL)
            return 1; 
        if (str_chect1 != NULL && str_chect2 == NULL)
            return -1; 
        str1++;
        str2++;
    }
    return 0;
}

void swap_comp(char* array[], int id_first, int id_second){
    char* temporary;
    temporary = array[id_first];
    array[id_first] = array[id_second];
    array[id_second] = temporary;
}

void qsort_comparator(char* array[], int (*comparator)(char* str1, char* str2), int left, int right){
    int i, last;
    if (left >= right)
        return;
    swap_comp(array, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++) 
        if (comparator(array[i], array[left]) < 0)
            swap_comp(array, ++last, i);
    swap_comp(array, left, last); 
    qsort_comparator(array, comparator, left, last - 1);
    qsort_comparator(array, comparator, last + 1, right);
}

void present(char* array[], int n){
    setlocale(LC_ALL, "rus");
    
    for (int i = 0; i < n; i++)
    {
        while (*array[i] != '\0')
        {
            printf("%c", *array[i]);
            array[i]++;
        }
        printf("\n");
    }
}