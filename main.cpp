#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#include "include/comp.hpp"
#include "include/test.hpp"

int main()
{
    setlocale(LC_ALL, "C.UTF-8"); //helps to setup Russain language
    wchar_t jopa = 0;

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

    print_output_of_strcmp(strcmp(str1, str2), -1);
    print_output_of_strcmp(strcmp(str3, str4),  1);
    print_output_of_strcmp(strcmp(str5, str6),  0);
    print_output_of_strcmp(strcmp(str7, str8), -1);
    print_output_of_strcmp(strcmp(str9,  str10),  1);
    print_output_of_strcmp(strcmp(str11, str12),  0);
}