// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi; 
int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n, m, q;
    cin >> n >> m >> q;

    string s; 

    vvi originales(n + 1, vi(m + 1, 0)); 
    vvi grid(n + 1, vi(m + 1, 0)); // ya guarda las cantidades por rango 
    vvi vertical(n + 1, vi(m + 1, 0)); 
    vvi horizontal(n + 1, vi(m + 1, 0));  
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < m; j++){ 
            grid[i+1][j+1] = grid[i][j + 1] + grid[i + 1][j] - grid[i][j]; 
            if (s[j] == '0') continue;
            grid[i+1][j+1]++;  
            originales[i + 1][j + 1] = 1; 
            if (originales[i][j+1] == 1) vertical[i+1][j+1] = 1; 
            if (originales[i + 1][j] == 1) horizontal[i+1][j+1] = 1;             
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            vertical[i][j] += vertical[i-1][j] + vertical[i][j - 1] - vertical[i - 1][j - 1]; 
            horizontal[i][j] += horizontal[i-1][j] + horizontal[i][j-1] - horizontal[i - 1][j - 1]; 
        }
    }

    auto cantidad = [&](vvi &cur, int a, int b, int c, int d){
        return cur[c][d] - cur[a-1][d] - cur[c][b-1] + cur[a-1][b-1]; 
    };

    int a,b,c,d;

    while (q--){
        cin >> a >> b >> c >> d; 
        int t = cantidad(grid, a, b, c, d); 
        int v = (a < c) ? cantidad(vertical, a + 1, b, c, d) : 0;
        int h = (b < d) ? cantidad(horizontal, a, b + 1, c, d) : 0;

        cout << t - v - h << endl; 
    }


    
}

