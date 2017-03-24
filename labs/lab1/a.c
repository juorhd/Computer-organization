#include <stdio.h>
#include <math.h>

long int factorial(long int n){
	if (n == 0) return 1;
	else return n*factorial(n-1);
}

int main(){
	printf("what is n");
	long int n;
	scanf("%ld", &n );
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=i; ++j)
			printf("*");
		printf("\n");
	}
	printf("\nthe hypotenuse is %.2lf", n*sqrt(2));
	long int f[21];
	long int product = 1;
	for (int i=2; i<=n; ++i){
		product*=i;
		f[i] = product;
	}
	printf("\nn factorial is:  %ld, %ld\n", factorial(n), f[n]);
	return 0;
}