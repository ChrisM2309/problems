#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve()
{
    int n;
    cin >> n;
    vi a(n), prefA(n + 1, 0);
    vll pref2(n + 2, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefA[i + 1] = prefA[i] + a[i];
    }

    for (int i = 0; i <= n; i++){
        pref2[i + 1] = pref2[i] + prefA[i];
    }
    vll finalesFilas;
    ll ultimo = 0;
    for (int i = 0; i < n; i++)
    {
        finalesFilas.push_back(ultimo + n - i);
        ultimo = finalesFilas.back();
    }

    // construir el prefix para cada nivel,
    int nivelActual = 0, posNivelActual = 0;
    // linear, crear todos los prefix

    // pref de rows
    vll prefRows(n + 1,0);
    for (int i = 0; i < n; i++) 
    {
        int fila = n - i;
        ll sumaFila = pref2[n + 1] - pref2[i + 1] - 1LL * fila * prefA[i];

        prefRows[i + 1] = prefRows[i] + sumaFila; 
    } 

    int q;
    ll l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        l--;
        // sacar posiciones triangulas de l y r
        int nivelL = lower_bound(finalesFilas.begin(), finalesFilas.end(), l) - finalesFilas.begin();
        int nivelR = lower_bound(finalesFilas.begin(), finalesFilas.end(), r) - finalesFilas.begin();
        // en que posicion estan, probar
        int indiceL = l - (nivelL == 0 ? 0 : finalesFilas[nivelL - 1]) - 1;
        int indiceR = r - (nivelR == 0 ? 0 : finalesFilas[nivelR - 1]) - 1;

        int cntL = indiceL + 1; 
        int cntR = indiceR + 1; 

        //cout << "p L " << nivelL << " " << indiceL << endl;
        //cout << "p R " << nivelR << " " << indiceR << endl;

        ll totalL = prefRows[nivelL] + (pref2[nivelL + cntL + 1] - pref2[nivelL + 1] - cntL*prefA[nivelL]); 
        ll totalR = prefRows[nivelR] + (pref2[nivelR + cntR + 1] - pref2[nivelR + 1] - cntR*prefA[nivelR]); 

        cout << totalR - totalL << "\n"; 
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t = 1;
    while (t--)
    {
        solve();
    }
}
