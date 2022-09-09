#pragma once
//!-------------------------------------------------------------------
//! Define to printf colored output of test of the comparator\
//! possibly works for all function with two variables
//!-------------------------------------------------------------------
#define print_output_of_comparator(x, y){                                   \
    if(x == y)                                                              \
    {                                                                       \
        printf("\x1b[32m");                                                 \
        printf("Test Function: %s, Result: %d, Should be: %d\n", #x, x, y); \
        printf("\x1b[0m");                                                  \
    }else                                                                   \
    {                                                                       \
        printf("\x1b[31m");                                                 \
        printf("Test Function: %s, Result: %d, Should be: %d\n", #x, x, y); \
        printf("\x1b[0m");                                                  \
    }                                                                       \
}

//!-------------------------------------------------------------------
//! Macros what works as soft assert (without stoping the program)
//!-------------------------------------------------------------------
#define ASSERT(condition){                                                  \
    if (!(condition))                                                       \
        printf("Error in %s in %d\n",                                       \
            #condition, __LINE__);                                          \
}

//!-------------------------------------------------------------------
//! Define to printf help message
//!-------------------------------------------------------------------
#define print_get_help{                                                                                                                                                                     \
    printf("To sort the Onegin text in straight order use ./main --straight"\
    " or ./make -s\nTo sort the Onegin text in reversed order use ./main --"\
    "reversed or ./make -r");                                               \
}                                               

//!-------------------------------------------------------------------
//! Function to runn all tests implemented in test.cpp
//!-------------------------------------------------------------------
void run_tests();
