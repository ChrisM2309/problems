// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n; 
    cin >> n;

    vector<pair<int,int>> a(n), x(n), y(n); 

    for (int i = 0; i < n; i++){
        cin >> x[i].first >> y[i].first; 
        x[i].second = i; 
        y[i].second = i; 
    } 

    sort(all(x)); 
    sort(all(y)); 

    for (int i = 0; i < n; i++){
        a[x[i].second].first = i + 1; 
        a[y[i].second].second = i + 1; 
    }

    sort(all(a));
    vector<vector<int>> grid( n + 1, vector<int>(n + 1, 0)); 

    for (auto cur : a) {
        grid[cur.first][cur.second] = 1; 
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i -1][j - 1];
        }
    }

    auto rango = [&](int x1, int y1, int x2, int y2){
        return grid[x2][y2] - grid[x1-1][y2] - grid[x2][y1-1] + grid[x1-1][y1-1]; 
    };

    long long ans = n + 1; 
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            // para las vacas actuales 
            int x1 = a[i].first; 
            int x2 = a[j].first;
            // la menor 
            int y1 = a[i].second; 
            int y2 = a[j].second;

            int lo = min(y1,y2); 
            int hi = max(y1,y2); 

            ans += 1LL * rango(x1, 1, x2, lo) * rango(x1, hi, x2, n);

        }
    }
    cout << ans << endl;

}

