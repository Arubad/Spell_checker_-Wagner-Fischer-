#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"
#include "wagner_fischer.h"

#define MAX_DISTANCE 3 // Max allowed edit distance for suggestions

ReturnType readFile(char* str1) {
    char str2[100];
    FILE *file;
    ReturnType returnObject = {.count = 0};

    file = fopen("dictionary.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: dictionary.txt not found!\n");
        return returnObject;
    }

    while (fgets(str2, sizeof(str2), file)) {
        str2[strcspn(str2, "\n")] = '\0';
        int distance = wagner_fischer(str1, str2);

        if (distance > MAX_DISTANCE) continue;

        // Insert into top 5 suggestions
        int i;
        for (i = 0; i < returnObject.count; i++) {
            if (distance < returnObject.suggestions[i].editDistance) {
                break;
            }
        }

        if (i < 5) {
            for (int j = 4; j > i; j--) {
                if (j < returnObject.count) {
                    returnObject.suggestions[j] = returnObject.suggestions[j - 1];
                }
            }

            strcpy(returnObject.suggestions[i].string, str2);
            returnObject.suggestions[i].editDistance = distance;
            if (returnObject.count < 5) returnObject.count++;
        }
    }

    fclose(file);
    return returnObject;
}
