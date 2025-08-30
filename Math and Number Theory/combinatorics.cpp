int64_t mod = 1e9 + 7;
vector<int64_t> fac, inv, finv;
 
int64_t nCr(int64_t x, int64_t y) {
    if (x < 0 or y > x or y < 0)
        return 0;
    return (fac[x] * finv[y] % mod * finv[x - y] % mod);
}
 
int64_t nPr(int64_t x, int64_t y) {
    if (x < 0 or y > x or y < 0)
        return 0;
    return fac[x] * finv[x - y] % mod;
}
 
int64_t power(int64_t b, int64_t n) {
    b %= mod;
    int64_t ret = 1;
    while (n) {
        if (n % 2 == 1)
            ret = ret * b % mod;
        b = b * b % mod;
        n /= 2;
    }
    return ret;
}
 
void initial(int n) {
    fac.resize(n + 1);
    inv.resize(n + 1);
    finv.resize(n + 1);
    fac[0] = inv[0] = inv[1] = finv[0] = finv[1] = 1;
    for (int64_t i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    for (int64_t i = 2; i <= n; ++i) {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    }
    for (int64_t i = 2; i <= n; ++i) {
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
 
int64_t multiplication(int64_t a, int64_t b) {
    return ((a % mod) * (b % mod)) % mod;
}
 
int64_t addition(int64_t a, int64_t b) {
    return ((a % mod) + (b % mod)) % mod;
}
 
int64_t subtraction(int64_t a, int64_t b) {
    return (((a - b) % mod) + mod) % mod;
}
 
int64_t divide(int64_t a, int64_t b) {
    return multiplication(a, power(b, mod - 2));
}
 
int64_t inverse(int x) {
    return power(x, mod - 2);
}
 
int64_t catalan(int n) {
    return (nCr(2 * n, n) * inverse(n + 1)) % mod;
}
 
int64_t stars_and_pars(int64_t n, int64_t k) {
    return nCr(n + k - 1, k - 1);
}
