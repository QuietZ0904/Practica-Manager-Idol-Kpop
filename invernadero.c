#include <stdio.h>

int main(){
  float temperatura [24];
  float tempLimite;
  float tempMax;
  float tempMin;
  float promedio=0;
  int totalSupCritico=0;
  
  printf("----Invernadero---- \n");
  printf("Control de temperaturas que no deberia superar el invernadero: \n");
  scanf("%f", & tempLimite);
  
  for(int i=0 ; i<=23 ; i++){
    printf("Ingresa las temperatura de las %d:00: \n",i);
    scanf("%f", & temperatura[i]);
  }
  tempMax = temperatura[0];
  tempMin = temperatura[0];
  
  for(int i=0 ; i<=23 ; i++){
    
    promedio=promedio + temperatura[i]; 
    
    if(tempMax < temperatura[i]){
      tempMax = temperatura[i];
    }
    if(tempMin > temperatura[i]){
      tempMin = temperatura[i];
    }
    if(temperatura[i] > tempLimite){
      totalSupCritico ++;
    }  
  }
  promedio = promedio/24 ;
  
  printf("La temperatura Maxima fue: %f, la Minima: %f \n",tempMax, tempMin);
  
  printf ("El promedio de temperatura es: %f y la temperatura limite se supero: %d veces", promedio, totalSupCritico);
  
}
