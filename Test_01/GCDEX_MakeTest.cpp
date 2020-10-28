#include <bits/stdc++.h>
#define ll long long
#define foru(i, a, n) for (ll i = (a); i <= (n); ++i)
#define ford(i, n, a) for (int i = (n); i >= (a); --i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const string NAME = "GCDEX";
const int N = 202020;
long long n, a[N];

inline long long Rand(long long l, long long h)
{
    return l + 1ll * rand() * rand() % (h - l + 1);
}

void sub1(int u)
{
    n = Rand(1000, 2000);
    foru(i, 1, n) a[i] = Rand(1, 100000);
}

void sub2(int u)
{
    n = Rand(160000, 200000);
    foru(i, 1, n) a[i] = Rand(1, 200000);
}

void taoinput(int itest)
{
    freopen((NAME + ".inp").c_str(), "w", stdout);
    if (itest <= 12)
        sub1(itest);
    else if (itest <= 19)
        sub2(itest);
    else
    {
        n = 200000;
        foru(i, 1, n) a[i] = Rand(1, n);
    }
    cout << n << "\n";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    fclose(stdout);
}

void movefile(int u)
{
    string stt = "";
    while (u > 0)
    {
        stt = char(u % 10 + 48) + stt;
        u /= 10;
    }
    while (stt.size() % 3 != 0)
        stt = "0" + stt;
    string path = NAME + "\\Test" + stt;
    string tepvao = path + "\\" + NAME + ".inp";
    string tepra = path + "\\" + NAME + ".out";
    system(("rd /S /Q " + path).c_str());
    system(("md " + path).c_str());
    system(("MOVE " + NAME + ".inp " + tepvao).c_str());
    system(("MOVE " + NAME + ".out " + tepra).c_str());
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= 20; iTest++)
    {
        taoinput(iTest);
        system((NAME + ".exe").c_str());
        movefile(iTest);
    }
    return 0;
}
