#include <bits/stdc++.h>
#define ll long long
#define foru(i, a, n) for (ll i = (a); i <= (n); ++i)
#define ford(i, n, a) for (int i = (n); i >= (a); --i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const string NAME = "KSEQ";
const int N = 505050;
long long n, k, a[N], b[N];
map<long long, long long> M;
vector<pair<long long, long long>> V;

inline long long Rand(long long l, long long h)
{
    return l + 1ll * rand() * rand() % (h - l + 1);
}
void makeSubSum()
{
    M.clear();
    for (int i = 1; i <= n; i++)
    {
        long long sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum += a[j];
            M[sum]++;
        }
    }
    V.clear();
    for (auto x : M)
        V.emplace_back(x.second, x.first);
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
}

void makeSubSum2()
{
    M.clear();
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        M[sum]++;
    }
    for (auto x = M.rbegin(); x != M.rend(); x++)
    {
        V.emplace_back(x->second, x->first);
        if (V.size() >= 10)
            break;
    }
    sort(V.begin(), V.end(), greater<pair<ll, ll>>());
}

void sub1(int u)
{
    n = Rand(180, 200);
    foru(i, 1, n) a[i] = Rand(-10, 10);
    makeSubSum();
    k = V[Rand(0, 3)].second;
}

void sub2(int u)
{
    n = Rand(500, 5000);
    foru(i, 1, n) a[i] = Rand(-100, 100);
    makeSubSum();
    k = V[Rand(0, 3)].second;
}

void sub3(int u)
{
    n = Rand(200000, 500000);
    foru(i, 1, n) a[i] = Rand(-1e3, 1e3);
    makeSubSum2();
    k = V[Rand(0, 5)].second;
}
void sub4(int u)
{
    n = Rand(40000, 500000);
    foru(i, 1, n) a[i] = Rand(-1e6, 1e6);
    makeSubSum2();
    k = V[Rand(0, 5)].second;
}

void taoinput(int itest)
{
    freopen((NAME + ".inp").c_str(), "w", stdout);
    if (itest <= 6)
        sub1(itest);
    else if (itest <= 12)
        sub2(itest);
    else if (itest <= 16)
        sub3(itest);
    else if (itest <= 19)
        sub4(itest);
    else
    {
        n = 500000;
        k = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = Rand(1e8, 1e9);
            k += a[i];
        }
    }
    cout << n << " " << k << "\n";
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
    for (int iTest = 17; iTest <= 20; iTest++)
    {
        taoinput(iTest);
        system((NAME + ".exe").c_str());
        movefile(iTest);
    }
    return 0;
}
