#include <iostream>
#include <cstdio>
using namespace std;

long long int primeFactorization(long long int n) {
    long long int i, flag, j=0;
    while(n%2==0) {
        n = n/2;
        printf("2 ");
        j++;
    }
    for(i=3; i*i<=n; i=i+2) {
        while(n%i==0) {
            printf("%lld ", i);
            n = n/i;
            j++;
        }
    }
    if(n>2){
        printf("%lld\n", n);
        j++;
    }
    return j;
}

int main()
{
    long long int x;
    while(scanf("%lld", &x)==1){
        printf("Divisor Count: %lld\n", primeFactorization(x));
    }
}
