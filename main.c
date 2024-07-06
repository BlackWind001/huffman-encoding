#include "main.h"

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
            countArr[current].n++;
            countArr[current].c = current;
        }
    } while(!(readPtr < DEFAULT_BUFFER_SIZE));

    // Sort character occurrences
    sort(countArr, COUNT_ARRAY_SIZE);

    for (int i = 0; i < COUNT_ARRAY_SIZE; i++) {
        printf("%c : %ld\n", countArr[i].c, countArr[i].n);
    }


    fclose(fptr);
    free(buffer);

    return 0;
}

void exitIfNull (void *ptr) {
    if (ptr == NULL) {
        printf("NULL pointer encountered. Exiting");
        exit(ERROR_NULL_POINTER);
    }
}

void sort (COUNT_ARRAY_TYPE* arr, int length) {
    exitIfNull(arr);

    COUNT_ARRAY_TYPE curr, prev;

    for (int i = 0; i < length; i++) {
        for (int j = 1; j < length - i; j++) {
            prev = arr[j - 1];
            curr = arr[j];

            if (curr.n < prev.n) {
                arr[j - 1] = curr;
                arr[j] = prev;
            }
        }
    }
}
