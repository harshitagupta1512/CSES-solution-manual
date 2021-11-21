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
    vector<ll> x(n + 1);
    x[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    sort(x.begin(), x.end());

    //vector<ll> dp; // dp[i] = number of possible sums with array elements 0.....i

    set<int, greater<int>> sums;
    set<int, greater<int>>::iterator itr;
    sums.insert(x[0]);
    ll y = 0;
    for (int i = 1; i <= n; i++) {
        for (itr = sums.begin(); itr != sums.end(); itr++) {
            y = *itr + x[i];
            sums.insert(y);
        }
    }
    cout << sums.size() - 1;
    cout << endl;
    vector<ll> sum(sums.size() - 1);
    int j = 0;
    for (itr = sums.begin(); itr != sums.end(); itr++) {
        if (*itr != 0)
            sum[j] = *itr;

        j++;
    }
    sort(sum.begin(), sum.end());
    for (int i = 0; i < sum.size(); i++)
        cout << sum[i] << " ";

    cout << endl;

}