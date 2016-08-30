#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define N 10000
int B[N][N], C[N][N];

int LCS_length(string X, string Y, int m, int n, int p, int q) {
    /*int p, q;
    p = X.size(), q = Y.size();
    printf("P: %d Q: %d\n", p, q);*/
    if(m>p && n>=q) {
        printf("return: %d\n", B[m-1][n]);
        return B[m-1][n];
    }
    if(m>p) {
        m = 1;
        n++;
        printf("m: %d n: %d\n", m, n);
        //cout << endl;
    }
    if(X[m-1]==Y[n-1]) {
        C[m][n] = 1;
        B[m][n] = B[m-1][n-1] + 1;
        printf("C[%d][%d]: %d\tB[%d][%d]{=%d}: B[%d][%d]{=%d} + 1\n", m, n, C[m][n], m, n, B[m][n], m-1, n-1, B[m-1][n-1]);
        //printf("%d[%d]\t", B[m][n], C[m][n]);
    }else if(B[m-1][n]>B[m][n-1]) {
        C[m][n] = 2;
        B[m][n] = B[m-1][n];
        printf("C[%d][%d]: %d\tB[%d][%d]{=%d}: B[%d][%d]{=%d}\n", m, n, C[m][n], m, n, B[m][n], m-1, n, B[m-1][n]);
        //printf("%d[%d]\t", B[m][n], C[m][n]);
    }else {
        C[m][n] = 0;
        B[m][n] = B[m][n-1];
        printf("C[%d][%d]: %d\tB[%d][%d]{=%d}: B[%d][%d]{=%d}\n", m, n, C[m][n], m, n, B[m][n], m, n-1, B[m][n-1]);
        //printf("%d[%d]\t", B[m][n], C[m][n]);
    }
    printf("Call: m:%d n:%d p: %d q: %d\n", m+1, n, p, q);
    return LCS_length(X, Y, m+1, n, p, q);
}

void LCS_subsequence(string X, int m, int n) {
    if(m==0 || n==0)    return ;
    if(C[m][n]==1) {
        LCS_subsequence(X, m-1, n-1);
        cout << X[m-1];
    }else if(C[m][n]==2) {
        LCS_subsequence(X, m-1, n);
    }else {
        LCS_subsequence(X, m, n-1);
    }
}

int main()
{
    freopen("LCS.txt", "r", stdin);
    string X, Y;
    while(getline(cin, X)) {
        getline(cin, Y);
        printf("START:\n");
        printf("X.size(): %d Y.size(): %d\n", X.size(), Y.size());
        cout << "Length: " << LCS_length(X, Y, 1, 1, X.size(), Y.size()) << endl;
        cout << "Sub-sequence: ";
        LCS_subsequence(X, X.size(), Y.size());
        cout << endl;
        for(int i=0; i<=Y.size(); i++) {
            for(int j=0; j<=X.size(); j++) {
                printf("%d[%d] ", B[j][i], C[j][i]);
            }
            cout << endl;
        }
        cout <<endl;
        printf("END\n");
    }
    fclose(stdin);
}
