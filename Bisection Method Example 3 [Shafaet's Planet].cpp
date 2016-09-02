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

#define N 1000
int edge_weight[N+2];
mci _map;

struct NODE {
    int visited;
    char name;
    vector<pii>edge;
};

void dfs_visit(vector<NODE>&graph, int source, int weight) {
    int i, x, w, n;
    n = graph[source].edge.size();
    for(i=0; i<n; i++) {
        x = graph[source].edge[i].first;
        w = graph[source].edge[i].second;
        if(graph[x].visited==0 && w<=weight) {
            graph[x].visited = 1;
            dfs_visit(graph, x, weight);
        }
    }
    return ;
}

bool dfs(vector<NODE>&graph, int source, int destination, int weight) {
    int i, x, w, n;
    n =graph.size();
    for(i=0; i<n; i++) {
        graph[i].visited = 0;
    }
    graph[source].visited = 1;
    n = graph[source].edge.size();
    for(i=0; i<n; i++) {
        x = graph[source].edge[i].first;
        w = graph[source].edge[i].second;
        if(!graph[x].visited && w<=weight) {
            graph[x].visited = 1;
            dfs_visit(graph, x, weight);
        }
    }
    if(graph[destination].visited) return true;
    return false;
}

bool bfs(vector<NODE>&graph, int source, int destination, int weight) {
    int i, j, x, w, n, top;
    qi Q;
    n = graph.size();
    for(i=0; i<n; i++) graph[i].visited = 0;
    graph[source].visited = 1;
    pu(Q, source);
    while(!Q.empty()) {
        top = Q.front();
        Q.pop();
        n = graph[top].edge.size();
        for(i=0; i<n; i++) {
            x = graph[top].edge[i].first;
            w = graph[top].edge[i].second;
            if(!graph[x].visited && w<=weight) {
                pu(Q, x);
                graph[x].visited = 1;
            }
        }
    }
    return graph[destination].visited&1;
}

int calculate(vector<NODE>&graph, int source, int destination, int high) {
    int low, mid, value;
    value = low = 0;
    while(low<=high) {
        mid = (low+high)/2;
        //if(dfs(graph, source, destination, mid)) { /// finding path using DFS
        if(bfs(graph, source, destination, mid)) { /// finding path using BFS
            high = mid - 1;
            value = mid;
        }else {
            low = mid + 1;
        }
    }
    return value;
}

int binary_search_down(int value, int high) {
    int low, mid, index;
    low = 0;
    index = -1;
    while(low<=high) {
        mid = (low+high)/2;
        if(edge_weight[mid]>value) {
            high = mid-1;
        }else {
            low = mid+1;
            index = mid;
        }
    }
    if(~index) return edge_weight[index];
    return index;
}

int main()
{
    //fr("Bisection Method Example 3 [Shafaet's Planet].txt");
    int i, j, w, e, mw, n;
    char c, x, y;
    NODE temp;
    vector<NODE>graph;
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
        mw = 0;
        for(i=0; i<e; i++) {
            scc(x);
            scc(y);
            sci(w);
            edge_weight[i] = w;
            mw = max(mw, w);
            int p = _map[x];
            int q = _map[y];
            pb(graph[p].edge, mp(q, w));
            pb(graph[q].edge, mp(p, w));
        }
        // Source vertex name
        scc(x);
        // Destination vertex name
        scc(y);
        printf("source: %c destination: %c ", x, y);
        int res = calculate(graph, _map[x], _map[y], mw);
        //printf("calculated res: %d\n", res);
        sort(edge_weight, edge_weight+e);

        pfcs("edges:");
        for(i=0; i<e; i++) {
            pfsp();
            pfi(edge_weight[i]);
        }
        pfn();

        res = binary_search_down(res, e);
        printf("minimum weight: %d\n", res);
        acl(_map);
        acl(graph);
    }
}

