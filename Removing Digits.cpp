#include <bits/stdc++.h>
#include <istream>
#include <algorithm>
#include <functional>

#define modValue 1000000007
using namespace std;
typedef long long int ll;

ll solve(ll n, vector<ll> &dp) {

    dp[n] = INT64_MAX;
    ll num = n;
    vector<ll> d;
    while (num != 0) {
        d.push_back(num % 10);
        num = num / 10;
    }
    int numDigits = d.size();
    for (int i = 0; i < numDigits; i++) {
        if (d[i] == 0)
            continue;
        ll x = n - d[i];
        if (dp[x] != -1)
            dp[n] = min(dp[n], dp[x] + 1);
        else
            dp[n] = min(dp[n], solve(x, dp) + 1);
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    vector<ll> dp(n + 1);

    for (int i = 0; i < n; i++)
        dp[i] = -1;

    dp[0] = 0;

    if (n >= 9) {
        for (int i = 1; i <= 9; i++)
            dp[i] = 1;
    } else {
        for (int i = 1; i <= n; i++)
            dp[i] = 1;

    }

    ll ans = solve(n, dp);
    cout << ans << endl;
}