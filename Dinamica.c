#include <stdio.h>
#include <stdlib.h>

int main(void){
  int *p;
  
  p =malloc (sizeof(int));
  if(p==NULL){
    printf("No hay memmoria disponible");
    return 1;
  }
  
  *p = 42;
  printf("Valor: %d \n  ",*p);
  
  free(p);
  p = NULL;
  return 0;
  
}
