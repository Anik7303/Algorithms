#include<stdio.h>
void show_3D(int array[][2][2],int a,int b,int c);

int main()
{
    int array[2][2][2],p,q,r;
    for(p=0;p<2;p++)
      for(q=0;q<2;q++)
        for(r=0;r<2;r++)
          scanf("%d",&array[p][q][r]);
    show_3D(array,2,2,2);
    return 0;
}

void show_3D(int array[][2][2],int a,int b,int c)
{
    int i,j,k;
    for(i=0;i<a;i++)
     for(j=0;j<b;j++)
      for(k=0;k<c;k++)
        printf("%d ",array[i][j][k]);
}
