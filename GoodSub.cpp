#include<bits/stdc++.h>
using namespace std; 

typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    string s;
    cin >> s;
    vector<int> a;
    vector<int> pref(n + 1); 
    pref[0] = 0; 
    map<int, ll> cont; 
    for (int i = 0; i < n; i++){
        a.push_back(s[i] - '0'); 
        pref[i+1] = a[i] + pref[i]; 
    }

    for (int i = 0; i <= n; i++){
        cont[pref[i] - i]++; 
    }
    ll ans = 0; 
    for (auto x : cont) {
        ans += x.second * (x.second-1)/2;  
    }
    cout << ans << "\n"; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t; 
    while (t--){
        solve();
    }
}