/// \file

#ifndef TEXT
#define TEXT

#include <unistd.h>

//!-------------------------------------------------------------------
//! Reads text from file into buffer
//!
//! @param [in] buffer - buffer what will be filled with text
//!
//! @return Number of successfully read bytes
//!-------------------------------------------------------------------
size_t read_text(char** buffer);

//!-------------------------------------------------------------------
//! Modifies the text in order to computate number of non-null strings
//!
//! @param [in] buffer - buffer what will be readen and modified 
//!
//! @return Number of non-null strings
//!-------------------------------------------------------------------
size_t modify_text(char* const buffer, size_t* len);

//!-------------------------------------------------------------------
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
//!-------------------------------------------------------------------
void set(char** arr, char* buffer, size_t cnt, int len);

#endif// readText