#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define N 100000000
#define Q N/15
#define M sqrt(N)
bool isPrime[N+2];
int prime_count, primes[Q];

void sieve_of_Eratosthenes() {
    int i, j;
    isPrime[0] = isPrime[1] = true;
    for(i=4; i<+N; i+=2) {
        isPrime[i] = true;
    }
    primes[prime_count++] = 2;
    for(i=3; i<=N; i+=2) {
        if(!isPrime[i]) {
            primes[prime_count++] = i;
            if(i<=M) {
                for(j=i*i; j<=N; j+=2*i) {
                    isPrime[j] = true;
                }
            }
        }
    }
    if(Q>prime_count) {
        cout << prime_count << " : " << Q << endl;
    }
}


int main()
{
    sieve_of_Eratosthenes();
}
