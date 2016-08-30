#include <iostream>
#include <cstdio>
using namespace std;

long long GCD(long long a, long long b) {
    if(b==0) {
        return a;
    }else {
        return GCD(b, a%b);
    }
}

long long LCM(long long a, long long b, long long x) {
    return (a/x)*b;
}

int main()
{
    long long a, b, x;
    while(scanf("%lld %lld", &a, &b)==2 && a && b) {
        x = GCD(a, b);
        cout << "GCD between " << a << " & " << b << ": " << x << endl;
        cout << "LCM between " << a << " & " << b << ": " << LCM(a, b, x) << endl;
    }
}
