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
    string a, b;
    cin >> a;
    cin >> b;
    ll m = a.size();
    ll n = b.size();
    ll dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) //first column
        dp[i][0] = i;

    for (int j = 0; j <= n; j++) // first row
        dp[0][j] = j; //convert a null string to some substring of b

    //dp[i][j] is the edit distance between x[0...i-1] and y[0...j-1]
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            int diff = 1;
            if (a[i - 1] == b[j - 1])
                diff = 0;
            dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1]);
            dp[i][j] = min(diff + dp[i - 1][j - 1], dp[i][j]);

        }

/*
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/

    cout << dp[m][n];
}
