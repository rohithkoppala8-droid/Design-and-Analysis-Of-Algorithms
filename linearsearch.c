#include<stdio.h>
int main(){
  int size,key;
  printf("enter the size of array:\n");
  scanf("%d",&size);
  int array[size];
  printf("enter the elements of the array:\n");
  for(int i=0;i<size;i++){
     scanf("%d",&array[i]);
  }
  printf("enter the key element:\n");
  scanf("%d",&key);
  for(int i=0;i<size;i++){
     if(array[i]==key){
       printf("%d is found at position %d and index %d\n",key,i+1,i);
       return 0;
      }
  }
  printf("element not found\n");
return 0;
}
