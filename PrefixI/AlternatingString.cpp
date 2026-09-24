#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    cin >> n;
    
    string s; 
    cin >> s; 

    vector<vector<vector<int>>> pref(2, vector<vector<int>>(26, vector<int>(n + 1, 0)));

    for(int i = 0; i < n; i++){

        for (int j = 0; j < 26; j++){
            pref[0][j][i + 1] += pref[0][j][i]; 
            pref[1][j][i+1] += pref[1][j][i];   
        }

        int cur = s[i] - 'a';
        if (i%2){
            pref[0][cur][i+1]++;  // impar
        } else {
            pref[1][cur][i+1]++; // par 
        }
        
    }

    // para cuando es par 
    if (n%2==0){
        int maxPar = 0, maxImpar = 0;
        for (int i = 0; i < 26; i++){
            maxPar = max(maxPar, pref[1][i][n]);
            maxImpar = max(maxImpar, pref[0][i][n]);
        }
        cout << n - maxPar - maxImpar << "\n"; 
        return; 
    } 
    // si es impar, buscar el mejor para quitar 
    int mejor = 0;
    for (int i = 0; i < n; i++){
        int maxPar = 0, maxImpar = 0; 
        for (int c = 0; c < 26; c++ ){
            int paresDerecha = pref[1][c][i] + (pref[0][c][n] - pref[0][c][i+1]);
            int imparesDerecha = pref[0][c][i] + (pref[1][c][n] - pref[1][c][i+1]); 
            maxPar = max(maxPar, paresDerecha); 
            maxImpar = max(maxImpar, imparesDerecha); 
        }
        mejor = max(mejor, maxImpar + maxPar);
    }
    cout << n - mejor << "\n"; 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}