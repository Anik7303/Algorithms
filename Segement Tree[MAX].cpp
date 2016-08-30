#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 100
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define SET(x, y) memset(x, y, sizeof(x))
#define MAXF(x, y) (x>y? x: y)
#define MINF(x, y) (x<y? x: y)

int A[MAX], Tree[MAX*3];

void build(int L, int R, int Index) {
    if(L==R) {
        Tree[Index] = A[L];
        return ;
    }
    int mid = (L+R)/2;
    build(L, mid, 2*Index);
    build(mid+1, R, 2*Index+1);
    Tree[Index] = MAXF(Tree[Index*2], Tree[Index*2+1]);
}

int query_max(int L, int R, int Index, int x, int y) {
    if(L>=x && R<=y) return Tree[Index];
    int mid = (L+R)/2;
    int C1 = 0, C2 = 0;
    if(x<=mid) {
        C1 = query_max(L, mid, 2*Index, x, y);
    }
    if(y>mid) {
        C2 = query_max(mid+1, R, 2*Index+1, x, y);
    }
    return MAXF(C1, C2);
}

void update(int L, int R, int Index, int x, int Value) {
    if(L==R) {
        Tree[Index] = Value;
        return ;
    }
    int mid = (L+R)/2;
    if(x<=mid) {
        update(L, mid, 2*Index, x, Value);
    }else {
        update(mid+1, R, 2*Index+1, x, Value);
    }
    Tree[Index] = MAXF(Tree[Index*2], Tree[Index*2+1]);
}

int main()
{
    int i, j, n, x, y, q;
    while(scanf("%d",&n)==1 && (n>0 && n<100)) {
        SET(A, 0);
        for(i=0; i<n; i++) {
            scanf("%d", &A[i]);
        }
        build(0, n-1, 1);
        int q;
        printf("Number of Query's: ");
        scanf("%d", &q);
        for(j=0; j<q; j++) {
            cout << "Update[x,y]: ";
            scanf("%d %d", &x, &y);
            update(1, n, 1, x, y);
            cout << "MAX[x,y]: ";
            scanf("%d %d", &x, &y);
            cout << "MAX: " << query_max(1, n, 1, x, y) << endl;
        }
    }
}

