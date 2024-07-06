#include <stdio.h>
#include <stdlib.h>

// Define directives
#define FILENAME "file.txt"
#define DEFAULT_BUFFER_SIZE 100
#define COUNT_ARRAY_SIZE 255

#define ERROR_NULL_POINTER 1
#define ERROR_FILE_LENGTH_CALC 2

// Custom data types
struct key_occurrence {
    char c; // character
    long n; // number of occurrences
};

// Custom type names
typedef struct key_occurrence key_occurrence;
typedef key_occurrence COUNT_ARRAY_TYPE;

void exitIfNull (void *ptr);
void sort (COUNT_ARRAY_TYPE* arr, int length);
