#include <math.h>
#include <stdio.h>

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