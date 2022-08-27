#pragma warning(disable:4996)

#include <stdio.h>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

enum { SIZE = 5 };

int main(void) {
    double a[SIZE] = { 1.,2.,3.,4.,5. };
    FILE* fp = fopen("test.bin", "wb"); 
    fwrite(a, sizeof * a, SIZE, fp); 
    fclose(fp);

    double b[SIZE];
    fp = fopen("test.bin", "rb");
    size_t ret_code = fread(b, sizeof * b, SIZE, fp); 

    if (ret_code == SIZE) {
        puts("Array read successfully, contents: ");
        for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
        putchar('\n');
    } else { 
        if (feof(fp)) {
            printf("Error reading test.bin: unexpected end of file\n");
        } else if (ferror(fp)) {
            perror("Error reading test.bin");
        }
    }

    fclose(fp);

    _getch();
    return 0;
}