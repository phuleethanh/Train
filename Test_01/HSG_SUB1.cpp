#include <bits/stdc++.h>
using namespace std;
const string NAME = "HSG";
const int N = 202020;
string s;

int main()
{
    freopen((NAME + ".inp").c_str(), "r", stdin);
    freopen((NAME + ".out").c_str(), "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    int n = s.size();
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (s[i] == 'h' && s[j] == 's' && s[k] == 'g')
                    ans++;
    cout << ans;
    return 0;
}