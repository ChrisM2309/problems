#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi; 


// solo practica de escritura de range queries en matrices 
x   
void solve(){
    int n, q;
    cin >> n >> q; 

    vvi grid(n  + 1, vi(n + 1, 0)); 
    string s; 

    for (int i = 1; i <= n; i++){
        cin >> s;
        for (int j = 1; j <= n; j++){ 
            grid[i][j] = grid[i][j - 1] + grid[i-1][j] + ((s[j-1] == '*')? 1 : 0) - grid[i-1][j-1];  
        } 
    }


    while(q--){
        int a,b; 
        int c,d;
        cin >> a >> b >> c >> d; 

        cout << grid[c][d] - grid[a - 1][d] -  grid[c][b-1] + grid[a - 1][b - 1] << "\n";  
    }

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1; 
    while (t--){
        solve();
    }
}