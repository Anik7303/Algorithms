#include<stdio.h>
int main()
{
    int n;
    printf("How many elements do you wanna input?\n");
    scanf("%d",&n);
    int a[n],i,k,highest,second_highest,index;
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
    highest=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>highest)
        {
            highest=a[i];
            index=i;
        }
    }
    printf("\nThe highest element is %d and it is located in index %d",highest,index);
    second_highest=0;
    for(i=0;i<n;i++)
    {
        if(index!=i)
        {
            if(a[i]>second_highest)
            {
                second_highest=a[i];
                k=i;
            }
        }
    }
    index=k;
    printf("\nThe Second highest element is %d and it is located in index %d",second_highest,index);
    return 0;
}
