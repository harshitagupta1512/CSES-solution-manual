#include <bits/stdc++.h>
#include <istream>
#include <algorithm>
#include <functional>

#define modValue 1000000007
using namespace std;
typedef long long int ll;


ll solve(ll row, ll col, vector<vector<ll>> &dp) {

    if (dp[row][col] != -1)
        return dp[row][col] % modValue;

    if (dp[row - 1][col] == -1)
        dp[row - 1][col] = solve(row - 1, col, dp) % modValue;

    if (dp[row][col - 1] == -1)
        dp[row][col - 1] = solve(row, col - 1, dp) % modValue;

    dp[row][col] = dp[row - 1][col] % modValue + dp[row][col - 1] % modValue;

    return dp[row][col] % modValue;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    char grid[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    //dp[i][j] = number of ways to reach (i, j) from (0, 0)
    // to find = dp[n-1][n-1]

    vector<vector<ll>> dp(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i].push_back(0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*')
                dp[i][j] = 0; // one can never reach a square with a trap
            else
                dp[i][j] = -1; //Not found yet
        }
    int index = n;

    for (int i = 0; i < n; i++)
        if (dp[i][0] == 0) {
            index = i;
            break;
        }
    for (int i = 0; i < index; i++)
        dp[i][0] = 1;
    for (int i = index; i < n; i++)
        dp[i][0] = 0;

    index = n;

    for (int j = 0; j < n; j++)
        if (dp[0][j] == 0) {
            index = j;
            break;
        }
    for (int j = 0; j < index; j++)
        dp[0][j] = 1;
    for (int j = index; j < n; j++)
        dp[0][j] = 0;


    ll ans = solve(n - 1, n - 1, dp);

    /*  for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++)
              cout << dp[i][j] << " ";
          cout << endl;
      }
      */
    cout << ans % modValue << endl;

}