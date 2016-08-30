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

#define MAX 1000
#define fr(x) freopen(x, "r", stdin)
#define pfi(x) printf("%d\n", x)
#define pfl(x) printf("%lld\n", x)
#define pff(x) printf("%f\n", x)
#define pfd(x) printf("%lf\n", x)
#define pfc(x) printf("%c\n", x)
#define pfcs(x) printf("%s\n", x)
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
#define sccs(x) scanf("%s", x)
#define scs(x) getline(cin, x)
#define gt() getchar()
#define pb(x, y) x.push_back(y)
#define set(x, y) memset(x, y, sizeof(x))
#define pcase(x) printf("Case %d: ", x)
#define lp(a, x, n, y) for(a=x; a<n; a+=y)
#define lpe(a, x, n, y) for(a=x; a<=n; a+=y)
#define vln(x) x.size()

bool isprime[MAX];
vector<int> primes;

void seiveOfEratosthenes() {
    int i, j, k;
    k = sqrt(MAX)+1;
    pb(primes, 2);
    lpe(i, 3, MAX, 2) {
        if(!isprime[i]) {
            pb(primes, i);
            if(i<=k) {
                lpe(j, i*i, MAX, 2*i) {
                    isprime[j] = true;
                }
            }
        }
    }
    pfi(vln(primes));
}

int main()
{
    seiveOfEratosthenes();
    /*
    int i;
    lp(i, 0, vln(primes), 1) {
        printf("%d ", primes[i]);
    }
    */
}
