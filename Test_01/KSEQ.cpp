#include <bits/stdc++.h>
using namespace std;
const string NAME = "KSEQ";
const int N = 505050;
#define ll long long
long long n, k, a[N];
map<ll, ll> M;

int main()
{
    freopen((NAME + ".inp").c_str(), "r", stdin);
    freopen((NAME + ".out").c_str(), "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long ans = 0, sum = 0;
    M[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        M[sum]++;
        ans += M[sum - k];
    }
    cout << ans;
    return 0;
}