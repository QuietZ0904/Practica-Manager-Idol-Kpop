#include <stdio.h>

void  suma(int *a,int *b){
    printf("La suma es: %d \n",(*a)+(*b));
}
void resta(int *a, int *b){
  printf("La resta es: %d \n",(*a)-(*b));
}
void multiplicacion(int *a, int *b){
  printf("La multiplicacion es: %d \n",(*a)*(*b));
}
void division(int *a, int *b){
  printf("La division es: %d \n",(*a)/(*b));
}

void calcular(int *a,int *b,void (*ptr)(int*,int*)){
  printf("Calculando");
  ptr(a,b);
}


int main(){
  int a=5;
  int b=5;
  
  calcular(&a,&b, suma);
  calcular(&a,&b, resta);
  calcular(&a,&b, multiplicacion);
  calcular(&a,&b, division);
}


