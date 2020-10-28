#include <bits/stdc++.h>
using namespace std;
const string NAME = "KSEQ";
const int N = 505050;
#define ll long long
long long n, k, a[N];

int main()
{
    freopen((NAME + ".inp").c_str(), "r", stdin);
    freopen((NAME + ".out").c_str(), "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum += a[j];
            if (sum == k)
                ans++;
        }
    }
    cout << ans;
    return 0;
}