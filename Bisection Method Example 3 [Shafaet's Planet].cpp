#include <iostream>
#include <cstdio>
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

struct NODE {
    int visited;
    char name;
};

int n;
mci _map;
vector<NODE> graph;
int weight[27][27];
bool edges[27][27], arr[27][27];

void dfs_visit(int x) {
    for(int i=0; i<n; i++) {
        if(arr[x][i]==true && graph[i].visited==0) {
            graph[i].visited = 1;
            dfs_visit(i);
        }
    }
    return ;
}

bool dfs(int s, int d) {
    for(int i=0; i<n; i++) {
        graph[i].visited = 0;
    }
    graph[s].visited = 1;
    for(int i=0; i<n; i++) {
        if(arr[s][i]==true && graph[i].visited==0) {
            graph[i].visited = 1;
            dfs_visit(i);
        }
    }
    if(graph[d].visited==1) return true;
    return false;
}

int calculate(int s, int d, int high) {
    int low, mid, value;
    low = 0;
    while(low<high) {
        mid = (low+high)/2;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                arr[i][j] = edges[i][j];
                if(arr[i][j]==true && weight[i][j]>mid) {
                    arr[i][j] = false;
                }
            }
        }
        bool res = dfs(s, d);
        if(res==true) {
            high = mid-1;
            value = mid;
        }else {
            low = mid+1;
        }

    }
    return value;
}

int binary_search_down(int ax[], int value, int x) {
    int low, high, mid, index;
    index = low = 0;
    high = x;
    while(low<high) {
        mid = (low+high)/2;
        if(ax[mid]>value) {
            high = mid-1;
        }else {
            low = mid+1;
            index = mid;
        }
    }
    return index;
}

int main()
{
    fr("C:\\Users\\Anik\\Desktop\\input.txt");
    int i, j, w, e, mw;
    char c, x, y;
    NODE temp;
    ///pfcs("Number of vertex: ");
    while(sci(n)==1) {
        for(i=0; i<n; i++) {
            scc(c);
            _map[c] = i;
            temp.name = c;
            pb(graph, temp);
        }
        ///pfcs("Number of edge: ");
        sci(e);
        int edge_weight[e+2];
        mw = 0;
        mset(edges, 0);
        mset(weight, 0);
        for(i=0; i<e; i++) {
            scc(x);
            scc(y);
            sci(w);
            edge_weight[i] = w;
            mw = max(mw, w);
            int p = _map[x];
            int q = _map[y];
            weight[p][q] = w;
            weight[q][p] = w;
            edges[p][q] = edges[q][p] = true;
        }
        ///pfcs("Source: ");
        scc(x);
        ///pfcs("Destination: ");
        scc(y);
        ///printf("source: %c destination: %c\n", x, y);
        int res = calculate(_map[x], _map[y], mw);
        sort(edge_weight, edge_weight+e);
        res = binary_search_down(edge_weight, res, e);
        printf("Minimum weight: %d\n", edge_weight[res]);
        acl(_map);
        acl(graph);
    }
}

