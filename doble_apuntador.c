#include <stdio.h>

void asignar_valor(int **pp){
	int n=42;
	*pp= &n ;
}
int main(){
	int *p=NULL;
	asignar_valor(&p);
	
	printf("%d",*p);
	return 0;
}
