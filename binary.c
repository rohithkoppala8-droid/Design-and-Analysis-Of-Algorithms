#include<stdio.h>
int main(){
int size,key;
  printf("enter the size of array:\n");
  scanf("%d",&size);
  int array[size];
  printf("enter the elements of the array in a sorted way:\n");
  for(int i=0;i<size;i++){
     scanf("%d",&array[i]);
  }
  printf("enter the key element:\n");
  scanf("%d",&key);
  int low=0,high=size-1,mid;
  while(low<=high){
    mid=(low+high)/2;
    if (array[mid]==key){
       printf("%d is found at the position %d and index %d\n",key,mid+1,mid);
       break;
     }
     else if(array[mid]<key){
       low=mid+1;
     }
     else {
       high=mid-1;
     }
 }  
 if(low>high){
 printf("key not found\n");
 }
return 0;
}
