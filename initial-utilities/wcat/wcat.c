#include <stdio.h>
#include <string.h>
#define MAX 100

int main(int argc, char *argv[]) {
    
    if(argc < 2) {
        printf("Choose file\n");
        return (1);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("cannot open file\n");
        return (1);
    }

    char buf[MAX];
    fgets(buf, MAX, fp);
    printf("string: %s", buf);

    return 0;
}
