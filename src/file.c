
#include "copy.h"

FILE* file_open(const char* filename, const char* mode) {
    FILE* file_handle = fopen(filename, mode);

    if (file_handle == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);

        exit(EXIT_FAILURE);
    }

    return file_handle;
}

void file_close(FILE* file_handle) {
    if (fclose(file_handle) == EOF) {
        fprintf(stderr, "Fatal error while attempting to close file\n");

        exit(EXIT_FAILURE);
    }
}
