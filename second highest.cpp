#include<stdio.h>
int main()
{
    int i,k,n,highest_number,index,second_highest;
    printf("How many elements do you want?\n");
    scanf("%d",&n);

    int a[n];
    printf("Please Enter your number\n");

    for(i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }

    highest_number=a[0],index=0;
    for(i=0;i<n;i++)
    {
        if(highest_number<=a[i])
        {
            highest_number=a[i];
            index=i;
        }
    }

    printf("\nThe highest number is %d & index number is %d\n",highest_number,index);

    second_highest=a[0];
    for(i=0;i<n;i++)
    {
        if(index!=i)
        {
            if(second_highest<=a[i])
            {
                second_highest=a[i];
                k=i;
            }
        }
    }
    index=k;
    printf("\nThe second highest number is %d & index number is %d\n",second_highest,index);
    return 0;


}
