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
    vector<ll> coins(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> coins[i];

    coins[0] = 0;


    /*dp[i][j] = number of distinct ordered ways use first i coins (in an ordered way) to make sum j
    final answer = dp[n][x]
    dp[0][0] = 1
    dp[0][j] = 0
    dp[i][0] = 1
    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[j]]
    For space complexity concerns we take only two rows at a time
    */

    ll dp[2][x + 1];
    for (int j = 0; j <= x; j++)
        dp[0][j] = 0;

    dp[0][0] = 1;
    dp[1][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[1][j] = dp[0][j] % modValue;
            if (j - coins[i] >= 0)
                dp[1][j] += dp[1][j - coins[i]] % modValue;
        }

        ll temp = 0;
        for (int j = 0; j <= x; j++) {
            temp = dp[0][j] % modValue;
            dp[0][j] = dp[1][j] % modValue;
            dp[1][j] = temp % modValue;
        }
    }

    cout << dp[0][x] % modValue << endl;
}