#include <iostream>
#include <cstdio>
using namespace std;

long long BigMod_Algorithm(int a, int b, int x) {
    return ((long long)(a%x) * (b%x)) % x;
}

int BigMod(int a, int b, int x) {
    if(b==0) return 1 % x;
    long long p = BigMod(a, b/2, x);
    if(b%2==1) return BigMod_Algorithm(BigMod_Algorithm(p, p, x), a, x);
    return BigMod_Algorithm(p, p, x);
}

int main()
{
    int a, b, x;
    while(scanf("%d %d %d", &a, &b, &x)==3) {
        cout << BigMod(a, b, x) << endl;
    }
}
