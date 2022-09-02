#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <locale.h>

void present(wchar_t* array[], int n)
{
    setlocale(LC_ALL, "C.UTF-8");
    for (int i = 0; i < n; i++)
    {
        while (*array[i] != '\0')
        {
            printf("%lc", *array[i]);
            array[i]++;
        }
        printf("\n");
    }
}

int main(){
    setlocale(LC_ALL, "C.UTF-8"); 
    FILE* pfile;
    struct stat buff;

    pfile = fopen("Onegin.txt", "r");
    fstat (fileno (pfile), &buff);

    printf("Size of the file is: %ld\n", buff.st_size);

    void* buffer = malloc((buff.st_size + 1) * sizeof(wchar_t));

    size_t len = fread(buffer, sizeof(wchar_t), buff.st_size, pfile);
    printf("%ld\n", len);
    printf("%lc", ((wchar_t*) buffer + 1)[2]);
    free(buffer);
    fclose(pfile);
    return 0;

}

