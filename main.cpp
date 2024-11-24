#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> venda(n);
    for (auto &i : venda)
        cin >> i;

    vector<ll> custo(m), limite(m);
    for (ll i = 0; i < ll(custo.size()); i++) {
        ll ci, li;
        cin >> ci >> li;
        custo[i] = ci;
        limite[i] = li;
    }

    vector<vector<double>> receitas(n, vector<double>(m));
    for (auto &row : receitas)
        for (auto &i : row)
            cin >> i;

    ll i;
    printf("max: ");
    for (i = 0; i < n; i++)
        printf("+%lld*p%lld ", venda[i], i);

    for (i = 0; i < m-1; i++)
        printf("-%lld*c%lld ", custo[i], i);
    printf("-%lld*c%lld;\n", custo[i], i);

    for (i = 0; i < m; i++)
        printf("limit_constraint%lld: c%lld <= %lld;\n", i, i, limite[i]);

    for (ll j = 0; j < m; j++) {
        printf("receita_constraint%lld: ", j);
        for (i = 0; i < n-1; i++) {
            printf("+%lf*p%lld ", receitas[i][j], i);
        }
        printf("+%lf*p%lld <= c%lld;\n", receitas[i][j], i, j);
    }
}
