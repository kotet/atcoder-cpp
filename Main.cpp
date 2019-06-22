#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0, __##i##_length = (n); i < __##i##_length; i++)
#define rep_reverse(i, n) for (ll i = (n)-1; 0 <= i; i--)
#define FOR(i, from, to) for (ll i = (from), __##i##_end = (to); i < __##i##_end; i++)
#define FOR_REVERSE(i, from, to) for (ll i = (to)-1, __##i##_end = (from); __##i##_end <= i; i--)
#define foreach(e, v) for (const auto e : (v))
#define vfree(v) std::vector<int>().swap(v)
#define DEBUG(x) cout << #x << " = " << (x) << endl

using namespace std;
typedef int64_t ll;
typedef vector<ll> llv;
typedef vector<llv> llvv;

ll gcd(ll a, ll b)
{
    return (a < b) ? gcd(b, a) : ((a % b) ? gcd(b, a % b) : b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    // https://atcoder.jp/contests/abc131/tasks/abc131_c
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll c = B / C - (A - 1) / C;
    ll d = B / D - (A - 1) / D;
    ll cd = B / lcm(C, D) - (A - 1) / lcm(C, D);
    cout << (B - A + 1) - (c + d - cd) << endl;
    return 0;
}
