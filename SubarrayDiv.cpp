#include<bits/stdc++.h> 
using namespace std; 

typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    vector<ll> a(n);    
    ll total = 0; 
    vector<ll> mods(n); 
    vector<ll> cont(n,0); 
    cont[0] = 1; 
    for (int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
        cont[(total % n + n) % n]++; 
    }
    ll ans = 0; 
    for (auto x : cont){
        //cout << x << " ";
        ans += x * (x-1)/2;
    }
    cout << ans; 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    while(t--){
        solve();
    }
}

