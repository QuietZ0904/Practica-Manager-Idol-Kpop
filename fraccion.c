#include <stdio.h>
typedef struct{
  int numerador;
  int denominador;
}Fraccion;
Fraccion Suma(Fraccion a, Fraccion b);
Fraccion Resta(Fraccion a, Fraccion b);
Fraccion Multiplicacion(Fraccion a, Fraccion b);
Fraccion Division(Fraccion a, Fraccion b);
Fraccion Simplifica(Fraccion a, Fraccion b);


int main(){
  Fraccion f1,f2;
  
  Printf("Ingresa el numerador de la primer fraccion \n")
  scanf("%d",& f1.numerador);
  Printf("Ingresa el denominador de la primer fraccion \n")
  scanf("%d",& f1.denominador);
  Printf("Ingresa el numerador de la segunda fraccion \n")
  scanf("%d",& f2.numerador);
  Printf("Ingresa el denominador de la segunda fraccion \n")
  scanf("%d",& f2.denominador);
  
  Fraccion resultador = Suma(f1,f2);
  printf("La suma de tus fracciones es: %d / %d",resultado.numerador ,resultado.denominador);
  Fraccion resultador = Resta(f1,f2);
  printf("La resta de tus fracciones es: %d / %d",resultado.numerador ,resultado.denominador);
  Fraccion resultador = Multiplicacion(f1,f2);
  printf("La multiplicacion de tus fracciones es: %d / %d",resultado.numerador ,resultado.denominador);
  Fraccion resultador = Division(f1,f2);
  printf("La division de tus fracciones es: %d / %d",resultado.numerador ,resultado.denominador);
  
  return 0;
}
Fraccion Suma(Fraccion a, Fraccion b){

  Fraccion resultado;
  
  resultado.numerador= (( a.numerador * b.denominador) + (b.numerador * a.denominador));
  resultado.denominador= (a.denominador * b.denominador);
  return reultado;
}
Fraccion Resta(Fraccion a, Fraccion b){

  Fraccion resultado;
  
  resultado.numerador= (( a.numerador * b.denominador) - (b.numerador * a.denominador));
  resultado.denominador= (a.denominador * b.denominador);
  return reultado;
}
Fraccion Multiplicacion(Fraccion a, Fraccion b){

  Fraccion resultado;
  
  resultado.numerador= ( a.numerador * b.numerador);
  resultado.denominador= (a.denominador * b.denominador);
  return reultado;
}
Fraccion Division(Fraccion a, Fraccion b){

  Fraccion resultado;
  
  resultado.numerador= ( a.numerador * b.denominador);
  resultado.denominador= (a.denominador * b.numerador);
  return reultado;
}
Fraccion Simplifica(Fraccion a, Fraccion b){
  
}

