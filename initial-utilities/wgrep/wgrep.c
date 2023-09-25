#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    FILE *stream;
    char *buffer = NULL;
    size_t buffer_size = 32;

    if(argc <= 1) {
        printf("wgrep: searchterm [file ...]\n");
        return (1);
    }

    char *search_term = argv[1];
    char *target_file = argv[2];

    if(target_file) {
        stream = fopen(target_file, "r");
    } else {
        stream = stdin;
    }

    if(stream == NULL) {
        printf("wgrep: cannot open file\n");
        return (1);
    }

    while (getline(&buffer, &buffer_size, stream) != -1) {
        if(strstr(buffer, search_term)) {
            printf("%s", buffer);
        }
    }

    fclose(stream);
    free(buffer);
    return (0);

}