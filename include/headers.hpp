#pragma once
#ifndef HEADERS
#define HEADERS

//!-------------------------------------------------------------------
//! Size of Alphabet (Russain + American ;)
//!-------------------------------------------------------------------
int SIZE_OF_ALPHABET = 59;

//!-------------------------------------------------------------------
//! Alphabet with lower characters
//!-------------------------------------------------------------------
char* LOWER_ALPHABET = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяabcdefghijklmnopqrstuvwxyz";

//!-------------------------------------------------------------------
//! Alphabet with upper characters
//!-------------------------------------------------------------------
char* UPPER_ALPHABET = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯABCDEFGHIJKLMNOPQRSTUVWXYZ";

//!-------------------------------------------------------------------
//! String with priorities of straight comparator 
//!-------------------------------------------------------------------                        
char* STRAIGHT_CHECK = "0123456789zyxwvutsrqponmlkjihgfedcbaъьщшчцхфтсрпнмлкйзждгвбеиёюяэыоуа";

//!-------------------------------------------------------------------
//! String with priorities of reversed comparator 
//!-------------------------------------------------------------------     
char* REVERSED_CHECK = "ауоыэяюёиебвгджзйклмнпрстфхцчшщьъabcdefghijklmnopqrstuvwxyz9876543210"; 

#endif// headers