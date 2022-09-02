#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#include "include/comparator.hpp"
#include "include/test.hpp"

int main()
{
    setlocale(LC_ALL, "C.UTF-8"); //helps to setup Russain language

    wchar_t* str1  = L"АБ";
    wchar_t* str2  = L"АА";

    wchar_t* str3  = L"АА";
    wchar_t* str4  = L"АБ";
    
    wchar_t* str5  = L"АА";
    wchar_t* str6  = L"АА";

    wchar_t* str7  = L".А";
    wchar_t* str8  = L"АА";

    wchar_t* str9  = L"АА";
    wchar_t* str10 = L".А";

    wchar_t* str11 = L".А";
    wchar_t* str12 = L".А";

    wchar_t* array1[] = {L"АА", L"АБ", L"ББ", L"!Б"};

    wchar_t* onegin_test[] = \
    {
        L"«Мой дядя самых честных правил,", 
        L"Когда не в шутку занемог,",
        L"Он уважать себя заставил",
        L"И лучше выдумать не мог.",
        L"Его пример другим наука;",
        L"Но, боже мой, какая скука",
        L"С больным сидеть и день и ночь,"
    };

    qsort_comp(array1, 0, 3);   //0 goes as integer of starting point
                                //2 goes as integer of ending point
                                //implement writing function 
                                
    qsort_comp(onegin_test, 0, 6);
    
    print_output_of_strcmp(strcmp(str1, str2), -1);
    print_output_of_strcmp(strcmp(str3, str4),  1);
    print_output_of_strcmp(strcmp(str5, str6),  0);
    print_output_of_strcmp(strcmp(str7, str8), -1);
    print_output_of_strcmp(strcmp(str9,  str10),  1);
    print_output_of_strcmp(strcmp(str11, str12),  0);

    present(array1, 4);
    present(onegin_test, 7);
}