#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll INV2 = (MOD+1)/2; // 500000004

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    ll dp = 1; // (1-1)! = 0! = 1
    for (int i = 1; i <= N-1; ++i) {
        dp = dp * i % MOD; // dp = i!
    }
    ll ans = dp * INV2 % MOD;
    cout << ans << '\n';
}
