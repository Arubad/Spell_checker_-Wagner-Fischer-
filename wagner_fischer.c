#include "wagner_fischer.h"
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int wagner_fischer(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) matrix[i][0] = i;
    for (int j = 0; j <= len2; j++) matrix[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 2;
            matrix[i][j] = min(min(matrix[i - 1][j] + 1,
                                   matrix[i][j - 1] + 1),
                                   matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[len1][len2];
}
