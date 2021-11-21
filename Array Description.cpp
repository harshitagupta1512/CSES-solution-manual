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
    ll m;
    cin >> m;
    vector<ll> x(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> x[i];

    //1-based indexing
    vector<ll> dpPrev(m + 1);
    vector<ll> dpNext(m + 1);
    dpPrev[0] = -1;
    dpNext[0] = -1;

    if (x[1] == 0) {
        //unknown
        for (ll v = 1; v <= m; v++)
            dpPrev[v] = 1;
    } else {
        for (ll v = 1; v <= m; v++)
            dpPrev[v] = 0;

        dpPrev[x[1]] = 1;
    }


    for (ll xIndex = 2; xIndex <= n; xIndex++) {

        if (x[xIndex] == 0) {
            //unknown
            for (ll v = 1; v <= m; v++) {
                if (m == 1) {
                    dpNext[v] = dpPrev[v] % modValue;
                    continue;
                }
                if (v == 1)
                    dpNext[v] = dpPrev[v] % modValue + dpPrev[v + 1] % modValue;
                else if (v == m)
                    dpNext[v] = dpPrev[v] % modValue + dpPrev[v - 1] % modValue;
                else
                    dpNext[v] = dpPrev[v - 1] % modValue + dpPrev[v] % modValue + dpPrev[v + 1] % modValue;
            }
        } else {
            for (ll v = 1; v <= m; v++)
                dpNext[v] = 0;

            if (m == 1)
                dpNext[x[xIndex]] = dpPrev[x[xIndex]] % modValue;
            else if (x[xIndex] == 1)
                dpNext[x[xIndex]] = (dpPrev[x[xIndex]] % modValue + dpPrev[x[xIndex] + 1]) % modValue;
            else if (x[xIndex] == m)
                dpNext[x[xIndex]] = dpPrev[x[xIndex]] % modValue + dpPrev[x[xIndex] - 1] % modValue;
            else
                dpNext[x[xIndex]] = dpPrev[x[xIndex] - 1] % modValue + dpPrev[x[xIndex]] % modValue +
                                    dpPrev[x[xIndex] + 1] % modValue;
        }
        dpPrev = dpNext;

    }

    ll ans = 0;
    for (ll v = 1; v <= m; v++)
        ans = ans + dpPrev[v] % modValue;

    cout << ans % modValue << endl;

}