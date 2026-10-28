#include <stdio.h>
void invertirSecuencia(int **pp){
  int *actual= *pp;
  int *fin = *pp+5;
  
  int temp;
  
  while(actual<fin){
    temp = *actual;
    *actual = *fin;
    *fin = temp;
    actual++;
    fin--;
  }
}
int main(){
  int arr[5]={32,28,25,22,20};
  int *ap= arr;
  int *actual=NULL;
  int *fin=NULL;
  int **dobleptr=NULL;
  
  int n= sizeof(arr)/sizeof(arr[0]);
  actual=arr;
  fin=arr+n;
  while(actual<fin){
    printf("%d \n", *actual );
    actual++;
  }
  
  actual = arr;
  
  for(int i=0; i<n;i++){
    printf("Arreglo[%d] =%d\n",i++, *(ap + i));
  }
  
  
  dobleptr= &actual;
  
  invertirSecuencia(dobleptr);
  for(int i=0; i<n;i++){
    printf("Arreglo[%d] =%d\n",i++, *(ap + i));
  }
  return 0;
}

