#include <stdio.h>

void saludo_formal(const char *nombre){
  printf("Buenos dias, %s. \n",nombre);
}
void saludo_casual(const char *nombre){
  printf("Hola %s , que onda! \n", nombre);
}

void procesar_usuario(const char *nombre, void (*callback)(const char *)){
  printf("Procesando usuario...\n");
  callback(nombre);
}

int main(){
  procesar_usuario("Ana",saludo_formal);
  procesar_usuario("Luis",saludo_casual);
  return 0;
}
