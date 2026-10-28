#include <stdio.h>

typedef struct {
	char nombre[30];
	int edad;
	int hambre;
}Mascota;
Mascota alimentar (Mascota m);
Mascota crear_mascota(void);
void mostrarmascota(Mascota g);

int main(void){

        Mascota Luna = crear_mascota();
	Luna=alimentar(Luna);
	mostrar_mascota(Luna);
	
	
}
Mascota alimentar(Mascota m){
  m.hambre = m.hambre-20;
  return m;
}
Mascota crear_mascota(void){
  Mascota x;
  printf("Ingresa el nombre \n");
  scanf("%s", x.nombre);
  printf("ingresa la edad \n");
  scanf("%d", & x.edad);
  printf("Ingresa el nombre ");
  scanf("%d", & x.hambre);
  return x;
}
void mostrarmascota(Mascota g){
        Mascota g= {"Luna",0,50};
	printf("Nombre: %s \n ", g.nombre);
	printf("Edad: %d dias \n", g.edad);
	printf("Hambre: %d \n", g.hambre);
	return 0;
}
