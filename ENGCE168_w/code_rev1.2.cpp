#include <stdio.h>
#include <string.h>

struct S {
    char name[32] ;
    char SubjectName[20] ;
    char semester[4] ;
    unsigned int CountSubject ;
    char code[10] ;
    int unit[3] ;
    int point[4] ;  
} ;

void getData(struct S *subject) ;
void getSubjectData(struct S *subject, int subjectCount) ;
const char* getGrade(int point) ;
void calculateAverageGrade(struct S *subject) ;
void ShowData(struct S subject) ;


int main() {

    struct S subject;
    getData(&subject);
    getSubjectData(&subject, subject.CountSubject);
    ShowData(subject);                                        
    calculateAverageGrade(&subject);

    return 0;
}//end main

void getData(struct S *subject) {
    printf("Enter your name: ");
    fgets(subject->name, sizeof(subject->name), stdin);
    subject->name[strcspn(subject->name, "\n")] = '\0';

    printf("Enter semester: ");
    scanf("%3s", subject->semester); 

    printf("Enter total subjects: ");
    scanf("%u", &subject->CountSubject);
}//end getData Func


void getSubjectData(struct S *subject, int subjectCount) {
    for (int i = 0; i < subjectCount; i++) {
        printf("\nEnter code of subject [%d]: ", i + 1);
        scanf("%s", subject->code);  
        printf("Enter name of subject Code %s: ", subject->code);
        scanf("%s", subject->SubjectName);  
        printf("Enter unit for subject %s: ", subject->SubjectName);
        scanf("%d", &subject->unit[i]);
        printf("Enter your score for subject %s: ", subject->SubjectName);
        scanf("%d", &subject->point[i]);
    }
}//end getSubject func

const char* getGrade(int point) {
    if (point >= 80) return "A";
    else if (point >= 75) return "B+";
    else if (point >= 70) return "B";
    else if (point >= 65) return "C+";
    else if (point >= 60) return "C";
    else if (point >= 55) return "D+";
    else if (point >= 50) return "D";
    else return "F";
}//end show grade func

void calculateAverageGrade(struct S *subject) {
    int totalPoints = 0;
    for (int i = 0; i < subject->CountSubject; i++) {
        totalPoints += subject->point[i];
        printf("Grade for subject %d (%s): %s\n", i + 1, subject->SubjectName, getGrade(subject->point[i]));
    }

    float average = totalPoints / (float)subject->CountSubject;
    printf("\nAverage Score: %->2f\n", average);
    printf("Average Grade: %s\n", getGrade((int)average));
}//end calculateAVG_GPA func

void ShowData(struct S subject) {
    printf("Name: %s\n", subject.name);
    printf("Semester: %s\n", subject.semester);
    printf("Total Subjects: %u\n", subject.CountSubject);

    for (int i = 0; i < subject.CountSubject; i++) {
        printf("\nSubject %d:\n", i + 1);
        printf("Subject Code: %s\n", subject.code);
        printf("Subject Name: %s\n", subject.SubjectName[i]);
        printf("Unit: %d\n", subject.unit[i]);
        printf("Score: %d\n", subject.point[i]);
        printf("Grade: %s\n", getGrade(subject.point[i]));
    }
}//end ShowData func