#include<stdio.h>
#include<windows.h>
int n2_series(int n,int x);
int main()
{
    int a;
    SetConsoleTitle("Solve of n2 Series");
    while(1){
    printf("Enter the value of x: ");
    scanf("%d",&a);
    printf("The value at %dth place = %d\n\n",a,n2_series(a,0));}
}
int n2_series(int n,int x)
{
    if(n==0)
        return x;
    else
        return n2_series(n-1,n*n+x);
}
