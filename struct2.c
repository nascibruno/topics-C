#include <stdio.h>
#include <conio.h>
int main(void)
{
	/*Create a struct */
	struct student_record
	{
		char name[50];
		char subject[30];
		float test_grade1;
		float test_grade2;
	};
	
	/*Create  a var student that will be type struct student_record */
	
	struct student_record student;
	
	printf("\n---------- student register -----------\n\n\n");
	
	printf("\nStudent name ......: ");
	fflush(stdin);
	fgets(student.name, 50, stdin);
	
	
	/*We are going to use the command fgets() to read the strings, in 
	case the name of the student and the discipline
    fgets (variable, string size, input)
    As we are reading from the keyboard the input is stdin (standard input),
    however in another case, the input could also be a file */
	

	printf("\nSubject ......: ");
	fflush(stdin);
	fgets(student.subject, 30, stdin);
	
	printf("\nWrite the 1th. grade ..: ");
	
	scanf("%f", &student.test_grade1);
	
	printf("\nWrite the 2th. grade ..: ");
	scanf("%f", &student.test_grade2);
	
	printf("\n\n --------- Read the Data Struct ---------\n\n");
	printf("Name ...........: %s\n", student.name);
	printf("Subject ........: %s\n", student.subject);
	printf("Test Grade 1 ...: %.2f\n" , student.test_grade1);
	printf("Test Grade 2 ...: %.2f\n" , student.test_grade2);
	
	//getch();
	return(0);
}