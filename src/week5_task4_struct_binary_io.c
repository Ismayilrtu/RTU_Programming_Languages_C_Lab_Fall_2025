/*
 * week5_task4_struct_binary_io.c
 * Author: [Ismayil Allahverdili], [231ADB126]
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Save student to binary file
void save_student_binary(const char *filename, Student s) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student saved to %s in binary format.\n", filename);
}

// Load student from binary file
Student load_student_binary(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file for reading");
        exit(1);
    }
    Student s;
    fread(&s, sizeof(Student), 1, fp);
    fclose(fp);
    return s;
}

// Get file size in bytes
long get_file_size(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) return -1;
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}

int main(void) {
    Student s1, s2;

    printf("Enter student name: ");
    scanf("%49s", s1.name);

    printf("Enter student age: ");
    scanf("%d", &s1.age);

    printf("Enter student GPA: ");
    scanf("%f", &s1.gpa);

    printf("\nSaving student in binary format...\n");
    save_student_binary("student.bin", s1);

    printf("Loading student from binary file...\n");
    s2 = load_student_binary("student.bin");

    printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);

    long size = get_file_size("student.bin");
    if (size >= 0) {
        printf("Binary file size: %ld bytes\n", size);
    } else {
        printf("Could not determine file size.\n");
    }

    return 0;
}
