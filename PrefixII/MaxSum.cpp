#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vi; 
int main() {
	int n, q; 
    cin >> n >> q;
    vi a(n), dif(n + 2, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    sort(a.begin(), a.end()); 
    int l,r;
    while(q--){
        cin >> l >> r; 
        dif[l]++; 
        dif[r+1]--; 
    }
    long long ans = 0; 
    priority_queue<int, vector<int>, greater<int>> cantidades; 
    for (int i = 1; i <= n; i++){
        dif[i] += dif[i - 1]; 
        cantidades.push(dif[i]);
        //cout << dif[i] << " ";
    }
    int pos = 0; 
    while(!cantidades.empty()){
        ans += cantidades.top() * a[pos]; 
        //cout << cantidades.top() << " " << a[pos] << endl; 
        pos++; 
        cantidades.pop();
    }
    cout << ans;
}
