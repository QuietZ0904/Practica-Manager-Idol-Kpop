
#include <stdio.h>

int main(void){
	int i=5;
	float f=3.14f;
	char c= 'A';
	
	int *pi = &i;
	float *pf = &f;
	char *pc= &c;

	printf("sizeof(int)   = %lu,  sizeof(pi) =%lu\n", sizeof(int),sizeof(pi));
	printf("sizeof(float)   = %lu,  sizeof(pf) =%lu\n", sizeof(float),sizeof(pf));
	printf("sizeof(char)   = %lu,  sizeof(pc) =%lu\n", sizeof(char),sizeof(pc));
	
	return 0;
}
