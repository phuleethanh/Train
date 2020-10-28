#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define foru(i, a, n) for (int i = (a); i <= (n); i++)
const int N = 202020;

int n, a[N], f[N], d[N], e[N], R[N], L[N];

int main()
{
    freopen("GCDEX.inp", "r", stdin);
    freopen("GCDEX.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    foru(i, 1, N - 1) e[i] = i;
    for (ll i = 2; i * i < N; i++)
        if (e[i] == i)
            for (ll j = i * i; j < N; j += i)
                e[j] = i;

    cin >> n;
    foru(i, 1, n) cin >> a[i];

    ///khoang cach min ben phai
    foru(i, 1, N - 1) f[i] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        int u = a[i];
        int pos = n + 1;
        while (u > 1)
        {
            pos = min(pos, f[e[u]]);
            f[e[u]] = i;
            int v = u;
            while (v % e[u] == 0)
                v /= e[u];
            u = v;
        }
        R[i] = pos;
    }
    ///khoang cach min ben trai
    foru(i, 1, N - 1) f[i] = 0;
    foru(i, 1, n)
    {
        int u = a[i];
        int pos = 0;
        while (u > 1)
        {
            pos = max(pos, f[e[u]]);
            f[e[u]] = i;
            int v = u;
            while (v % e[u] == 0)
                v /= e[u];
            u = v;
        }
        L[i] = pos;
    }
    //foru(i,1,n) cout <<i <<" " <<L[i] <<" " <<R[i] <<"\n";
    foru(i, 1, n)
    {
        if (L[i] == 0 && R[i] == n + 1)
            cout << -1;
        else
        {
            if (L[i] == 0)
                cout << R[i];
            else
            {
                if (R[i] == n + 1)
                    cout << L[i];
                else
                {
                    if (i - L[i] <= R[i] - i)
                        cout << L[i];
                    else
                        cout << R[i];
                }
            }
        }
        cout << " ";
    }
    return 0;
}