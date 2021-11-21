#include <bits/stdc++.h>
#include <istream>
#include <algorithm>
#include <functional>

#define modValue 1000000007
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    /* ------- O(n*n) solution -------

    vector<ll> dp(n); //dp[i] is the length of the longest subsequence with x[i] as it's last element
    vector<vector<ll>> edgeList(n);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (x[j] > x[i] && j > i)
                edgeList[j].push_back(i);

    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < edgeList[i].size(); j++)
        {
            dp[i] = max(dp[i], dp[edgeList[i][j]]);
        }
        dp[i] = dp[i] + 1;
    }

    ll ans = *max_element(dp.begin(), dp.end());
    cout << ans;
    */
}