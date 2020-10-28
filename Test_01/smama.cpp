#include <bits/stdc++.h>
using namespace std;
const string NAME = "smama";
vector<long long> v;

void brute(long long num)
{
    if (num > 1000000000)
        return;
    v.push_back(num);
    brute(num * 10 + 4);
    brute(num * 10 + 7);
}

int main()
{
    freopen((NAME + ".inp").c_str(), "r", stdin);
    freopen((NAME + ".out").c_str(), "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    brute(0);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int n;
    cin >> n;
    for (int i = 1; i < v.size(); i++)
        if (v[i] == n)
        {
            cout << i;
            return 0;
        }
    cout << -1;
    return 0;
}