#include<stdio.h>
#include<limits.h>
int crosssum(int arr[],int low,int mid,int high){
     int leftsum=INT_MIN,rightsum=INT_MIN,sum=0;
     for(int i=mid;i>=low;i--){
        sum=sum+arr[i];
        if(sum>leftsum){
            leftsum=sum;
        }
     }
     sum=0;
     for(int j=mid+1;j<=high;j++){
        sum=sum+arr[j];
        if(sum>rightsum){
            rightsum=sum;
        }
     }
     return leftsum+rightsum;
}
int maxsubarray(int arr[],int low,int high){
    if(low==high){
        return arr[low];
    }
    int mid=(low+high)/2;
    int left=maxsubarray(arr,low,mid);
    int right=maxsubarray(arr,mid+1,high);
    int cross=crosssum(arr,low,mid,high);
    return (left>right&&left>cross)?left:(right>left&&right>cross)?right:cross;
}
int main(){
     int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result=maxsubarray(arr,0,n-1);
    printf("max subarray sum:%d",result);
    return 0;
}