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

size_t strlen(char* str){
    char* end_of_str = str;

    while (*end_of_str != '\0')
        end_of_str++;

    return end_of_str - str;
}

char* get_end_of_str(char* str){
    while (*str != '\0')
        str++;
    return str;
}

int straight_comparator(const void* str1, const void* str2){
    char* str_1 = (char*) str1;
    char* str_2 = (char*) str2;

    while (*str_1 != '\0' && *str_2 != '\0'){
        char lower_char1 = tolower(*str_1);
        char lower_char2 = tolower(*str_2);

        char* str_chect1 = strchr(STRAIGHT_CHECK,  (int) lower_char1);
        char* str_chect2 = strchr(STRAIGHT_CHECK,  (int) lower_char2);

        if ((str_chect1 != str_chect2 != NULL && str_chect1 - str_chect2 < 0) ||
            (str_chect1 == NULL && str_chect2 != NULL))
            return -1;
        if ((str_chect1 != str_chect2 != NULL && str_chect1 - str_chect2 > 0) ||
            (str_chect1 != NULL && str_chect2 == NULL))
            return  1;

        str_1++;
        str_2++;
    }
    return 0;
}

int reversed_comparator(const void* str1, const void* str2){
    char* end_of_str1 = get_end_of_str((char*) str1);
    char* end_of_str2 = get_end_of_str((char*) str2);

    size_t len1 = strlen((char*) str1);
    size_t len2 = strlen((char*) str2);

    while (len1 != 0 && len2 != 0){
        char lower_char1 = tolower(*end_of_str1);
        char lower_char2 = tolower(*end_of_str2);

        char* str_chect1 = strchr(STRAIGHT_CHECK,  (int) lower_char1);
        char* str_chect2 = strchr(STRAIGHT_CHECK,  (int) lower_char2);

        if ((str_chect1 != str_chect2 != NULL && str_chect1 - str_chect2 < 0) ||
            (str_chect1 == NULL && str_chect2 != NULL))
            return  1;
        if ((str_chect1 != str_chect2 != NULL && str_chect1 - str_chect2 > 0) ||
            (str_chect1 != NULL && str_chect2 == NULL))
            return -1;

        len1--;
        len2--;
        end_of_str1--;
        end_of_str2--;
    }
    return 0;
}

void swap_comp(char* array[], int id_first, int id_second){
    char* temporary;
    temporary = array[id_first];
    array[id_first] = array[id_second];
    array[id_second] = temporary;
}

void qsort_comparator(char* array[], int (*comparator)(const void*, const void*), int left, int right){
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

/*
void qsort( void *ptr, size_t count, size_t size,
            int (*comp)(const void *, const void *) );
ptr	    -	pointer to the array to sort
count	-	number of elements in the array
size	-	size of each element in the array in bytes
comp	-	comparison function which returns ​a negative integer value 
            if the first argument is less than the second, a positive 
            integer value if the first argument is greater than 
            the second and zero if the arguments are equivalent.
*/

void present(char** const array, int n){
    setlocale(LC_ALL, "rus");
    char** const arr = array;
    
    for (int i = 0; i < n; i++){
        while (*arr[i] != '\0')
        {
            printf("%c", *arr[i]);
            arr[i]++;
        }
        printf("\n");
    }
}