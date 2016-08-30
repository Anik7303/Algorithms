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
#include <map>
using namespace std;

#define MAX 1000000
#define fr(x) freopen(x, "r", stdin)
#define pfi(x) printf("%d\n", x)
#define pfl(x) printf("%lld\n", x)
#define pff(x) printf("%f\n", x)
#define pfd(x) printf("%lf\n", x)
#define pfc(x) printf("%c\n", x)
#define pfs(x) printf("%s\n", x.c_str())
#define pfn() printf("\n")
#define sci(x) scanf("%d", &x)
#define scii(x, y) scanf("%d %d", &x, &y)
#define scl(x) scanf("%lld", &x)
#define scll(x, y) scanf("%lld %lld", &x, &y)
#define sclll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define scf(x) scanf("%f", &x)
#define scff(x, y) scanf("%f %f", &x, &y)
#define scd(x) scanf("%lf", &x)
#define scdd(x, y) scanf("%lf %lf", &x, &y)
#define scc(x) scanf(" %c", &x)
#define scs(x) getline(cin, x)
#define gt() getchar()
#define pb(x) push_back(x)
#define set(x, y) memset(x, y, sizeof(x))

int stringToInteger(string s, int *a) {
    int i, j, k, l, x, y, n;
    char ch[100];
    n = s.size() + 1;
    j = l = 0;
    for(i=0; i<n; i++) {
        if(s[i]==' ' || s[i]=='\0') {
            ch[j] = '\0';
            x = 0;
            y = 1;
            for(k=j-1; k>=0; k--) {
                x+=(ch[k]-48)*y;
                y*=10;
            }
            a[l++] = x;
            j = 0;
        }else {
            ch[j++] = s[i];
        }
    }
    return l;
}

int main()
{
    string s;
    int ar[1000], i, n;
    while(getline(cin, s)) {
        n = stringToInteger(s, ar);
        for(i=0; i<n; i++) {
            printf("%d: %d\n", i+1, ar[i]);
        }
    }
}


