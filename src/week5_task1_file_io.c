/*
 * week5_task1_file_io.c
 * Author: [Ismayil Allahverdili], [231ADB126]
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 3
#define BUFFER_SIZE 256

int main(void) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char lines[MAX_LINES][BUFFER_SIZE];

    printf("Enter %d lines to write into data.txt:\n", MAX_LINES);
    for (int i = 0; i < MAX_LINES; i++) {
        printf("Line %d: ", i + 1);
        if (fgets(lines[i], BUFFER_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }
        // Remove newline at end if present
        size_t len = strlen(lines[i]);
        if (len > 0 && lines[i][len - 1] == '\n') {
            lines[i][len - 1] = '\0';
        }
    }

    printf("\nWriting lines to data.txt...\n");
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    for (int i = 0; i < MAX_LINES; i++) {
        fprintf(fp, "%s\n", lines[i]);
    }
    fclose(fp);

    printf("\nReading contents from data.txt:\n");
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    int line_number = 1;
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        printf("Line %d: %s", line_number++, buffer);
    }

    fclose(fp);
    return 0;
}
