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
    int distance, visited;
    string name;
    vector<pii>edge;
};

void dijkstra_algorithm(vector<NODE>&graph, int source) {
    int i, j, x, y, sz, top;
    qi Q;
    // source is pushed to queue for proccessing
    pu(Q, source);
    // source's distance is 0
    graph[source].distance = 0;
    // main proccess
    while(!Q.empty()) { // loop run's until the queue is empty
        top = Q.front(); // the top value of queue is fetched
        Q.pop(); // the top value is popped from queue
        if(!graph[top].visited) { // checked if the vertex is visited or not
            sz = graph[top].edge.size(); // the number of edges from that vertex
            graph[top].visited = 1;
            for(i=0; i<sz; i++) {
                x = graph[top].edge[i].first; // the end point of the edge
                y = graph[top].distance + graph[top].edge[i].second; // the distance for that edge
                if(graph[x].distance>y) {
                    graph[x].distance = y;
                    // if the distance is change then the ending vertex have to be proccess again
                    graph[x].visited = 0;
                }
                pu(Q, x);
            }
        }
        graph[top].visited = 1;
    }
    return ;
}


int main()
{
    int i, j, k, n, e, x, y, w, source;
    vector<NODE> graph;
    msi _map;
    NODE temp;
    string s;
    /// Number of vertices in the graph
    sci(n);
    gt();
    temp.distance = 0;
    temp.visited = 0;
    //temp.name = "\0";
    pb(graph,temp);
    for(i=0; i<n; i++) {
        //scs(s);
        temp.distance = IMAX;
        temp.visited = 0;
        //temp.name = s;
        pb(graph, temp);
    }
    /*
    for(i=0; i<=n; i++) {
        printf("Graph[%d]-> name: %s distance: %d visited: %d\n", i, graph[i].name.c_str(), graph[i].distance, graph[i].visited);
    }
    */
    /// The vertices are numbered from 1 to n
    /// Number of edges
    sci(e);
    for(i=0; i<e; i++) {
        sci(x); // starting vertex
        sci(y); // ending vertex
        sci(w); // edge weight
        pb(graph[x].edge, mp(y, w));
        pb(graph[y].edge, mp(x, w));
    }
    /// details of every edge
    /*
    for(i=0; i<=n; i++) {
        for(j=0; j<graph[i].edge.size(); j++) {
            printf("%d->%d: %d\n", i, graph[i].edge[j].first, graph[i].edge[j].second);
        }
    }
    */
    /// Source vertex
    sci(source);
    dijkstra_algorithm(graph, source);
    /// details of the graph after appling the dijkstra algorithm
    for(i=0; i<=n; i++) {
        printf("Graph[%d]-> name: %s distance: %d visited: %d\n", i, graph[i].name.c_str(), graph[i].distance, graph[i].visited);
    }
}
