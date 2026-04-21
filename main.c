/*
Name: Epuwat Elly Benon 
Registration Number: 25/U/BIE/18668/PE
*/

#include <stdio.h>

int main(void) {
    /* Declare variables here */
     int i;

    int sem1Scores[8], sem2Scores[8];
    int sem1GP[8], sem2GP[8];
    char sem1Grade[8], sem2Grade[8];

    float totalPointsSem1 = 0, totalCreditsSem1 = 0;
    float totalPointsSem2 = 0, totalCreditsSem2 = 0;

    float gpa1, gpa2, cgpa;
    char *classification;

    char *sem1Courses[8] = {
        "1.TEMB 1101", "2.TEMB 1102", "3.TEMB 1103", "4.TEMB 1104",
        "5.TEMB 1105", "6.TEMB 1106",
        "7.TEMB 1107", "8.TEMB 1108"
    };

    char *sem2Courses[8] = {
        "9.TEMB 1201", "10.TEMB 1202", "11.TEMB 1203", "12.TEMB 1204",
        "13.TEMB 1205", "14.TEMB 1206",
        "15.TEMB 1207", "16.TEMB 1208"
    };

    int credits[8] = {4, 3, 3, 3, 3, 3, 3, 3};

    /* Read 16 scores */
     printf("Enter Semester I scores:\n");
    for (i = 0; i < 8; i++) {
        printf("%s: ", sem1Courses[i]);
        scanf("%d", &sem1Scores[i]);
    }

    printf("\nEnter Semester II scores:\n");
    for (i = 0; i < 8; i++) {
        printf("%s: ", sem2Courses[i]);
        scanf("%d", &sem2Scores[i]);
    }

    /* Validate input */
     for (i = 0; i < 8; i++) {
        if (sem1Scores[i] < 0 || sem1Scores[i] > 100 ||
            sem2Scores[i] < 0 || sem2Scores[i] > 100) {
            printf("Invalid input detected! Scores must be between 0 and 100.\n");
            return 1;
        }
     }

    /* Determine grades and grade points */
    for (i = 0; i < 8; i++) {

        // Semester I
        if (sem1Scores[i] >= 80) {
            sem1Grade[i] = 'A'; sem1GP[i] = 5;
        } else if (sem1Scores[i] >= 70) {
            sem1Grade[i] = 'B'; sem1GP[i] = 4;
        } else if (sem1Scores[i] >= 60) {
            sem1Grade[i] = 'C'; sem1GP[i] = 3;
        } else if (sem1Scores[i] >= 50) {
            sem1Grade[i] = 'D'; sem1GP[i] = 2;
        } else {
            sem1Grade[i] = 'F'; sem1GP[i] = 0;
        }

        // Semester II
        if (sem2Scores[i] >= 80) {
            sem2Grade[i] = 'A'; sem2GP[i] = 5;
        } else if (sem2Scores[i] >= 70) {
            sem2Grade[i] = 'B'; sem2GP[i] = 4;
        } else if (sem2Scores[i] >= 60) {
            sem2Grade[i] = 'C'; sem2GP[i] = 3;
        } else if (sem2Scores[i] >= 50) {
            sem2Grade[i] = 'D'; sem2GP[i] = 2;
        } else {
            sem2Grade[i] = 'F'; sem2GP[i] = 0;
        }
}

    /* Compute Semester I GPA */
    for (i = 0; i < 8; i++) {
        totalPointsSem1 += sem1GP[i] * credits[i];
        totalCreditsSem1 += credits[i];
    }
    gpa1 = totalPointsSem1 / totalCreditsSem1;

    /* Compute Semester II GPA */
    for (i = 0; i < 8; i++) {
        totalPointsSem2 += sem2GP[i] * credits[i];
        totalCreditsSem2 += credits[i];
    }
    gpa2 = totalPointsSem2 / totalCreditsSem2;

    /* Compute CGPA */
      cgpa = (totalPointsSem1 + totalPointsSem2) /
           (totalCreditsSem1 + totalCreditsSem2);

    /* Determine classification */
    if (cgpa >= 4.40) classification = "First Class";
    else if (cgpa >= 3.60) classification = "Second Class Upper";
    else if (cgpa >= 2.80) classification = "Second Class Lower";
    else if (cgpa >= 2.00) classification = "Pass";
    else classification = "Fail";

    /* Display full academic report */
    printf("\n=========== SEMESTER I REPORT ===========\n");
    printf("%-25s %-6s %-6s %-6s %-6s\n", "Course", "Score", "Grade", "GP", "CU");

    for (i = 0; i < 8; i++) {
        printf("%-25s %-6d %-6c %-6d %-6d\n",
               sem1Courses[i], sem1Scores[i],
               sem1Grade[i], sem1GP[i], credits[i]);
    }

    printf("\n=========== SEMESTER II REPORT ===========\n");
    printf("%-25s %-6s %-6s %-6s %-6s\n", "Course", "Score", "Grade", "GP", "CU");

    for (i = 0; i < 8; i++) {
        printf("%-25s %-6d %-6c %-6d %-6d\n",
               sem2Courses[i], sem2Scores[i],
               sem2Grade[i], sem2GP[i], credits[i]);
    }

    printf("\n=========== SUMMARY ===========\n");
    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);

    return 0;
}
