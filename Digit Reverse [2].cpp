#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
using namespace std;

#define MAX 1000000
#define fr(x) freopen(x, "r", stdin)
#define pfi(x) printf("%d\n", x)
#define pfl(x) printf("%lld\n", x)
#define pff(x) printf("%f\n", x)
#define pfd(x) printf("%lf\n", x)
#define pfc(x) printf("%c\n", x)
#define pfs(x) printf("%s\n", x.c_str())
#define sci(x) scanf("%d", &x)
#define scii(x, y) scanf("%d %d", &x, &y)
#define scl(x) scanf("%lld", &x)
#define scll(x, y) scanf("%lld %lld", &x, &y)
#define scf(x) scanf("%f", &x)
#define scff(x, y) scanf("%f %f", &x, &y)
#define scd(x) scanf("%lf", &x)
#define scdd(x, y) scanf("%lf %lf", &x, &y)
#define scc(x) scanf("%c", &x)
#define scs(x) getline(cin, x)
#define gt() getchar()
#define pb(x) push_back(x)
#define set(x, y) memset(x, y, sizeof(x))

int digitCount(long long x) {
    int i=0;
    while(x>0) {
        i++;
        x/=10;
    }
    return i;
}

long long reverseDigit(long long x) {
    long long digit, a, n, p;
    n = digitCount(x);
    p = 1;
    for(long long i=1; i<n; i++) {
        p *= 10;
    }
    digit = 0;
    while(n--) {
        a = x % 10;
        a *= p;
        p /= 10;
        digit += a;
        x /= 10;
    }
    return digit;
}

int main()
{
    long long x;
    scl(x);
    pfl(reverseDigit(x));
}
