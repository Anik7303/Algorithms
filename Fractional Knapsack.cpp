#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

#define fr(x) freopen(x, "r", stdin)
#define fc(x) fclose(x)

int knapsack_profit(int weight[], int price[], int knapsack, int n) {
    map<int, int> products;
    map<int, int>::iterator it;
    int i, j, w, profit, unit_price[n];
    for(i=0; i<n; i++) {
        unit_price[i] = price[i]/ weight[i];
        products[unit_price[i]] = weight[i];
    }
    sort(unit_price, unit_price+n);
    i = n - 1;
    profit = 0;
    while(knapsack>0 && i>=0) {
        it = products.find(unit_price[i]);
        if(it!=products.end()) {
            w = it->second;
            if(w<=knapsack) {
                profit = profit + (w * unit_price[i]);
                knapsack = knapsack - w;
            }else {
                profit = profit + (knapsack * unit_price[i]);
                knapsack = 0;
            }
        }
        i--;
    }
    products.clear();
    return profit;
}

int main()
{
    fr("knapsack_input.txt");
    int i, j, n, knapsack;
    scanf("%d %d", &n, &knapsack);
    int weight[n], price[n];
    for(i=0; i<n; i++) {
        scanf("%d %d", &weight[i], &price[i]);
    }
    printf("Total Profit: %d\n", knapsack_profit(weight, price, knapsack, n));
    fc(stdin);
}
