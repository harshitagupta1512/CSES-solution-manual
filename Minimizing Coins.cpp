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

    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<ll> dp(x + 1);
    for (int i = 0; i <= x; i++)
        dp[i] = -1;

    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        ll answer = INT64_MAX;

        for (int j = 0; j < n; j++) {
            if (i - coins[j] < 0)
                continue;

            if (dp[i - coins[j]] == -1)
                continue;

            answer = min(answer, dp[i - coins[j]] + 1);
        }

        if (answer == INT64_MAX)
            dp[i] = -1;
        else
            dp[i] = answer;
    }

    cout << dp[x] << endl;

}