#include "main.h"

void exitIfNull (void *ptr) {
    if (ptr == NULL) {
        exit(ERROR_NULL_POINTER);
    }
}

int main () {
    FILE *fptr;
    size_t readPtr;
    char *buffer;
    fptr = fopen(FILENAME, "r");
    buffer = (char *)malloc(DEFAULT_BUFFER_SIZE *sizeof(char));
    COUNT_ARRAY_TYPE *countArr = (COUNT_ARRAY_TYPE *)calloc(COUNT_ARRAY_SIZE, sizeof(COUNT_ARRAY_TYPE));

    exitIfNull(fptr);

    // Count character occurrences
    do {
        readPtr = fread(buffer, sizeof(char), DEFAULT_BUFFER_SIZE, fptr);
        for (int i = 0; i < readPtr; i++) {
            const char current = *(buffer + i);
            countArr[current]++;
        }
    } while(!(readPtr < DEFAULT_BUFFER_SIZE));

    for (int i = 0; i < COUNT_ARRAY_SIZE; i++) {
        printf("%c : %ld\n", i, countArr[i]);
    }

    // Sort character occurrences


    fclose(fptr);
    free(buffer);

    return 0;
}