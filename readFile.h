#ifndef READFILE_H
#define READFILE_H

typedef struct {
    char string[100];
    int editDistance;
} Suggestion;

typedef struct {
    Suggestion suggestions[5];
    int count;
} ReturnType;

ReturnType readFile(char* str1);

#endif
