#include <stdio.h>

int main(){
  int filas, columnas;
  int lugaesEstacionamineto;
  int lugaresOcupados=0, porcentajeOcupacion;
  int cordenadaX=0,cordenadaY=0, libreEncontrado=0, espaciosLibres=0;
  int espaciosFilaConMasEspacios=0;
  int filaMasEspacios=0;
  
  printf("Ingresa el # de filas");
  scanf("%d", &filas);
  printf("Ingresa el # de columnas");
  scanf("%d", &columnas);
  
    for(int i=0 ; i<= filas-1; i++){
      printf("\n");
    for(int j=0 ; j<=columnas-1; j++){
      printf("0 ");
      }
    }
  
  int lugaresEstacionamiento[filas][columnas];
  filas--;
  columnas--;
  
  printf("Ingresa el estado actual del estacionamiento 1= ocupado 0= libre  \n");
  for(int i=0 ; i<= filas; i++){
    for(int j=0 ; j<=columnas; j++){
      printf("Lugar %d, %d", i , j);
      scanf("%d", &lugaresEstacionamiento[i][j]);
      
    }
  }
  printf("Estado actual \n");
      for(int i=0 ; i<= filas; i++){
        printf("\n");
      for(int j=0 ; j<=columnas; j++){
        printf("%d |", lugaresEstacionamiento[i][j]);
      }
    }
    for(int i=0 ; i<= filas; i++){
        for(int j=0 ; j<=columnas; j++){
            if(lugaresEstacionamiento[i][j]==1){
                lugaresOcupados++;
            }
            if(lugaresEstacionamiento[i][j]==0 && libreEncontrado==0){
                cordenadaX=i;
                cordenadaY=j;
                libreEncontrado=1;
            }
      }
    } 
    
    porcentajeOcupacion = (lugaresOcupados / ((filas+1) * (columnas+1))) * 100;
    for(int i=0 ; i<= filas; i++){
        for(int j=0 ; j<=columnas; j++){
        if(lugaresEstacionamiento[i][j]==0){
              espaciosLibres++;
         }
       }
       if(espaciosFilaConMasEspacios < espaciosLibres){
        espaciosFilaConMasEspacios = espaciosLibres;
        filaMasEspacios = i ;
       }
    }
    printf("porcentaje de ocupacion = %d \n", porcentajeOcupacion);
    printf("Primer espacio libre fila %d - columna %d \n", cordenadaX,cordenadaY);
    printf("Fila con mas espacios libres = %d \n", filaMasEspacios);
    
    
}

