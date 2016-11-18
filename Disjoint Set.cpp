#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <list>
#include <map>
#include <utility>
#include <sstream>
#include <fstream>
using namespace std;

typedef long long int ll;
typedef int _i;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef priority_queue<int> pqi;
typedef priority_queue<long long int> pql;
typedef priority_queue<string> pqs;
typedef map<int, int> mii;
typedef map<long long int, long long int> mll;
typedef map<int, string> mis;
typedef map<long long int, string> mls;
typedef map<int, char> mic;
typedef map<char, int> mci;
typedef map<string, int> msi;
typedef map<string, long long int> msl;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<long long int, string> pls;
typedef pair<string, long long int> psl;
typedef queue<int> qi;
typedef queue<long long int> ql;
typedef queue<string> qs;
typedef deque<int> di;
typedef deque<ll> dl;
typedef deque<char> dc;
typedef deque<string> ds;

#define IMAX 2147483647
#define IMIN -2147483646
#define fr(x) freopen(x, "r", stdin)
#define fo(x) freopen(x, "w", stdout)
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
#define pfcs(x) printf("%s", x)
#define pfcsn(x) printf("%s\n", x)
#define pfs(x) printf("%s", x.c_str())
#define pfsn(x) printf("%s\n", x.c_str())
#define pfn() printf("\n")
#define pfsp() printf(" ")
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
#define pu(x, y) x.push(y)
#define mp(a, b) make_pair(a, b)
#define mset(x, y) memset(x, y, sizeof(x))
#define pcase(x) printf("Case %d: ", x)
#define lp(a, x, n, y) for(a=x; a<n; a+=y)
#define lpe(a, x, n, y) for(a=x; a<=n; a+=y)
#define sln(x) x.size()
#define acl(x) x.clear()
#define qcl(x) {while(!x.empty()) x.pop(); }

template<class T> T maxT(T a, T b) {return a>b ? a: b;}
template<class T> T gcd(T a,T b) {return a==0 ? b : gcd(b % a, a);}
template<class T> T power(T x, T y) {T a,i; a=1; for(i=0; i<y; i++) a*=x; return a;}

#define N 100
int parent[N+2];
int node_rank[N+2];
void create_node(int n) {
    parent[n] = n;
    node_rank[n] = 1;
    return ;
}

int find_parent(int n) {
    if(parent[n]==n) return n;
    return parent[n] = find_parent(parent[n]);
}

void merge_node(int x, int y) {
    int a = find_parent(x);
    int b = find_parent(y);
    if(a==b) return ;
    if(node_rank[a]>node_rank[b]) {
        parent[b] = a;
        node_rank[a] = node_rank[a] + node_rank[b];
        node_rank[b] = 1;
    }else {
        parent[a] = b;
        node_rank[b] = node_rank[b] + node_rank[a];
        node_rank[a] = 1;
    }
    return ;
}

int main()
{
    int i, j, k, n, m, x, y, t;
    // total number of vertices
    sci(n);
    for(i=0; i<=n; i++) create_node(i); // m+1 nodes index starts at either 0 or 1
    // total number of edges
    sci(m);
    for(i=0; i<m; i++) {
        // two vertices of an edge
        scii(x, y);
        // joining the vertices
        merge_node(x, y);
    }
    for(i=0; i<=n; i++) {
        x = find_parent(i);
        printf("node: %d parent: %d rank: %d\n", i, parent[i], node_rank[i]);
    }
}
