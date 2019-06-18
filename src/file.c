
#include "copy.h"

FILE* file_open(const char* filename, const char* mode) {
    FILE* file_handle = fopen(filename, mode);

    if (file_handle == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);

        exit(EXIT_FAILURE);
    }

    return file_handle;
}
