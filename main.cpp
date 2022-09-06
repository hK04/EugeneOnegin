#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

#include <locale.h>
#include <unistd.h>

#include "include/sortComparator.hpp"
#include "include/readText.hpp"
#include "include/test.hpp"

//!-------------------------------------------------------------------
//!   @file main.cpp
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

char* FILENAME = "text/Onegin.txt";

void handle_input(int argc, char* argv[]){
    if (argc == 1 || (
    argc == 2 && (straight_comparator(argv[1], "--help") == 0 ||
    straight_comparator(argv[1], "-h")                   == 0 ))){
        print_get_help;
        return;
    }
    if (argc == 2 && (
    straight_comparator(argv[1], "--reversed")  == 0 ||
    straight_comparator(argv[1], "-r")          == 0 ||
    straight_comparator(argv[1], "--reverse")   == 0 )){
        complete_work_with_text_reversed(FILENAME);
    } 
    else if (argc == 2 && (
    straight_comparator(argv[1], "--straight") == 0 ||
    straight_comparator(argv[1], "-s")         == 0 )){
        complete_work_with_text_straight(FILENAME);
    }
}

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "rus"); //helps to setup Russain language

#if DebugMode == 1
    run_tests();
    
#else
    handle_input(argc, argv);

#endif //DebugMode

    return 0;
}