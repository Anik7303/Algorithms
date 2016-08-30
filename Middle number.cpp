#include<stdio.h>
#include<windows.h>
int main()
{
    SetConsoleTitle("Middle Number");
    long int g,h,i,j,k,l,m,n,o,p,q,r,s;
    printf("Enter the number of elements\n");
    scanf("%ld",&n);
    double a[n],b[n],sum,medium,sample;
    for(g=0;g<n;g++)
    {
        printf("a[%ld]=",g);
        scanf("%lf",&a[g]);
        sum+=a[g];
    }
    medium=sum/n;
    for(h=0;h<n;h++)
    {
        b[h]=medium-a[h];
        if(b[h]<0)
        {
            b[h]*=-1;
        }
    }
    sample=b[0];
    for(k=0;k<n;k++)
    {
        if(sample>b[k])
        {
            sample=b[k];
            m=k;
        }
    }
    printf("\n\nThe middle number is %0.2lf And its index is %ld\n\n",a[m],m);
    return 0;
}
