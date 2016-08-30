#include <iostream>
#include <cstdio>
using namespace std;

#define N 10000000
#define sf scanf
#define pf printf
int isPrime[N+2];

void sieveOfEratosthenes() {
    int i, j;
    isPrime[0] = isPrime[1] = 1;
    for(i=4; i<=N; i+=2) {
        isPrime[i] = 1;
    }
    for(i=3; i*i<=N; i+=2) {
        if(!isPrime[i]) {
            for(j=i*i; j<=N; j+=i*2) {
                isPrime[j] = 1;
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("Primes[1].txt", "w", stdout);
    long long int x, i, count=0;
    sieveOfEratosthenes();/*
    for(i=1; i<=N; i++) {
        if(!isPrime[i]) {
            cout << i << endl;
        }
    }
    /**/
    for(i=1; i<=N; i++) {
        if(isPrime[i]==0) {
            count++;
        }
    }
    printf("Count: %lld\n", count);/**/

    while(sf("%lld", &x)==1 && x) {
        if(isPrime[x]==0) {
            pf("%lld is a prime number.\n", x);
        }else {
            pf("%lld is a not prime number.\n", x);
        }
    }/**/
    //fclose(stdin);
    //fclose(stdout);
}
