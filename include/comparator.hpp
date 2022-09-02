//!-------------------------------------------------------------------
//! Turns UPPER Russian letter to lowercase
//!
//! @param [in] character - character needed to be turned in lowercase
//!
//! @return lowercase character
//!-------------------------------------------------------------------
wchar_t tolower(wchar_t character);

//!---------------------------------------------------------
//! Return first entrance of character in str
//!
//! @param [in] str - str where strchr seeks character
//! @param [in] character - character needed to be found
//!
//! @return pointer to character if it exist, NULL otherwise
//!---------------------------------------------------------
wchar_t* strchr(wchar_t* str, int character);

//!----------------------------------------------------------------------------------
//! Returns comparison of str1 and str2 by rule in STRAIGHT_CHECK
//!
//! @param [in] str1 - str1 to be compared
//! @param [in] str2 - str2 to be compared
//!
//! @return 1 if str1[i] > str2[i], -1 if str1[i] < str2[i], 0 then str1[i] = str2[i]
//!----------------------------------------------------------------------------------
int straight_comparator(wchar_t* str1, wchar_t* str2);

//!----------------------------------------------------------------------------------
//! Returns comparison of str1 and str2 by rule in REVERSED_CHECK
//!
//! @param [in] str1 - str1 to be compared
//! @param [in] str2 - str2 to be compared
//!
//! @return -1 if str1[i] > str2[i], 1 if str1[i] < str2[i], 0 then str1[i] = str2[i]
//!----------------------------------------------------------------------------------
int reversed_comparator(wchar_t* str1, wchar_t* str2);

//!-----------------------------------------------
//! Swaps the array[id_first] and array[id_second]
//!
//! @param [in] array - array of string
//!
//! @param [in] id_first - id of first element
//! @param [in] id_second - id of second element
//!-----------------------------------------------
void swap_comp(wchar_t* array[], int id_first, int id_second);

//!-----------------------------------------------------------------------------------
//! Sorts the array of wchar_t strings in different order in dependece with comparator
//!
//! @param [in] array - array of string
//! @param [in] comparator - comparator (gives equaltiy of strings)
//! @param [in] left - id of first element in array
//! @param [in] right - id of last element in array
//!-----------------------------------------------------------------------------------
void qsort_comparator(wchar_t* array[], int (*comparator)(wchar_t* str1, wchar_t* str2), int left, int right);

//!------------------------------------------------
//! Prints output in bash
//!
//! @param [in] array - array of string
//!
//! @param [in] n - number of strings to be printed
//!------------------------------------------------
void present(wchar_t* array[], int n);
