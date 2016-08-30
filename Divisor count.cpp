#include <iostream>
#include <cstdio>
using namespace std;

int divisorCount(int n) {
    int count = 1, divisors = 1, i;
    while(n%2==0) {
        n/=2;
        divisors++;
    }
    count = count * divisors;
    for(i=3; i*i<=n; i+=2) {
        divisors = 1;
        while(n%i==0) {
            n/=i;
            divisors++;
        }
        count = count * divisors;
    }
    if(n>1) {
        count = count * 2;
    }
    return count;
}

int main()
{
    int n;
    while(scanf("%d", &n)==1 && n) {
        cout << "Divisors: " << divisorCount(n) << endl;
    }
}

