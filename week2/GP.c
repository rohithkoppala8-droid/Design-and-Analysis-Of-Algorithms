#include<stdio.h>
#include<math.h>
int main(){
    int n;
    float a,r;
    printf("enter the first element, no of terms and common ration :\n");
    scanf("%f %d %f",&a,&n,&r);
    float sum= a*(pow(r,n)-1)/(r-1);
    printf("sum:%f",sum);
    return 0;
}