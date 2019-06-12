#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0, __##i##_length = (n); i < __##i##_length; i++)
#define rep_reverse(i, n) for (ll i = (n)-1; 0 < i; i--)
#define FOR(i, from, to) for (ll i = (from), __##i##_end = (to); i < __##i##_end; i++)
#define FOR_REVERSE(i, from, to) for (ll i = (to)-1, __##i##_end = (from); __##i##_end <= i; i--)
#define foreach(e, v) for (const auto e : (v))
#define vfree(v) std::vector<int>().swap(v)
#define DEBUG(x) cout << #x << " = " << (x) << endl

using namespace std;
typedef int64_t ll;
typedef vector<ll> llv;
typedef vector<llv> llvv;

// https://atcoder.jp/contests/abc129/tasks/abc129_f

llv mul(llv lhs, llv rhs, ll mod)
{
    llv dst(9, 0);
    rep(i, 9)
        rep(j, 3)
    {
        dst[i] += (lhs[3 * (i / 3) + j] * rhs[j * 3 + (i % 3)]) % mod;
        dst[i] %= mod;
    }
    return dst;
}

llv mul_vec_mat(llv vec, llv mat, ll mod)
{
    llv dst(3);
    rep(i, 3)
        dst[i] = ((vec[0] * mat[i] % mod) + (vec[1] * mat[i + 3] % mod) + (vec[2] * mat[i + 6] % mod)) % mod;
    return dst;
}

llv powmod(llv m, ll n, ll mod)
{
    if (n == 0)
        return llv{1, 0, 0, 0, 1, 0, 0, 0, 1};
    if (n & 1)
    {
        llv tmp = powmod(m, n - 1, mod);
        return mul(tmp, m, mod);
    }
    else
    {
        llv tmp = powmod(m, n / 2, mod);
        return mul(tmp, tmp, mod);
    }
}

int main()
{
    ll L, A, B, M;
    cin >> L >> A >> B >> M;

    llv mat{1, 1, 0, 0, 0, 0, B % M, 0, 1};
    ll i = 0, d = 10;
    llv state{A % M, 0, 1};
    mat[4] = d;
    while (i <= L)
    {
        ll nexti = (d - A + B - 1) / B;
        if (nexti != 0 && i <= nexti && i <= L)
        {
            mat[4] = d % M;
            llv dst = powmod(mat, min(nexti, L) - i, M);
            i = nexti;
            state = mul_vec_mat(state, dst, M);

        }
        d *= 10;
    }
    cout << state[1] << endl;

    return 0;
}
