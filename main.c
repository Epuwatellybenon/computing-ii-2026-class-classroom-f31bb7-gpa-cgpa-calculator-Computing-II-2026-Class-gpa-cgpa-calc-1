/*
Name: Epuwat Elly Benon 
Registration Number: 25/U/BIE/18668/PE
*/

#include <stdio.h>

int main(void) {
    int getGradePoint(int score) {
    if (score >= 80) return 5;
    else if (score >= 70) return 4;
    else if (score >= 60) return 3;
    else if (score >= 50) return 2;
    else return 0;
}

char getGrade(int score) {
    if (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}

const char* getClassification(float cgpa) {
    if (cgpa >= 4.40) return "First Class";
    else if (cgpa >= 3.60) return "Second Class Upper";
    else if (cgpa >= 2.80) return "Second Class Lower";
    else if (cgpa >= 2.00) return "Pass";
    else return "Fail";
}

// ===== MAIN PROGRAM =====
int main() {
    int i;

    // ===== COURSE NAMES =====
    char *sem1Courses[8] = {
        "1.TEMB 1101", "2.TEMB 1102", "3.TEMB 1103", "4.TEMB 1104",
        "5.TEMB 1105", "6.TEMB 1106",
        "7.TEMB 1107", "8.TEMB 1108"
    };

    char *sem2Courses[8] = {
        "1.TEMB 1201", "2.TEMB 1202", "3.TEMB 1203", "4.TEMB 1204",
        "5.TEMB 1205", "6.TEMB 1206",
        "7.TEMB 1207", "8.TEMB 1208"
    };

    // ===== CREDIT UNITS =====
    int credits[8] = {4, 3, 3, 3, 3, 3, 3, 3};

    // ===== ARRAYS TO STORE SCORES =====
    int sem1Scores[8], sem2Scores[8];

    // ===== INPUT =====
    printf("Enter scores for Semester I:\n");
    for (i = 0; i < 8; i++) {
        printf("%s: ", sem1Courses[i]);
        scanf("%d", &sem1Scores[i]);
    }

    printf("\nEnter scores for Semester II:\n");
    for (i = 0; i < 8; i++) {
        printf("%s: ", sem2Courses[i]);
        scanf("%d", &sem2Scores[i]);
    }

    // ===== CALCULATIONS =====
    float totalPointsSem1 = 0, totalCreditsSem1 = 0;
    float totalPointsSem2 = 0, totalCreditsSem2 = 0;

    // ===== PRINT SEMESTER I TABLE =====
    printf("\n========== SEMESTER I REPORT ==========\n");
    printf("%-25s %-6s %-6s %-6s %-6s\n", "Course", "Score", "Grade", "GP", "CU");

    for (i = 0; i < 8; i++) {
        int gp = getGradePoint(sem1Scores[i]);
        char grade = getGrade(sem1Scores[i]);

        totalPointsSem1 += gp * credits[i];
        totalCreditsSem1 += credits[i];

        printf("%-25s %-6d %-6c %-6d %-6d\n",
               sem1Courses[i], sem1Scores[i], grade, gp, credits[i]);
    }

    // ===== PRINT SEMESTER II TABLE =====
    printf("\n========== SEMESTER II REPORT ==========\n");
    printf("%-25s %-6s %-6s %-6s %-6s\n", "Course", "Score", "Grade", "GP", "CU");

    for (i = 0; i < 8; i++) {
        int gp = getGradePoint(sem2Scores[i]);
        char grade = getGrade(sem2Scores[i]);

        totalPointsSem2 += gp * credits[i];
        totalCreditsSem2 += credits[i];

        printf("%-25s %-6d %-6c %-6d %-6d\n",
               sem2Courses[i], sem2Scores[i], grade, gp, credits[i]);
    }

    // ===== GPA =====
    float gpa1 = totalPointsSem1 / totalCreditsSem1;
    float gpa2 = totalPointsSem2 / totalCreditsSem2;

    float cgpa = (totalPointsSem1 + totalPointsSem2) /
                 (totalCreditsSem1 + totalCreditsSem2);

    const char* classification = getClassification(cgpa);

    // ===== REQUIRED SUMMARY =====
    printf("\n========== SUMMARY ==========\n");
    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);

    return 0;
}
