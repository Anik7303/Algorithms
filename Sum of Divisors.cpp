#include <iostream>
#include <cstdio>
using namespace std;

int power(int x, int y) {
    int a, i;
    a = 1;
    for(i=0; i<y; i++) {
        a*=x;
    }
    return a;
}

int sum_of_Divisors(int n) {
    int sum = 1, divisors = 1, i;
    while(n%2==0) {
        n/=2;
        divisors++;
    }
    sum*=(power(2, divisors)-1);
    for(i=3; i*i<=n; i+=2) {
        divisors = 1;
        while(n%i==0) {
            n/=i;
            divisors++;
        }
        sum*=(power(i, divisors)-1)/(i-1);
    }
    if(n>2) {
        sum*=((n*n)-1)/(n-1);
    }
    return sum;
}

int main()
{
    int n;
    while(scanf("%d", &n)==1 && n) {
        printf("Sum: %d\n", sum_of_Divisors(n));
    }
}
