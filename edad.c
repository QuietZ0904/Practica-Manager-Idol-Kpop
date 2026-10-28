#include <stdio.h>
int main(void){
  int edad = 20;
  int *p_edad= &edad;
  
  printf("Antes: edad = %d \n", edad);
  *p_edad= 25;
  printf("Despues: edad = %d \n",edad);
  return 0;
}
