#pragma once
#ifndef READ_TEXT_H
#define READ_TEXT_H

#include <unistd.h>

//!---------------------------------------------------------------------
//! Reads text from file into buffer
//!
//! @param [in] buffer - buffer what will be filled with text
//!
//! @param [in] filename - filename of file what needed to be read
//!
//! @return Number of successfully read bytes
//!---------------------------------------------------------------------
size_t read_text(char** buffer, const char* filename);

//!---------------------------------------------------------------------
//! Writes text from buffer into file
//!
//! @param [in] buffer - buffer what will be written to file
//!
//! @param [in] filename - filename of file what needed to be written
//!---------------------------------------------------------------------
size_t write_text(char** buffer, const char* filename, size_t cnt);

//!---------------------------------------------------------------------
//! Modifies the text in order to computate number of non-null strings
//!
//! @param [in] buffer - buffer what will be readen and modified 
//!
//! @return Number of non-null strings
//!---------------------------------------------------------------------
size_t modify_text(char* const buffer, size_t* len);

//!---------------------------------------------------------------------
//! Sets strings from buffer into arr
//!
//! @param [in] arr - char of readen strings
//!
//! @param [in] buffer - buffer what will be readen
//!
//! @param [in] cnt - number of strings to be readen
//!
//! @param [in] len - number of bytes to be readen
//!
//! @return Number of non-null strings
//!---------------------------------------------------------------------
void get_sentences(char** arr, char* const buffer, size_t cnt, int len);

//!---------------------------------------------------------------------
//! Completed function what calls all that necessary to sort file
//! in straight or reversed order in dependence with comparator
//!
//! @param [in] INPUT_FILENAME - file name of file needed to be sorted
//!
//! @param [in] OUTPUT_FILENAME - file name of file needed to be written
//!
//! @param [in] comparator - comparator function, either straight
//! or reversed
//!---------------------------------------------------------------------
void complete_work_with_text(const char* INPUT_FILENAME, const char* OUTPUT_FILENAME, int (*comparator) (const void*, const void*));

#endif// READ_TEXT_H