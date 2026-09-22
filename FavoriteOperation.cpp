#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve()
{
    int n;
    ll m;

    cin >> n >> m;

    vector<ll> a(n), restos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        restos[i] = a[i] % m;
    }

    ll ans = LLONG_MAX;

    sort(restos.begin(), restos.end());
    for (int i = 0; i < n; i++)
    {
        restos.push_back(restos[i] + m);
    }
    vector<ll> pref(2 * n + 1, 0);

    for (int i = 0; i < 2 * n; i++)
    {
        pref[i + 1] = pref[i] + restos[i];
    }

    for (int l = 0; l < n; l++)
    {
        int r = l + n - 1;
        int mid = l + (r - l) / 2;
        ll left = restos[mid] * (mid - l) - (pref[mid] - pref[l]);
        ll right = (pref[r + 1] - pref[mid + 1]) - restos[mid] * (r - mid);

        ans = min(ans, left + right);
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
        solve();
}