#include<iostream>
using namespace std;

typedef long long ll;
ll BigMod(ll b,ll p,ll m) {
    ll res=1;
    while(p) {
        if(p&1) {
            res=(res*b)%m;
        }
        p/=2;
        b=(b*b)%m;
    }
    return res;
}
int main() {
    cout<<BigMod(2,1000000000,1000000007);
}