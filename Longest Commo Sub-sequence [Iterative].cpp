#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define N 10100
int b[N][N], c[N][N];

int LCS_length(string X, string Y) {
    int m, n, i, j, p, q;
    m = X.size(), n = Y.size();
    for(i=0; i<=m; i++) {
        b[i][0] = 0;
    }
    for(j=1; j<=n; j++) {
        b[0][j] = 0;
    }
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            p = i-1, q = j-1;
            if(X[p]==Y[q]) {
                b[i][j] = b[p][q] + 1;
                c[i][j] = 1;
            }else if(b[i][q]>b[p][j]) {
                b[i][j] = b[i][q];
                c[i][j] = 2;
            }else {
                b[i][j] = b[p][j];
                c[i][j] = 0;
            }
        }
    }
    return b[m][n];
}

void LCS_subsequence(string X, string Y) {
    int m, n, i;
    m = X.size(), n = Y.size();
    i = 0;
    char ch[m+n];
    while(m && n) {
        if(c[m][n]==1) {
            ch[i] = X[m-1];
            i++;
            m--, n--;
        }else if(c[m][n]==0) {
            m--;
        }else {
            n--;
        }
    }
    ch[i] = '\0';
    cout << "Subsequence: ";
    for(i--; i>=0; i--) {
        cout << ch[i];
    }
    cout << endl;
}

int main()
{
    string X, Y;
    int length, m, n;
    while(getline(cin, X)) {
        getline(cin, Y);
        m = X.size();
        n = Y.size();
        length = LCS_length(X, Y);
        cout << "LENGTH: " << length << endl;
        LCS_subsequence(X, Y);
    }
}
