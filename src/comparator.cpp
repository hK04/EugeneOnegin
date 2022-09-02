#include <math.h>
#include <stdio.h>
#include <locale.h>

#include "../include/headers.hpp"

wchar_t tolower(wchar_t character)
{
    for (int i = 0; i < 33; i++)
        if (character == UPPER_ALPHABET[i])
            return LOWER_ALPHABET[i];
    return character;
}

wchar_t* strchr(wchar_t* str, int character)
{
    while (*str != '\0'){
        if (*str == (wchar_t) character)
            return str;
        str++;
    }
    return NULL;
}

int strcmp(wchar_t* str1, wchar_t* str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        wchar_t lower_char1 = tolower(*str1);
        wchar_t lower_char2 = tolower(*str2);

        wchar_t* first_check1  = strchr(FIRST_CHECK,  (int) lower_char1);
        //if first_check == NULL, so it's less than RUSSIAN LETTER, so it's kinda pointless \
            to make second check 
        //wchar_t* second_check1 = strchr(SECOND_CHECK, (int) lower_char1);
        wchar_t* first_check2  = strchr(FIRST_CHECK,  (int) lower_char2);
        //same 
        //wchar_t* second_check2 = strchr(SECOND_CHECK, (int) lower_char2);

        //printf("#%d %d %d %d\n", first_check1, second_check1, first_check2, second_check2);

        if (first_check1 != first_check2 != NULL && first_check1 - first_check2 < 0)
            return -1;
        if (first_check1 != first_check2 != NULL && first_check1 - first_check2 > 0)
            return 1;
        if (first_check1 == NULL && first_check2 != NULL)
            return -1; 
        if (first_check1 != NULL && first_check2 == NULL)
            return 1; 
        str1++;
        str2++;
    }
    return 0;
}

void swap_comp(wchar_t* array[], int id_first, int id_second)
{
    wchar_t* temporary;
    temporary = array[id_first];
    array[id_first] = array[id_second];
    array[id_second] = temporary;
}

void qsort_comp(wchar_t* array[], int left, int right)
{
    int i, last;
    if (left >= right)
        return;
    swap_comp(array, left, (left + right)/2);
    last = left;
    for(i = left+1; i <= right; i++) 
        if (strcmp(array[i], array[left]) < 0)
            swap_comp(array, ++last, i);
    swap_comp(array, left, last); 
    qsort_comp(array, left, last-1);
    qsort_comp(array, last+1, right);
}

void present(wchar_t* array[], int n)
{
    setlocale(LC_ALL, "C.UTF-8");
    for (int i = 0; i < n; i++)
    {
        while (*array[i] != '\0')
        {
            printf("%lc", *array[i]);
            array[i]++;
        }
        printf("\n");
    }
}