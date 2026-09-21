#include<bits/stdc++.h>
using namespace std; 

typedef long long ll; 

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n; 
    cin >> n;

    vector<ll> a(n); 
    vector<int> pref(n+1); 
    pref[0] = 0; 

    for (int i = 0; i < n; i++){
        cin >> a[i]; 
        pref[i+1] = (pref[i] + a[i]) % 7;
    }
    vector<pair<int,int>> cont(6);
    for (auto &X : cont ) {
        X.first = INT_MAX;
        X.second = INT_MIN; 
    } 

    for (int i = 0; i <= n; i++){
        int valor = pref[i];
        cont[valor].second = max(i, cont[valor].second); 
        cont[valor].first = min(i, cont[valor].first); 

    }
    int ans = 0; 
    for (auto x : cont) {
        if (x.first == INT_MAX || x.second == INT_MIN) continue; 
        ans = max(ans, x.second - x.first); 
    }
    cout << ans; 


}

