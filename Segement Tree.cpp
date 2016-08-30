#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 100
#define SET(x, y) memset(x, y, sizeof(x))

int A[MAX], Tree[MAX*3];

void build(int L, int R, int Index) {
    if(L==R) {
        Tree[Index] = A[L];
        return ;
    }
    int mid = (L+R)/2;
    build(L, mid, 2*Index);
    build(mid+1, R, 2*Index+1);
    Tree[Index] = Tree[Index*2] + Tree[Index*2+1];
}

int query(int L, int R, int Index, int x, int y) {
    if(L>=x && R<=y) {
        cout << "RE: " << Tree[Index] << endl;
        return Tree[Index];
    }
    int mid = (L+R)/2;
    int C1 = 0, C2 = 0;
    if(x<=mid) {
        C1 = query(L, mid, 2*Index, x, y);
        cout << "C1: " << C1 << endl;
    }
    if(y>mid) {
        C2 = query(mid+1, R, 2*Index+1, x, y);
        cout << "C2: " << C2 << endl;
    }
    cout << "C1+C2: " << C1+C2 << endl;
    return C1+C2;
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
    Tree[Index] = Tree[2*Index] + Tree[2*Index+1];
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
        for(i=0; i<n*3; i++) {
            printf("Tree[%d] : %d\n", i, Tree[i]);
        }
        int q;
        printf("Number of Query's: ");
        scanf("%d", &q);
        for(j=0; j<q; j++) {
            scanf("%d %d", &x, &y);
            cout << "SUM: " << query(1, n, 1, x, y) << endl;
        }
    }
}

