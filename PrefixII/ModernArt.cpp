// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int total = n * n;

    vvi a(n + 1, vi(n + 1, 0));
    vvi grid(n + 2, vi(n + 2, 0));

    vi minFil(total + 1, INT_MAX);
    vi minCol(total + 1, INT_MAX);
    vi maxFil(total + 1, INT_MIN);
    vi maxCol(total + 1, INT_MIN);

    vi vis(total + 1, 0);  
    vi des(total + 1, 0); 
    int visibles = 0, descartados = 0; 

    int cur;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            cur = a[i][j];
            if (cur == 0) continue; 
            minFil[cur] = min(minFil[cur], i);
            maxFil[cur] = max(maxFil[cur], i);
            minCol[cur] = min(minCol[cur], j);
            maxCol[cur] = max(maxCol[cur], j);
            if (!vis[cur] == 1) {
                visibles++;
                vis[cur] = 1; 
            } 
            
        }
    }

    for (int cur = 1; cur <= total; cur++)
    {

        if (minFil[cur] == INT_MAX)
            continue;

        int x1 = minFil[cur] + 1;
        int y1 = minCol[cur] + 1;
        int x2 = maxFil[cur] + 1;
        int y2 = maxCol[cur] + 1;

        grid[x1][y1]++;
        grid[x1][y2 + 1]--;
        grid[x2 + 1][y1]--;
        grid[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            grid[i][j] += grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j] > 1){
                if(des[a[i -1][j - 1]] == 0){
                    des[a[i - 1][ j - 1]] = 1;
                    descartados++; 
                }
            }
        }
    }

    if (visibles == 1) cout << total - 1; 
    else cout << total - descartados; 
}
