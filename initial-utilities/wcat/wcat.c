#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2000

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        return (0);
    }

    char buf[MAX];

    for(int i = 1; i < argc; i++) {

        FILE *fp = fopen(argv[i], "r");
        
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            return (1);
        }

        while(fgets(buf, MAX, fp) != NULL) {
            printf("%s", buf);
        }

        if(i < argc) {
            fclose(fp);
        }
    }
    return 0;
}