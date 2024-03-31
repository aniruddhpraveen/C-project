#include <stdio.h>
#define NUM_STUDENTS 5
#define NUM_TESTS 3
#define MAX_NAME_LENGTH 25

struct Student 
{
    char name[MAX_NAME_LENGTH];
    int rollnumber;
};

void displayMarks(struct Student students[NUM_STUDENTS], int marks[NUM_STUDENTS][NUM_TESTS]) 
{
    printf("\nStudent Marks:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) 
    {
        printf("Student %d - Name: %s, Roll Number: %d, Marks: ", i + 1, students[i].name, students[i].rollnumber);
        for (int j = 0; j < NUM_TESTS; j++) 
        {
            printf("%d ", marks[i][j]);
        }
        printf("\n");
    }
}

void updateMarks(int marks[NUM_STUDENTS][NUM_TESTS]) 
{
    int studentIndex, testIndex;
    printf("Enter the student number (1 to %d): ", NUM_STUDENTS);
    scanf("%d", &studentIndex);
    printf("Enter the test number (1 to %d): ", NUM_TESTS);
    scanf("%d", &testIndex);
    printf("Enter the new mark for Student %d, Test %d: ", studentIndex, testIndex);
    scanf("%d", &marks[studentIndex - 1][testIndex - 1]);
}

void addStudentMarks(int marks[NUM_STUDENTS][NUM_TESTS], struct Student students[NUM_STUDENTS], int *numStudents) 
{
    printf("Enter details for the new student:\n");
    printf("Enter name: ");
    scanf("%s", students[*numStudents].name);
    printf("Enter roll number: ");
    scanf("%d", &students[*numStudents].rollnumber);
    printf("Enter marks for the new student (out of 100):\n");
    for (int j = 0; j < NUM_TESTS; j++) 
    {
        printf("Enter marks for Test %d: ", j + 1);
        scanf("%d", &marks[*numStudents][j]);
    }
    (*numStudents)++;
}

int main() 
{
    struct Student students[NUM_STUDENTS];
    int marks[NUM_STUDENTS][NUM_TESTS];
    int numStudents = 0;

    char choice;
    do 
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Add student marks\n");
        printf("2. Update marks\n");
        printf("3. Display marks\n");
        printf("4. Exit\n\n");
        printf("Enter your choice (1-4): ");
        scanf("%c", &choice);

        switch (choice) 
        {
            case '1':
                addStudentMarks(marks, students, &numStudents);
                printf("The student details have successfully been added!\n\n");
                break;
            case '2':
                updateMarks(marks);
                printf("The student's marks have successfully been updated!\n\n");
                break;
            case '3':
                displayMarks(students, marks);
                break;
            case '4':
                printf("Exiting program.\n\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n\n");
                break;
        }
    } 
    while (choice != '4');
    return 0;
}