#include <stdio.h>

int main(void){
  int *p;

  if(p==NULL){
    printf("El apuntador es NULL, es seguro \n");
    
  }else {
    printf("Cuidado: el apuntador no fue inicializado \n");
  }
  return 0;
}
