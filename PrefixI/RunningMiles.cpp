#include<bits/stdc++.h>
using namespace std; 

void solve(){
    int n; 
    cin >> n; 
    vector<long long> a(n), sumIz(n), resDer(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sumIz[i] = a[i] + i + 1;
        resDer[i] = a[i] - i - 1;  
    }
    for (int i = 1; i < n; i++){
        sumIz[i] = max(sumIz[i], sumIz[i-1]);
        resDer[n-i-1] = max(resDer[n-i-1], resDer[n-i]); 
    }

    long long ans = INT_MIN; 
    for (int i = 1; i < n - 1; i++){
        ans = max(ans, a[i] + sumIz[i-1] + resDer[i+1]); 
    }
    cout << ans << "\n"; 
}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        solve(); 
    }
}