#include <bits/stdc++.h>
#define ll long long
using namespace std;
const string NAME = "HSG";
string s, r = "zxcvbnmasdfghjklqwertyuiophhhhhhhhhhssssssssssgggggggggg";
string r1 = "zxchhhhhhhhhhjklqwertyuiophhhhhhhhhhgggggggggg";
int n;

inline long long Rand(long long l, long long h)
{
    return l + 1ll * rand() * rand() % (h - l + 1);
}

void sub1(int u)
{
    n = Rand(150, 200);
    s = "";
    for (int i = 1; i <= n; i++)
        s.push_back(r[Rand(0, r.size() - 1)]);
    cout << s;
}

void sub2(int u)
{
    n = Rand(1700, 2000);
    s = "";
    for (int i = 1; i <= n; i++)
        s = s + r1[Rand(0, r1.size() - 1)];
    s[Rand(900, 1300)] = 's';
    cout << s;
}

void sub3(int u)
{
    n = Rand(40000, 50000);
    s = "";
    for (int i = 1; i <= n; i++)
        s = s + r[Rand(0, r.size() - 1)];
    cout << s;
}

void taoinput(int itest)
{
    freopen((NAME + ".inp").c_str(), "w", stdout);
    if (itest <= 6)
        sub1(itest);
    else if (itest <= 12)
        sub2(itest);
    else if (itest <= 19)
        sub3(itest);
    else
    {
        n = 16666;
        s = "";
        for (int i = 1; i <= n; i++)
            s = s + "hsg";
        cout << s;
    }
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
    for (int iTest = 20; iTest <= 20; iTest++)
    {
        taoinput(iTest);
        system((NAME + ".exe").c_str());
        movefile(iTest);
    }
    return 0;
}
