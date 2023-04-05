#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int grade_calc(int score);//this is the function declaration for calculating the grades
int STUDENT_INDEX=50;
int two_best(int grade1,int grade2,int grade3);
        //REMEMBER TO CREATE A FUNCTIOIN TO PLACE THE STUDENTS. THE FUNCYION SHOULD TAKE THE STUDENT STRUCTURE ARRAY INDEX AS THE ARGUMENT


//this is a structure that holds the name, index number and grade of student
typedef struct {
    char name[20];
    int index_no;
    int Math,English,Science,Social,BDT,ICT,French;
    char sex;
    int grades[7];
    int aggregate;
} Student;
//this structure holds the name and cutoff point of the boys' school as well as the courses offered
typedef struct{
    char Schoolname[20];
    int cutoff;
    char courses[50];

}BSchools;
//this structure holds the name and cutoff point of the girls' school as well as the courses offered
typedef struct{
    char Schoolname[20];
    int cutoff;
    char courses[50];

}GSchools;


int main()
{
    FILE *student_file;// we're creating a file pointer student_file that points to the student results
    Student students[STUDENT_INDEX];//we are declaring a variable that accesses the structure using the structure name "Student"
    char *token;
    char line[100];//this string variable will hold the data read from the file

    int num_students=0;
    // Open the student results,"trial_results" into the file pointer variable "student_file"
    student_file = fopen("trial_results.csv", "r");
    if (student_file == NULL) {
        printf("Error: Unable to open file \n");
        return 1;
    }
    //this line of code below is to set the pointer in the file to start reading the results
    fgets(line, sizeof(line), student_file);
    char stringhold[1];
    printf("Name\t\t\tIndex No.\tMath\tEnglish\tScience\tSocial\tBDT\tICT\tFrench\tSex\n");
    // read the data from the file into an array of Student structs
    while (fgets( line, sizeof(line), student_file) != NULL) {
        token = strtok(line, ",");
        strcpy(students[num_students].name, token);
        printf("%s\t\t",students[num_students].name);
        token = strtok(NULL, ",");
        students[num_students].index_no = atoi(token);
        printf("%d\t\t",students[num_students].index_no);
        token = strtok(NULL, ",");
        students[num_students].Math = atoi(token);
        printf("%d\t",students[num_students].Math);
        token = strtok(NULL, ",");
        students[num_students].English = atoi(token);
        printf("%d\t",students[num_students].English);
        token = strtok(NULL, ",");
        students[num_students].Science = atoi(token);
        printf("%d\t",students[num_students].Science);
        token = strtok(NULL, ",");
        students[num_students].Social = atoi(token);
        printf("%d\t",students[num_students].Social);
        token = strtok(NULL, ",");
        students[num_students].BDT= atoi(token);
        printf("%d\t",students[num_students].BDT);
        token = strtok(NULL, ",");
        students[num_students].ICT = atoi(token);
        printf("%d\t",students[num_students].ICT);
        token = strtok(NULL, ",");
        students[num_students].French = atoi(token);
        printf("%d\t",students[num_students].French);
        token=strtok(NULL,",");
        strcpy(stringhold,token);
        students[num_students].sex=stringhold[0];
        printf("%c\n",students[num_students].sex);
       num_students++;
    }
    fclose(student_file);

    //LET US READ THE FILE CONTAINING THE SCHOOLS,
    //THE CUT-OFF AND POINTSTHE COURSES OFFERED

    //schoolsdisplay
     BSchools school[6];//creating a structure  array variable for the boys' school
    char *token1;//token1 is A pointer variable to take the separated contents of the file
    FILE *cutoffs1;//declaring a pointer file for the file
    char buff1[100];//this is the string variable that is going to hold the data in the file
    int num_school1=0;//variable to hold school index for the structure array variable
    cutoffs1=fopen("boyschools_cutoffs.csv","r");    //opening the file in the read mode and putting the contents in the file pointer
    if (cutoffs1 == NULL) {      printf("Error: Unable to open file \n");    }//display an error message if file does not open

    printf("\n\tSCHOOL\t\t\tCUT-OFF\t\tCOURSES OFFERED\n");
     while (fgets( buff1, sizeof(buff1),cutoffs1) != NULL) {
        token1 = strtok(buff1, ",");
        strcpy(school[num_school1].Schoolname, token1);
        printf("%s\t\t",school[num_school1].Schoolname);
        token1 = strtok(NULL, ",");
        school[num_school1].cutoff = atoi(token1);
        printf("%d\t\t",school[num_school1].cutoff);
         token1=strtok(NULL,",");
        strcpy(school[num_school1].courses, token1);
        printf("%s\n",school[num_school1].courses);
        num_school1++;
     }
     fclose(cutoffs1);
    //for the girls' schools
   GSchools gschool[6];//creating a structure  array variable for the girls' school
    char *token2;
    FILE *cutoffs2;//declaring a pointer file for the file
    char buff2[100];//this is the string variable that is going to hold the data in the file
    int num_school2=0;
    //opening the file in the read mode and putting the contents in the file pointer
    cutoffs2=fopen("girlschools_cutoffs.csv","r");
    if (cutoffs2 == NULL) {        printf("Error: Unable to open file \n");    }

    printf("\n\tSCHOOL\t\t\tCUT-OFF\t\tCOURSES OFFERED\n");
     while (fgets( buff2, sizeof(buff2),cutoffs2) != NULL) {
        token2 = strtok(buff2, ",");
        strcpy(gschool[num_school2].Schoolname, token2);
        printf("%s\t\t",gschool[num_school2].Schoolname);
        token2 = strtok(NULL, ",");
        gschool[num_school2].cutoff = atoi(token2);
        printf("%d\t\t",gschool[num_school2].cutoff);
         token2=strtok(NULL, ",");
         strcpy(gschool[num_school2].courses,token2);
        printf("%s\n",gschool[num_school2].courses);
        num_school2++;
     }
     fclose(cutoffs2);


for (int i=0;i<num_students;++i)
{
    int ja=0;
    students[i].grades[ja]=grade_calc(students[i].Math);
    //printf("%d\t",students[i].grades[ja]);
    students[i].grades[++ja]=grade_calc(students[i].English);
    //printf("%d\t",students[i].grades[ja]);
    students[i].grades[++ja]=grade_calc(students[i].Science);
    //printf("%d\t",students[i].grades[ja]);
    students[i].grades[++ja]=grade_calc(students[i].Social);
    //printf("%d\t",students[i].grades[ja]);

    students[i].grades[++ja]=grade_calc(students[i].BDT);
     //printf("%d\t",students[i].grades[ja]);
    students[i].grades[++ja]=grade_calc(students[i].ICT);
     //printf("%d\t",students[i].grades[ja]);
    students[i].grades[++ja]=grade_calc(students[i].French);
     //printf("%d\n",students[i].grades[ja]);


}
//Let us calculate the aggregate for each student

for(int i=0;i<9;++i)
{
    int rawgrade=0;
    for(int j=0;j<4;++j){
            //we are calculating the aggregate of the first 4 subjects
        rawgrade+=students[i].grades[j];
    }
    students[i].aggregate=rawgrade+two_best(students[i].grades[4],students[i].grades[5],students[i].grades[6]);
//printf("the aggregate of student %d is:%d\n",i+1,students[i].aggregate);//I am checking if the code is working
}

        //LET US GO ON AHEAD WITH THE SCHOOL PLACEMENT
        //REMEMBER TO CREATE A FUNCTIOIN TO PLACE THE STUDENTS. THE FUNCYION SHOULD TAKE THE STUDENT STRUCTURE ARRAY INDEX AS THE ARGUMENT
printf("\nWHOSE RESULTS DO YOU WANT TO SEE?\n");
for(int i=0;i<9;i++){
   printf("%d.%s",i+1,students[i].name);
}
    int c="a"=="b";

    return 0;
}


//Function for assigning grades
int grade_calc(int score) {
    int grade;
    if (score < 40) {
        grade = 5;
    }
    else if (score <50) {
        grade = 4;
    }
    else if (score <60) {
        grade = 3;
    }
    else if (score <70) {
        grade = 2;
    }
    else if(score>=70){
        grade = 1;
    }

    return grade;
}


int two_best(int grade1,int grade2,int grade3)
{
int array[3]={grade1,grade2,grade3};
int temp=0;
        for(int i=0;i<3;++i)
        {
            for(int j=i+1;j<3;++j)
            {
                if(array[i]>array[j])
                {
                 //switch positions
                 temp=array[i];
                 array[i]=array[j];
                 array[j]=temp;

                }

            }
        }
    int sum=array[0]+array[1];
    return sum;
}
//feof(filename) checks if the file has been completely read

//I WANT TO READ THE FILES SO THAT THE PARAMETERS ARE STORED IN THE SCHOOLS STRUCT
