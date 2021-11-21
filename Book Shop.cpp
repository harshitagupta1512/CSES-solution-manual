#include <bits/stdc++.h>
#include <istream>
#include <algorithm>
#include <functional>

#define modValue 1000000007
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> price(n + 1);
    vector<ll> pages(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    for (int i = 1; i <= n; i++)
        cin >> pages[i];

    price[0] = 0;
    pages[0] = 0;

    //To find - maximum number of pages in price at most x
    //knapsack problem
    //dp[i][j] - maximum number of pages achievable with price at most j and books 1, 2, 3 ... i

    int currRow = 0;
    vector<ll> dpPrev(x + 1);
    vector<ll> dpNext(x + 1);
    for (int i = 0; i <= x; i++)
        dpPrev[i] = 0;

    dpNext[0] = 0;

    for (int i = 1; i <= n; i++) {
        currRow = i;
        for (int j = 1; j <= x; j++) {
            dpNext[j] = dpPrev[j];
            if (j - price[currRow] >= 0)
                dpNext[j] = max((dpPrev[j - price[currRow]] + pages[currRow]), dpPrev[j]);
        }
        dpPrev = dpNext;
    }

    cout << dpPrev[x] << endl;
}