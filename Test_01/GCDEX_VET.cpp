#include <bits/stdc++.h>
using namespace std;
const int N = 202020;
int n, a[N];

int main()
{
    freopen("GCDEX.inp", "r", stdin);
    freopen("GCDEX.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int vt = -1, ans = n + 1;
        for (int j = 1; j <= n; j++)
            if (j != i && __gcd(a[i], a[j]) > 1 && abs(i - j) < ans)
            {
                ans = abs(i - j);
                vt = j;
            }
        cout << vt << " ";
    }
    return 0;
}