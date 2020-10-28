#include <bits/stdc++.h>
#define ll long long
#define foru(i, a, n) for (ll i = (a); i <= (n); ++i)
#define ford(i, n, a) for (int i = (n); i >= (a); --i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const string NAME = "smama";
const int N = 1010101;
long long n;
vector<long long> v;

long long Rand(long long l, long long h)
{
    return l + 1ll * rand() * rand() % (h - l + 1);
}

void brute(long long num)
{
    if (num > 1000000000)
        return;
    v.push_back(num);
    brute(num * 10 + 4);
    brute(num * 10 + 7);
}

void sub1(int u)
{
    n = Rand(3, 60);
    cout << v[n];
}

void sub2(int u)
{
    n = Rand(70, 1000);
    cout << v[n];
}

void taoinput(int itest)
{
    freopen((NAME + ".inp").c_str(), "w", stdout);
    if (itest <= 1)
        cout << 46;
    else if (itest <= 2)
        cout << 444;
    else if (itest <= 3)
        cout << 7;
    else if (itest <= 10)
        sub1(itest);
    else if (itest <= 19)
        sub2(itest);
    else
        cout << 777747777;
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
    brute(0);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int iTest = 1; iTest <= 20; iTest++)
    {
        taoinput(iTest);
        system((NAME + ".exe").c_str());
        movefile(iTest);
    }
    return 0;
}
