#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<long long, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    int sum = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int l = 0, r = n - 1;
        while (l < i && i < r)
        {
            sum = a[i].first + a[l].first + a[r].first;
            if (sum == k)
            {
                cout << a[l].second << " " << a[i].second << " " << a[r].second;
                return;
            }
            else if (sum < k)
                l++;
            else if (sum > k)
                r--;
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}