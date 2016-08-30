#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 1000
int divisors[N];

int primeFactors(int x) {
    int i, flag, count;
    flag = count = 0;
    while(x%2==0) {
        flag = 1;
        x/=2;
    }
    if(flag==1) {
        divisors[count++] = 2;
    }
    flag = 0;
    for(i=3; i*i<=x; i+=2) {
        flag = 0;
        while(x%i==0) {
            x/=i;
            flag = 1;
        }
        if(flag==1) {
            divisors[count++] = i;
        }
    }
    if(x>2) {
        divisors[count++] = x;
    }
    return count;
}

int euler_totient_phi(int n) {
    int i, l;
    float x = n;
    l = primeFactors(n);
    for(i=0; i<l; i++) {
        x*=1-(1.0/divisors[i]);
    }
    return (int)x;
}

int main()
{
    int x;
    while(scanf("%d", &x)==1) {
        cout << "Euler's Totient Phi: " << euler_totient_phi(x) << endl;
    }
}

