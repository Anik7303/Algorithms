#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

long long int digitCount(long long int x) {
    long long int i = 0;
    while(x>0) {
        x = x/10;
        i++;
    }
    return i;
}

long long int digitRev(long long int x) {
    long long int len , i, a, p, t, r, k;
    p = 1, t = 0;
    len = digitCount(x);
    for(i=len-1; i>=0; i--) {
        for(k=1, r=1; k<=i; k++) {
            r = r*10;
        }
        a = x/r;
        a = a%10;
        a = a*p;
        t = t+a;
        p = p*10;
    }
    return t;
}

int main()
{
    long long int x;
    while(scanf("%lld", &x)==1) {
        printf("Reversed Digit: %lld\n", digitRev(x));
    }
}
