#include <bits/stdc++.h>
#include <istream>
#include <algorithm>
#include <functional>

#define mod 1000000007
using namespace std;
typedef long long int ll;

int globalCount = 0;

ll solve(ll height1, ll height2, vector<vector<ll>> &dp)
{

    if (height1 == 0 && height2 == 0)
        return 1;

    if (height1 < height2)
    {
        dp[height1][height2] = solve(height2, height1, dp);
        return dp[height1][height2];
    }

    if (dp[height1][height2] != -1)
    {
        return dp[height1][height2];
    }

    // height1 <= height2

    ll ans = 0;

    // block length = 1;

    for (ll i = 1; i <= height1; ++i)
    {
        ll subans = solve(height1 - i, height2, dp);
        ans = ans + subans;
        ans = ans % mod;
    }

    if (height2 != height1)
    {
        dp[height1][height2] = ans;
        return ans;
    }

    for (ll i = 1; i <= height1; ++i)
    {
        ll subans = solve(height1 - i, height2 - i, dp);
        ans = ans + subans;
        ans = ans % mod;
    }

    dp[height1][height2] = ans;
    return ans;
}

ll solve2(ll h1, ll h2, vector<vector<ll>> &dp)
{
    dp[0][0] = 1;
    /*  dp[1][0] = 1;
        dp[0][1] = 1;
        dp[2][0] = 2;
        dp[0][2] = 2;
        dp[3][0] = 4;
        dp[0][3] = 4;
    */
}

void printDP(vector<vector<ll>> &dp)
{
    for (int i = 0; i < dp.size(); ++i)
    {
        for (int j = 0; j < dp[i].size(); ++j)
        {
            if (dp[i][j] != -1)
            {
                cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n; //height of the tower
        //1-based indexing
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
        cout << solve(n, n, dp) << endl;
        //printDP(dp);
    }
}
