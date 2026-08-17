#include<stdio.h>
int main(){
    int n;
    float a,r;
    printf("enter the first element, no of terms and common ration :\n");
    scanf("%f %d %f",&a,&n,&r);
    int power=1;
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=a*power;
        power=power*r;
    }
    printf("the sum of the GP is :%f",sum);
    return 0;
}