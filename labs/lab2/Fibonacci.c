#include <stdio.h>

const int SIZE_NUM=200;

void pre_store(int *f){
	for (int i=0; i<SIZE_NUM; ++i)
		f[i]=0;
	f[0]=f[1]=1;
	for (int i=2; i<SIZE_NUM; ++i)
		f[i]=f[i-1]+f[i-2];
}

int recursion(int *f, int num){
	return (num==0||num==1)?1:recursion(f, num-1)+recursion(f,num-2);
}

int main(){
	int f[SIZE_NUM];
	int num, choice;
	scanf("%d%d", &num, &choice);
	if (choice == 1){
		pre_store(f);
		printf("%d\n", f[num-1]);
	}
	else printf("%d\n", recursion(f, num-1));
	return 0;
}