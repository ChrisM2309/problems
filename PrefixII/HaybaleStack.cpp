// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n, q;
    cin >> n >> q; 

    vector<int> pref(n + 2, 0); 
    int a, b; 
    while(q--){
        cin >> a >> b; 
        pref[a]++; 
        pref[b+1]--; 
    }
    priority_queue<int> pq; 
    for (int i = 1; i <= n; i++){
        pref[i] += pref[i - 1];
        pq.push(pref[i]);
        //cout << i << " " << pref[i] << endl; 
    }

    int elim = (n - 1)/2;
    while(elim--){
        pq.pop(); 
    }
    cout << pq.top(); 

    
}

