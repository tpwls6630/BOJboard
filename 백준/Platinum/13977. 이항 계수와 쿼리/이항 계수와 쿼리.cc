#include <iostream>
#include <vector>

using namespace std;

// 13977 : "https://www.acmicpc.net/problem/13977"

// 페르마 소정리
// 팩토리얼 계산

#define MOD 1'000'000'007
#define ll long long

ll Power(ll a, ll p)
{
    ll ret = 1;
    while (p)
    {
        if (p & 1)
        {
            ret *= a;
            ret %= MOD;
        }
        p >>= 1;
        a *= a;
        a %= MOD;
    }
    return ret;
}

vector<ll> InitFactorial(int maxN)
{
    vector<ll> factorial(maxN + 1, 1);
    for (int i = 2; i <= maxN; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    return factorial;
}

vector<ll> InitInverseFactorial(vector<ll> factorial)
{
    int maxN = factorial.size() - 1;
    vector<ll> inverseFactorial(maxN + 1, 1);
    inverseFactorial[maxN] = Power(factorial[maxN], MOD - 2);
    for (int i = maxN - 1; i >= 2; i--)
    {
        inverseFactorial[i] = (inverseFactorial[i + 1] * (i + 1)) % MOD;
    }
    return inverseFactorial;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    int maxN = 1;
    vector<int> N(M), K(M);
    for (int i = 0; i < M; i++)
    {
        cin >> N[i] >> K[i];
        maxN = max(maxN, N[i]);
    }

    vector<ll> factorial = InitFactorial(maxN);
    vector<ll> inverseFactorial = InitInverseFactorial(factorial);

    for (int i = 0; i < M; i++)
    {
        ll result = (factorial[N[i]] * inverseFactorial[K[i]]) % MOD;
        result = (result * inverseFactorial[N[i] - K[i]]) % MOD;
        cout << result << "\n";
    }
    return 0;
}