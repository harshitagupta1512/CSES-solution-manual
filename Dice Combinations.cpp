#include <bits/stdc++.h>
#include <istream>
#include <algorithm>
#include <functional>

#define modValue 1000000007
using namespace std;
typedef long long int ll;

ll solve(ll n, vector<ll> &dp) {

    ll ans = 0;

    if (n == 0)
        return 0;

    if (n >= 1 && n <= 6)
        ans++;

    for (int i = 1; i <= 6; i++) {
        if (n - i < 1)
            continue;

        if (dp[n - i] != -1)
            ans = ans % modValue + dp[n - i] % modValue;
        else
            ans = ans % modValue + solve(n - i, dp) % modValue;
    }

    dp[n] = ans % modValue;
    return ans % modValue;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> dp(n + 1);
    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    ll ans = solve(n, dp);
    cout << dp[n] << endl;
}