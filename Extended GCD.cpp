#include <iostream>
#include <cstdio>
using namespace std;

int egcd(int a, int b, int &x, int &y) {
    if(a==0) {
        x = 0, y = 1;
        return b;
    }
    int x1, y1, d = egcd(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}

int main()
{
    int a, b, x, y, gcd;
    while(scanf("%d %d", &a, &b)==2 && a && b) {
        gcd = egcd(a, b, x, y);
        cout << "x: " << x << " y: " << y << endl;
        cout << "GCD between " << a << " & " << b << " : " << gcd << endl;
        cout << "LCM between " << a << " & " << b << " : " << (a*b)/gcd << endl;
    }
}
