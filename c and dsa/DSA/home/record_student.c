/* write the c-program for creation of the student record of different subject marks and calculate its percentage and grades of 10 students using structure and DMA*/

#include <stdio.h>
#include <stdlib.h>

typedef struct record_student
{
  char name[50];
  char subjects_name[50];
  int marks;
} student;

int main()
{
  int n;
  printf("Enter how many subjects does a student have in its curriculum: ");
  scanf("%d", &n);

  student *temp = (student *)malloc(10 * sizeof(student));
  if (temp == NULL)
  {
    printf("Memory allocation failed.");
    return 1;
  }
  for (int i = 0; i < 10; i++)
  {
    printf("Enter the name of student %d: ", i + 1);
    scanf("%s", temp[i].name);
  
    int total_marks = 0;
    for (int j = 0; j < n; j++)
    {
      printf("\nEnter the name of subject %d: ", j + 1);
      scanf("%s", temp[i].subjects_name);
      printf("Enter marks for subject %d: ", j + 1);
      scanf("%d", &temp[i].marks);

      total_marks += temp[i].marks;
    }
    
    float percentage = (float)total_marks / n;
    //grade printing..
    //if (percentage/10>9) -->print outstanding..

    printf("Percentage for student %d (%s): %f\n", i + 1, temp[i].name, percentage);
    float cgpa=percentage/10;
    printf("your grade is: 0.2%f",cgpa);

  }
  return 0;
}
