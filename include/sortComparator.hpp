#pragma once
//!-------------------------------------------------------------------
//! Turns UPPER Russian letter to lowercase
//!
//! @param [in] character - character needed to be turned in lowercase
//!
//! @return lowercase character
//!-------------------------------------------------------------------
char tolower(char character);

//!---------------------------------------------------------
//! Returns first entrance of character in str
//!
//! @param [in] str - str where strchr seeks character
//! @param [in] character - character needed to be found
//!
//! @return pointer to character if it exist, NULL otherwise
//!---------------------------------------------------------
char* strchr(char* str, int character);

//!---------------------------------------------------------
//! Returns length of the str
//!
//! @param [in] str - str where strlen finds len
//!
//! @return length of the string
//!---------------------------------------------------------
size_t strlen(char* str);

//!---------------------------------------------------------
//! Returns pointer to the end of str
//!
//! @param [in] str - str where we finding the end
//!
//! @return pointer to the end of str
//!---------------------------------------------------------
char* get_end_of_str(char* str);

//!----------------------------------------------------------------------------------
//! Returns comparison of str1 and str2 by rule in STRAIGHT_CHECK
//!
//! @param [in] str1 - str1 to be compared
//! @param [in] str2 - str2 to be compared
//!
//! @return 1 if str1[i] > str2[i], -1 if str1[i] < str2[i], 0 then str1[i] = str2[i]
//!----------------------------------------------------------------------------------
int straight_comparator(const void* str1, const void* str2);

//!----------------------------------------------------------------------------------
//! Returns comparison of str1 and str2 by rule in REVERSED_CHECK
//!
//! @param [in] str1 - str1 to be compared
//! @param [in] str2 - str2 to be compared
//!
//! @return -1 if str1[i] > str2[i], 1 if str1[i] < str2[i], 0 then str1[i] = str2[i]
//!----------------------------------------------------------------------------------
int reversed_comparator(const void* str1, const void* str2);

//!-----------------------------------------------
//! Swaps the array[id_first] and array[id_second]
//!
//! @param [in] array - array of string
//!
//! @param [in] id_first - id of first element
//! @param [in] id_second - id of second element
//!-----------------------------------------------
void swap_comp(char* array[], int id_first, int id_second);

//!-----------------------------------------------------------------------------------
//! Sorts the array of  char strings in different order in dependece with comparator
//!
//! @param [in] array - array of string
//! @param [in] comparator - comparator (gives equaltiy of strings)
//! @param [in] left - id of first element in array
//! @param [in] right - id of last element in array
//!-----------------------------------------------------------------------------------
void qsort_comparator(char* array[], int (*comparator) (const void*, const void*), int left, int right);

//!------------------------------------------------
//! Prints output in bash
//!
//! @param [in] array - array of string
//!
//! @param [in] n - number of strings to be printed
//!------------------------------------------------
void present(char** const array, int n);