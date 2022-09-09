#include <stdio.h>
#include <stdlib.h>

#include "../include/sortComparator.hpp"
#include "../include/test.hpp"

void run_tests(){  
    char* str1  = "АБ";
    char* str2  = "АА";

    char* str3  = "АА";
    char* str4  = "АБ";
    
    char* str5  = "АА";
    char* str6  = "АА";

    char* str7  = ".А";
    char* str8  = "АА";

    char* str9  = "АА";
    char* str10 = ".А";

    char* str11 = ".А";
    char* str12 = ".А";

    char* str13 = ".А";
    char* str14 = "АА";

    char* array1[] = {"АА", "АБ", "ББ", "!Б"};
    char* array2[] = {"АА", "АБ", "ББ", "!Б"};
    char* array3[] = {"ААA", "АБА", "АББ", "БББ", "БАА", "БАБ"};

    char* onegin_test_1[] = \
    {
        "«Мой дядя самых честных правил,", 
        "Когда не в шутку занемог,",
        "Он уважать себя заставил",
        "И лучше выдумать не мог.",
        "Его пример другим наука;",
        "Но, боже мой, какая скука",
        "С больным сидеть и день и ночь,"
    };
    

    char* onegin_test_2[] = \
    {
        "«Мой дядя самых честных правил,", 
        "Когда не в шутку занемог,",
        "Он уважать себя заставил",
        "И лучше выдумать не мог.",
        "Его пример другим наука;",
        "Но, боже мой, какая скука",
        "С больным сидеть и день и ночь,"
    };

    print_output_of_comparator(straight_comparator(str1, str2), -1);
    print_output_of_comparator(straight_comparator(str3, str4),  1);
    print_output_of_comparator(straight_comparator(str5, str6),  0);
    print_output_of_comparator(straight_comparator(str7, str8), -1);
    print_output_of_comparator(straight_comparator(str9,  str10),  1);
    print_output_of_comparator(straight_comparator(str11, str12),  0);

    print_output_of_comparator(reversed_comparator(str1, str2), 1);
    print_output_of_comparator(reversed_comparator(str3, str4),-1);
    print_output_of_comparator(reversed_comparator(str5, str6), 0);
    print_output_of_comparator(reversed_comparator(str7, str8), 1);
    print_output_of_comparator(reversed_comparator(str9,  str10), -1);
    print_output_of_comparator(reversed_comparator(str11, str12),  0);
    print_output_of_comparator(straight_comparator(str13, str14),  1);

    printf("\nStraight Order: \n");
    qsort_comparator(array1, straight_comparator, 0, 3);   
                                //0 goes as integer of starting point
                                //2 goes as integer of ending point
                                //implement writing function 
    present(array1, 4);

    printf("\nReversed Order: \n");
    qsort_comparator(array2, reversed_comparator, 0, 3); 
    present(array2, 4);

    printf("\nReversed Order: \n");
    qsort_comparator(array3, reversed_comparator, 0, 6);
    present(array3, 6);

    printf("\nReversed Order: \n");
    qsort_comparator(onegin_test_1, straight_comparator, 0, 6);
    present(onegin_test_1, 7);

    printf("\nReversed Order: \n");
    qsort_comparator(onegin_test_2, reversed_comparator, 0, 6);
    present(onegin_test_2, 7);
}