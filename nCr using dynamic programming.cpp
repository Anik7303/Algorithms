#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define N 100
int nCr[N+2][N+2];

int nCr_function(int n, int r) {
    if(r==1) return n;
    if(n==r) return 1;
    if(nCr[n][r]!=-1) return nCr[n][r];
    return nCr[n][r] = nCr_function(n-1, r) + nCr_function(n-1, r-1);
}

int main()
{
    int n, r;
    memset(nCr, -1, sizeof(nCr));
    while(scanf("%d %d", &n, &r)==2 && n>=0 && r>=0) {
        printf("%dC%d = %d\n", n, r, nCr_function(n, r));
    }
}
