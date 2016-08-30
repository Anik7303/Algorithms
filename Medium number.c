#include<stdio.h>
int main()
{
    int n,i;
    printf("How many elements do you wanna input?\n");
    scanf("%d",&n);
    float a[n],sum,medium;
    for(i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%f",&a[i]);
    }
    sum=0;
    for(i=0;i<n;i++)
        sum+=a[i];
    medium=sum/n;
    for(i=0;i<n;i++)
    {
        if((int)medium==(int)a[i])
        {
            printf("The medium element is %0.1f and it is located in index %d\n",a[i],i);
            break;
        }
    }
    return 0;
}
