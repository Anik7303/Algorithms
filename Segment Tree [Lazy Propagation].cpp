#include <iostream>
#include <cstdio>
#include <cstdlib>
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
#include <sstream>
#include <fstream>
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
typedef deque<int> di;
typedef deque<ll> dl;
typedef deque<char> dc;
typedef deque<string> ds;

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

template<class T> T maxT(T a, T b) {return a>b ? a: b;}
template<class T> T gcd(T a,T b) {return a==0 ? b : gcd(b % a, a);}
template<class T> T power(T x, T y) {T a,i; a=1; for(i=0; i<y; i++) a*=x; return a;}

#define N 10002
int arr[N];
struct node {
    int Sum, Max, Min;
    int Propagate;
}tree[N*3];

void build(int l, int r, int idx) {
    tree[idx].Propagate = 0;
    if(l==r) {
        tree[idx].Sum = arr[l];
        tree[idx].Max = arr[l];
        tree[idx].Min = arr[l];
        return ;
    }
    int left = idx*2;
    int right = left+1;
    int mid = (l+r)/2;
    build(l, mid, left);
    build(mid+1, r, right);
    tree[idx].Sum = tree[left].Sum + tree[right].Sum;
    tree[idx].Max = max(tree[left].Max, tree[right].Max);
    tree[idx].Min = min(tree[left].Min, tree[right].Min);
    return ;
}

node query(int l, int r, int idx, int i, int j, int carry=0) {
    if(l>=i && r<=j) {
        node temp;
        temp.Sum = tree[idx].Sum + (carry * (r-l+1));
        temp.Max = tree[idx].Max + carry;
        temp.Min = tree[idx].Min + carry;
        return temp;
    }
    node q1, q2;
    q1.Sum = q2.Sum = 0;
    q1.Max = q2.Max = IMIN;
    q1.Min = q2.Min = IMAX;
    q1.Propagate = q2.Propagate = 0;
    int mid = (l+r)/2;
    if(i<=mid) q1 = query(l, mid, idx*2, i, j, carry+tree[idx].Propagate);
    if(j>mid) q2 = query(mid+1, r, idx*2+1, i, j, carry+tree[idx].Propagate);
    node temp;
    temp.Sum = q1.Sum + q2.Sum;
    temp.Max = max(q1.Max, q2.Max);
    temp.Min = min(q1.Min, q2.Min);
    return temp;
}

void update(int l, int r, int idx, int i, int j, int val) {
    if(l>=i && r<=j) {
        tree[idx].Sum = tree[idx].Sum + (val * (r-l+1));
        tree[idx].Propagate = tree[idx].Propagate + val;
        tree[idx].Max = tree[idx].Max + val;
        tree[idx].Min = tree[idx].Min + val;
        return ;
    }
    int left = idx*2;
    int right = left+1;
    int mid = (l+r)/2;
    if(i<=mid) update(l, mid, left, i, j, val);
    else update(mid+1, r, right, i, j, val);
    tree[idx].Sum = tree[left].Sum + tree[right].Sum + (tree[idx].Propagate * (r-l+1));
    tree[idx].Max = max(tree[left].Max, tree[right].Max);
    tree[idx].Min = min(tree[left].Min, tree[right].Min);
    return ;
}

void show(int n) {
    for(int i=1; i<=n; i++) {
        printf("node: %d sum: %d min: %d max: %d propagate: %d\n", i, tree[i].Sum, tree[i].Min, tree[i].Max, tree[i].Propagate);
    }
    return ;
}

int main()
{
    int i, j, k, n, x, y, q, t;
    node  res;
    while(sci(n)==1 && n) {
        for(i=0; i<n; i++) sci(arr[i]);
        build(0, n-1, 1);
        sci(q);
        //show(n*3);
        for(i=0; i<q; i++) {
            sci(j);
            switch(j) {
            case 1:
                scii(x, y);
                res = query(1, n, 1, x, y);
                printf("sum: %d min: %d max: %d\n", res.Sum, res.Min, res.Max);
                //show(n*3);
                break;
            case 2:
                scii(x, y);
                sci(k);
                update(1, n, 1, x, y, k);
                //show(n*3);
                break;
            }
        }
    }
}
