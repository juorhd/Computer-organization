#include <stdio.h>
#include <stdlib.h>

int main() {
	printf ("How many grades does the student have? ");
	int num;
	scanf("%d", &num);

	int *grades;
	grades = (int *)malloc(num * (sizeof(int)));

	int i;
	double sum = 0.0;
	for (i = 0; i < num; i++) {
		printf("Enter the next grade: ");
		scanf("%d", &grades[i]);
		sum += grades[i];
	}

	printf("The average grade is %.2f\n", sum/num);
	free(grades);
	return 0;
}