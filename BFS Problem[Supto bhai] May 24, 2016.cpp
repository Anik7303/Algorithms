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

#define MAX 100000000
#define IMAX 2147483647
#define fr(x) freopen(x, "r", stdin)
#define pfi(x) printf("%d", x)
#define pfin(x) printf("%d\n", x)
#define pfl(x) printf("%lld", x)
#define pfln(x) printf("%lld\n", x)
#define pff(x) printf("%f", x)
#define pffn(x) printf("%f\n", x)
#define pfd(x) printf("%lf", x)
#define pfdn(x) printf("%lf\n", x)
#define pfc(x) printf("%c", x)
#define pfcn(x) printf("%c\n", x)
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
#define scss(x, y) scanf("%s %s", x, y)
#define scs(x) getline(cin, x)
#define gt() getchar()
#define pb(x, y) x.push_back(y)
#define set(x, y) memset(x, y, sizeof(x))
#define pcase(x) printf("Case %d: ", x)
#define lp(a, x, n, y) for(a=x; a<n; a+=y)
#define lpe(a, x, n, y) for(a=x; a<=n; a+=y)
#define vln(x) x.size()

vector<int> factors;

int primefactors(int n) {
    int i, j;
    i = 0;
    while(n%2==0) {
        n/=2;
        if(i==0) {
            i = 1;
            pb(factors, 2);
        }
    }
    for(i=3; i*i<=n; i+=2) {
        if(n%i==0) {
            while(n%i==0) {
                n/=i;
            }
            pb(factors, i);
        }
    }
    if(n>1) {
        pb(factors, n);
    }
}

void bfs(int source, int destination) {
    queue<int> Q;
    map<int, int> _map;
    int d, x, y, i, top, flag;
    d = flag = 0;
    Q.push(source);
    //_map[source] = 1;
    while(!Q.empty()) {
        factors.clear();
        top = Q.front();
        Q.pop();
        //cout << "TOP: " << top << endl;
        //cout << factors.size() << endl;
        primefactors(top);
        //cout << factors.size() << endl;
        //printf("n: %d size: %d map[top]: %d\n", top, factors.size(), _map[top]);
        for(i=0; i<factors.size(); i++) {
            x = top + factors[i];
            if(_map[x]==0) {
                _map[x] = _map[top] + 1;
                Q.push(x);
            }
            if(x==destination) {
                flag = 1;
                break;
            }
        }
        d++;
        if(flag==1 || top>destination) {
            break;
        }
    }
    if(flag==1) {
        //printf("_map[%d]: %d\n", destination, _map[destination]);
        printf("%d\n", _map[destination]);
    }else {
        cout << "invalid" << endl;
    }
}

int main()
{
    int i, n, x;
    while(scanf("%d %d", &x, &n)) {
        bfs(x, n);
        factors.clear();
    }
}
