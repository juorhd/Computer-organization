#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[100]; // No one should have a name longer than this
    int *grades;    // This is the pointer to hold the (integer) grades
    int count;      // The number of grades
};

int main() {
	printf ("How many students are there? ");
	int stu_num;
	scanf("%d", &stu_num);

	struct student *students;
	students = (struct student *)malloc(stu_num * (sizeof(struct student)));

	int i, j;
	for (i = 0; i < stu_num; i++) {
		printf ("Enter the name of student %d:", i);
		scanf ("%s", students[i].name);
		printf ("How many grades does %s have?", students[i].name);
		scanf ("%d", &students[i].count);
		students[i].grades = (int *)malloc(students[i].count * (sizeof(int)));
		for (j = 0; j < students[i].count; j++) {
			printf ("Enter the next grade:");
			scanf ("%d", &students[i].grades[j]);
		}
	}

	for (i = 0; i < stu_num; i++) {
		double sum = 0;
		for (j = 0; j < students[i].count; j++)
			sum += students[i].grades[j];
		printf ("%s has an average grade of %.2f\n", students[i].name, sum/students[i].count);
	}

	return 0;
}