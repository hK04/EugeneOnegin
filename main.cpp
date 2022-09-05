#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
/// \file

#include <locale.h>
#include <unistd.h>

#include "include/sortComparator.hpp"
#include "include/readText.hpp"
#include "include/test.hpp"

//!-------------------------------------------------------------------
//!  @file main.cpp
//!   @mainpage Eugene Oneging Project Documentation
//!   @section desc Description:
//!   This program was written as second task at MIPT
//!
//!   @section download Downloading link:
//!   <a href="https://github.com/hK04/EugeneOnegin">->Github</a> 
//!   @author Anoshin. M aka hK04
//!   @brief Program meant to sort all sentence in EugeneOnegin poem at straight and reversed orders 
//!  
//!-------------------------------------------------------------------

void handle_input(int argc, char* argv[]){
    if (argc == 1 || (argc == 2 && (straight_comparator(argv[1], "--help") == 0 || straight_comparator(argv[1], "-h") == 0))){
        print_get_help;
    }
    else if (argc == 2 && (straight_comparator(argv[1], "--reversed")  == 0 || straight_comparator(argv[1], "-r") == 0 || straight_comparator(argv[1], "--reverse") == 0)){
        printf("Reversed");
        char* buffer = NULL;
        size_t len = read_text(&buffer);
        char* start_of_buffer = buffer;

        size_t cnt = modify_text(buffer, &len);

        char** arr = (char**) calloc(cnt, sizeof(char**));
        set(arr, buffer, cnt, len);

        qsort_comparator(arr, reversed_comparator, 0, cnt - 1);
        present(arr, cnt);
        
        free(buffer);

    } 
    else if (argc == 2 && (straight_comparator(argv[1], "--straight") == 0 || straight_comparator(argv[1], "-s") == 0)){
        printf("Straight");
        char* buffer = NULL;
        size_t len = read_text(&buffer);
        char* start_of_buffer = buffer;

        size_t cnt = modify_text(buffer, &len);

        char** arr = (char**) calloc(cnt, sizeof(char**));
        set(arr, buffer, cnt, len);

        qsort_comparator(arr, straight_comparator, 0, cnt - 1);
        present(arr, cnt);
        
        free(buffer);
    }
}

int main(int argc, char* argv[]){ //to add handle of input
    setlocale(LC_ALL, "rus"); //helps to setup Russain language

#if DebugMode == 1

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

    char* array1[] = {"АА", "АБ", "ББ", "!Б"};
    char* array2[] = {"АА", "АБ", "ББ", "!Б"};

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
    qsort_comparator(onegin_test_1, straight_comparator, 0, 6);
    present(onegin_test_1, 7);

    printf("\nReversed Order: \n");
    qsort_comparator(onegin_test_2, reversed_comparator, 0, 6);
    present(onegin_test_2, 7);

#else
    handle_input(argc, argv);

#endif //DebugMode

    return 0;
}

//wchar_t translates normal char in wrong way!!!!