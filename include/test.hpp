/// \file

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

#define ASSERT(condition){                                                  \
    if (!(condition))                                                       \
        printf("Error in %s in %d\n",                                       \
            #condition, __LINE__);                                          \
}

#define print_get_help{                                                                                                                                                                     \
    printf("To sort the Onegin text in straight order use ./main --straight or ./make -s\nTo sort the Onegin text in reversed order use ./main --reversed or ./make -r");                   \
}                                               

/*
#define print_output_of_qsort_comp(x, y) \
    {for ()}
*/
