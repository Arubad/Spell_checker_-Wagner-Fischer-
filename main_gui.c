#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isalnum()
#include "readFile.h"

#define MAX_INPUT 1000

// Removes punctuation and keeps only alphanumeric characters
void remove_punctuation(char* word) {
    int i = 0, j = 0;
    while (word[i]) {
        if (isalnum((unsigned char)word[i])) {
            word[j++] = word[i];
        }
        i++;
    }
    word[j] = '\0'; // Null-terminate cleaned word
}

int main() {
    char input[MAX_INPUT];

    // Read one line from stdin
    if (!fgets(input, MAX_INPUT, stdin)) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0'; // Remove newline

    char* word = strtok(input, " ");
    while (word != NULL) {
        remove_punctuation(word); // Strip punctuation

        if (strlen(word) == 0) {
            word = strtok(NULL, " ");
            continue;
        }

        ReturnType result = readFile(word);
        if (result.count > 0 && result.suggestions[0].editDistance > 0) {
            printf("[Misspelled: %s] -> Did you mean:\n", word);
            for (int i = 0; i < result.count; i++) {
                printf("  - %s (distance: %d)\n", result.suggestions[i].string, result.suggestions[i].editDistance);
            }
        } else {
            printf("[Correct: %s]\n", word);
        }

        word = strtok(NULL, " ");
    }

    return 0;
}
