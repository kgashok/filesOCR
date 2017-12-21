
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char fname[30];
    if (argc > 1)
        strcpy(fname, argv[1]);
    else
        strcpy(fname, "hand.txt");

    FILE* fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("File %s: Not available!\n", fname);
        return -1;
    }
    int count = 0;
    while (fgetc(fp) && !feof(fp) && ++count)
        ;
    printf("Number of bytes: %d\n", count);
    fclose(fp);
    return 0;
}