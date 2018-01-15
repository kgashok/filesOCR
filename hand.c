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
    char c;
    while ((c = fgetc(fp)) && !feof(fp)) {
        printf("%c(%d) \t", c, ++count);
    }
    printf("\nNumber of bytes: %d\n", count);
    
    fclose(fp);
    return 0;
}