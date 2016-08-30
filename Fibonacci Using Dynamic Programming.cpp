#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

#define N 100
#define mod 100000007
int fib[N];

int bigmod(int a, int b) {
    return (a%mod+b%mod)%mod;
}

int fibonacci(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    if(fib[n]!=-1) return fib[n];
    //return fib[n] = fibonacci(n-1) + fibonacci(n-2);
    return fib[n] = bigmod(fibonacci(n-1), fibonacci(n-2));
}

int main()
{
    int i, x;
    memset(fib, -1, sizeof(fib));
    printf("Limit: 99th fibonacci\n");
    while(scanf("%d", &x)==1 && x>=0) {
        printf("%d th fibonacci number is %d.\n", x, fibonacci(x));
    }
}
