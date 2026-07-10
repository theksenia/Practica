#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll S = 0, pow2 = 1; // pow2 = 2^(i-1) для текущего i
    for (int i = 0; i < n; ++i) {
        ll a; cin >> a;
        a %= MOD;
        if (a < 0) a += MOD;
        S = (2 * S + a * pow2) % MOD;
        pow2 = (pow2 * 2) % MOD;
    }
    cout << S << '\n';
}
