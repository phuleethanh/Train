#include <bits/stdc++.h>
using namespace std;
const string NAME = "HSG";
string s;

int main()
{
    freopen((NAME + ".inp").c_str(), "r", stdin);
    freopen((NAME + ".out").c_str(), "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;

    long long ans = 0, h = 0, hs = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'h')
            h++;
        else if (s[i] == 's')
            hs += h;
        else if (s[i] == 'g')
            ans += hs;
    }
    cout << ans;
    return 0;
}