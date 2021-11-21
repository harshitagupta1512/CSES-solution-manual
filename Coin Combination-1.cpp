#include <bits/stdc++.h>
#include <istream>
#include <algorithm>
#include <functional>

#define modValue 1000000007
using namespace std;
typedef long long int ll;

ll solve(ll n, ll x, vector<ll> &coins, vector<ll> &dp) {

    dp[x] = 0;
    for (int i = 0; i < n; i++) {
        ll y = x - coins[i];
        if (y < 0)
            continue;

        if (dp[y] == -1)
            dp[x] += solve(n, y, coins, dp) % modValue;
        else
            dp[x] += dp[y] % modValue;

    }
    return dp[x] % modValue;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<ll> dp(x + 1);
    for (int i = 0; i <= x; i++)
        dp[i] = -1;

    dp[0] = 1;
    ll answer = solve(n, x, coins, dp);
    cout << dp[x] % modValue << endl;
}