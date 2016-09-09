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
    int value;
    NODE *next;
    void insertNode(int value); // Insert a node at the end of the list
    void insertAfter(int node, int value); // Insert a node after an existing node
    void insertBefore(int node, int value); // Insert a node before an existing node
    bool deleteNode(int value); // Delete a node from the list
    bool showAll(); // print all the values in the list
    void clearAll(); // Delete all list elements
}*root=NULL, *linklist;

// 'root' contains the first element of the list

void NODE::insertNode(int value) {
    if(root==NULL) {
        root = new NODE();
        root->next = NULL;
        root->value = value;
    }else {
        NODE *temp = root;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        NODE *newnode = new NODE();
        newnode->value = value;
        newnode->next = NULL;
        temp->next = newnode;
    }
    return ;
}

void NODE::insertBefore(int node, int value) {
    NODE *current = root;
    NODE *previous = NULL;
    while(current!=NULL && current->value!=node) {
        previous = current;
        current = current->next;
    }
    NODE *temp = new NODE();
    temp->value = value;
    temp->next = current;
    if(previous==NULL) {
        root = temp;
    }else {
        previous->next = temp;
    }
    return ;
}

void NODE::insertAfter(int node, int value) {
    NODE *temp = root;
    while(temp!=NULL && temp->value!=node) {
        temp = temp->next;
    }
    NODE *newnode = new NODE();
    newnode->value = value;
    newnode->next = temp->next;
    temp->next = newnode;
    return ;
}

bool NODE::deleteNode(int value) {
    NODE *previous = NULL;
    NODE *current = root;
    while(current!=NULL && current->value!=value) {
        previous = current;
        current = current->next;
    }
    if(current==NULL) {
        return false;
    }else if(current==root) {
        root = current->next;
        delete(current);
    }else {
        previous->next = current->next;
        delete(current);
    }
    return false;
}

bool NODE::showAll() {
    NODE *temp = root;
    int i=0;
    while(temp!=NULL) {
        if(i>0) printf(" ");
        i++;
        printf("%d", temp->value);
        temp = temp->next;
    }
    if(i>0) printf("\n");
    delete(temp);
    return true;
}

void NODE::clearAll() {
    NODE *temp = root;
    while(temp!=NULL) {
        NODE *del = temp;
        temp = temp->next;
        delete(del);
    }
    root = NULL;
    delete(temp);
    return ;
}

int main()
{
    int i, j, n, selector, value, node;
    /*** printf("Number of nodes: "); ***/
    scanf("%d", &n);
    /*** printf("The values:\n"); ***/
    while(n--) {
        scanf("%d", &value);
        linklist->insertNode(value);
    }
    /***
    printf("Enter 1 to insert a new node\nEnter 2 to delete a node\nEnter 3 to view all nodes\nEnter 4 to clear the list\nEnter 5 to insert after a node\nEnter 6 to insert before a node\nCommand: ");
    ***/
    while(scanf("%d", &selector)==1 && selector) {
        switch(selector) { // here selector is an integer used to access the different cases described below
        case 1:
            scanf("%d", &value);
            linklist->insertNode(value); // here 'value' is the value that is inserted at the end of the list
            break;
        case 2:
            scanf("%d", &value);
            linklist->deleteNode(value); // 'value' is deleted from the list if it exist and the function returns true, otherwise nothing happens and the function returns false
            break;
        case 3:
            linklist->showAll(); // print all the values in the list
            break;
        case 4:
            linklist->clearAll(); // delete all the values from the list
            break;
        case 5:
            scanf("%d %d", &node, &value);
            linklist->insertAfter(node, value); // here 'value' is going to be inserted after 'node'
            break;
        case 6:
            scanf("%d %d", &node, &value);
            linklist->insertBefore(node, value); // here 'value' is going to be inserted before 'node'
            break;
        }
    }
}
