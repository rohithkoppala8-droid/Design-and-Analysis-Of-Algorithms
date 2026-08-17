#include<stdio.h>
int main(){
    int n,k;
    printf("enter which smallest element to find:\n");
    scanf("%d",&k);
    printf("enter the no of elemnts of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
        int swap=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swap=1;
                }
            }
            if(swap==0)
               break;
        }
    printf("%dth smallest element is %d",k,arr[k-1]);

    
     return 0;

 }
