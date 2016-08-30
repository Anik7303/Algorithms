#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10002
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int A[MAX];

struct NODE {
    int Sum, Max, Min;
}Tree[3*MAX];

void build(int L, int R, int index) {
    if(L==R) {
        Tree[index].Sum = A[L];
        Tree[index].Max = A[L];
        Tree[index].Min = A[L];
        return ;
    }
    int mid = (L+R)/2;
    build(L, mid, index*2);
    build(mid+1, R, index*2+1);
    Tree[index].Sum = Tree[index*2].Sum + Tree[index*2+1].Sum;
    Tree[index].Max = max(Tree[index*2].Max, Tree[index*2+1].Max);
    Tree[index].Min = min(Tree[index*2].Min, Tree[index*2+1].Min);
}

int query_sum(int L, int R, int index, int x, int y) {
    if(L>=x && R<=y) {
        return Tree[index].Sum;
    }
    int mid = (L+R)/2;
    int C1 = 0, C2 = 0;
    if(x<=mid) {
        C1 = query_sum(L, mid, index*2, x, y);
    }
    if(y>mid) {
        C2 = query_sum(mid+1, R, index*2+1, x, y);
    }
    return C1+C2;
}

int query_max(int L, int R, int index, int x, int y) {
    if(L>=x && R<=y) {
        return Tree[index].Max;
    }
    int mid = (L+R)/2;
    int C1 = INT_MIN, C2 = INT_MIN;
    if(x<=mid) {
        C1 = query_max(L, mid, index*2, x, y);
    }
    if(y>mid) {
        C2 = query_max(mid+1, R, index*2+1, x, y);
    }
    return max(C1, C2);
}

int query_min(int L, int R, int index, int x, int y) {
    if(L>=x && R<=y) {
        return Tree[index].Min;
    }
    int mid = (L+R)/2;
    int C1 = INT_MAX, C2 = INT_MAX;
    if(x<=mid) {
        C1 = query_min(L, mid, index*2, x, y);
    }
    if(y>mid) {
        C2 = query_min(mid+1, R, index*2+1, x, y);
    }
    return min(C1, C2);
}

int main()
{
    int i, j, n, x, y, q;
    while(scanf("%d", &n)==1 && n) {
        for(i=0; i<n; i++) {
            scanf("%d", &A[i]);
        }
        build(0, n-1, 1);/*
        for(i=0; i<n*3; i++) {
            printf("Tree[%d]-> Sum: %d Max: %d Min: %d\n", i, Tree[i].Sum, Tree[i].Max, Tree[i].Min);
        }*/
        printf("Query Number: ");
        scanf("%d", &q);
        for(i=0; i<q; i++) {
            scanf("%d %d", &x, &y);
            printf("Sum: %d Max: %d Min: %d\n", query_sum(1, n, 1, x, y), query_max(1, n, 1, x, y), query_min(1, n, 1, x, y));
        }
    }
}
