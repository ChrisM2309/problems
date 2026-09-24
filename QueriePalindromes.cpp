#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<bool>> pal(n + 1, vector<bool>(n + 1, 0));
    vector<vi> ans(n + 1, vi(n + 1, 0));

    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if (len == 1)
                pal[l][r] = 1;
            else if (len == 2)
                pal[l][r] = (s[l-1] == s[r-1]);
            else
                pal[l][r] = (s[l-1] == s[r-1]) && pal[l + 1][r - 1];
        }
    }

    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if (len == 1) ans[l][r] = 1; 
            else ans[l][r] = ans[l + 1][r] + ans[l][r - 1] - ans[l + 1][r - 1] + pal[l][r];
            //cout << ans[l][r] << " ";
        }
        //cout << endl; 
    }

    int q, l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        cout << ans[l][r] << "\n";
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t = 1;
    while (t--)
    {
        solve();
    }
}