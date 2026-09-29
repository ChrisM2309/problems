#include<bits/stdc++.h>
using namespace std; 

void solve(){
    int n, t;
    cin >> n >> t; 
    vector<int> a(n);
    for (auto &i : a) cin >> i; 

    int r = -1, cont = 0, ans = 0; 
    for (int l = 0; l < n; cont -= a[l++]){
        while( r + 1 < n && cont + a[r + 1] <= t) cont += a[++r]; 
        ans = max(ans, r - l + 1); 
    }  
    
    cout << ans; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}