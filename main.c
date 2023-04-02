#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//this is the function declaration for calculating the grades
int grade_calc(int score);
int STUDENT_INDEX=50;
void schoolsdisplay();
int two_best(int grade1,int grade2,int grade3);

//this is a structure that holds the name, index number and grade of student
typedef struct {
    char name[50];
    int index_no;
    int Math,English,Science,Social,BDT,ICT,French;
    char *sex;//we are using a pointer variable here because we'll be directly assigning the token to it(token holds pointer values)
    int grades[7];
    int aggregate;
} Student;

typedef struct{
    char Schoolname[30];
    int cutoff;

}Schools;


int main()
{
    // we're creating a file pointer student_file that points to the student results
    FILE *student_file;
    //we are declaring a variable that accesses the structure using the structure name "Student"
    Student students[STUDENT_INDEX];
    char *token;
    char line[100];

    int num_students=0;
    // Open the student results,"trial_results" into the file pointer variable "student_file"
    student_file = fopen("trial_results.csv", "r");
    if (student_file == NULL) {
        printf("Error: Unable to open file \n");
        return 1;
    }
    //this line of code below is to set the pointer in the file to start reading the results
    fgets(line, sizeof(line), student_file);

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
        students[num_students].sex=token;
        printf("%s\n",students[num_students].sex);
       num_students++;
    }

    fclose(student_file);

    //LET US READ THE FILE CONTAINING THE SCHOOLS,
    //THE CUT-OFF AND POINTSTHE COURSES OFFERED

    schoolsdisplay();

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
//I am just trying something out
/*for (int i=0;i<7;++i)
{
    printf("%d\n",students[2].grades[i]);

}
printf("%d\n",students[2].grades[3]);
printf("the num-students is %d",num_students);*/

/*Schools school[30];
char readschool[100];
bool readstatus=true;
FILE *school1=fopen("boyschools_cutoffs.txt","r");
do{
    fgets(readschool,100,school1);
        if(feof(school1)) readstatus=false;
    school1[]
}while(readstatus=true);
*/
        //LET US GO ON AHEAD WITH THE SCHOOL PLACEMENT
/*for(int i=0;i<9;i++){
    if(students[i].sex=='M'){

    }
}*/
printf("%s",students[4].sex);
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
//In this function we are displaying the schools, both boys and girls
//we could have done so in the main function but we wanted better readability in the
void schoolsdisplay(){
    //for the boys' schools
      //declaring a pointer file for the file
    FILE *cutoffs1;
    char buff1[150];//this is the string variable that is going to hold the data in the file
    //opening the file in the read mode and putting the contents in the file pointer
    cutoffs1=fopen("boyschools_cutoffs.txt","r");
    if (cutoffs1 == NULL) {
        printf("Error: Unable to open file \n");

    }
      while (fgets( buff1, sizeof(buff1),cutoffs1 ))
    {
    printf("%s", buff1) ;
    }
    fclose(cutoffs1);
    //for the girls' schools
      //declaring a pointer file for the file

    FILE *cutoffs2;
    char buff2[150];//this is the string variable that is going to hold the data in the file
    //opening the file in the read mode and putting the contents in the file pointer
    cutoffs2=fopen("girlschools_cutoffs.txt","r");
    if (cutoffs2 == NULL) {
        printf("Error: Unable to open file \n");

    }
      while (fgets( buff2, sizeof(buff2),cutoffs2 ))
    {
    printf("%s", buff2) ;
    }
    fclose(cutoffs2);

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
//feof(filename) checks if the file has been

//I WANT TO READ THE FILES SO THAT THE PARAMETERS ARE STORED IN THE SCHOOLS STRUCT
