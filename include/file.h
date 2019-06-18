
#ifndef PROJECT_INCLUDES_FILE_H_
#define PROJECT_INCLUDES_FILE_H_

// TODO: file_exists(const char* filename);

FILE* file_open(const char* filename, const char* mode);

void file_close(FILE* file_handle);

#endif // PROJECT_INCLUDES_FILE_H_
