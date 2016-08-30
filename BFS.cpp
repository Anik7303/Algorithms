#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class NODE {
public:
    vector<int> Adj;
    int parent, distance, visited;
};

void bfs(vector<NODE> &G, int source) {
    queue<int> Q;
    int top, x, i;
    Q.push(source);
    G[source].visited = 1;
    G[source].parent = -1;
    G[source].distance = 0;
    while(!Q.empty()) {
        top = Q.front();
        Q.pop();
        for(i=0; i<G[top].Adj.size(); i++) {
            x = G[top].Adj[i];
            if(G[x].visited==0) {
                G[x].distance = G[top].distance+1;
                G[x].visited = 1;
                Q.push(x);
            }
        }
    }
}

int main()
{
    freopen("bfs.txt", "r", stdin);
    int i, j, k, l, q, n, x, y, source;
    vector<NODE> V;
    printf("Node number: ");
    scanf("%d", &n);
    for(i=0; i<=n; i++) {
        NODE temp;
        V.push_back(temp);
    }
    printf("Edges: ");
    scanf("%d", &q);
    for(i=0; i<q; i++) {
        scanf("%d %d", &x, &y);
        V[x].Adj.push_back(y);
        V[y].Adj.push_back(x);
    }/**/
    printf("Vector size: %d\n", V.size());
    for(i=0; i<V.size(); i++) {
        printf("%d: ", i);
        for(j=0; j<V[i].Adj.size(); j++) {
            printf("%d ", V[i].Adj[j]);
        }
        printf("\n");
    }/**/
    printf("Source: ");
    scanf("%d", &source);
    for(i=0; i<V.size(); i++) {
        ///V[i].distance = 0;
        V[i].visited = 0;
    }
    printf("\n");
    bfs(V, source);
    for(i=1; i<V.size(); i++) {
        printf("%d: %d\n", i, V[i].distance);
    }
}

