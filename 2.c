#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll omega;
    cin >> n >> omega;

    vector<pair<ll, int>> a(n); // (масса, исходный индекс)
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; // нумерация с 1
    }

    sort(a.begin(), a.end()); // сортируем по возрастанию массы

    ll cur = omega;          // текущий размер центральной дыры
    vector<int> ans;         // порядок поглощения

    bool ok = true;
    for (auto &p : a) {
        if (cur > p.first) {     // можем поглотить
            cur += p.first;
            ans.push_back(p.second);
        } else {                 // не можем даже самую маленькую
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}
