// const int64_t _base1 = 129, _base2 = 131;
const int64_t _base1 = 31, _base2 = 37;
const int64_t inf = 1000000 + 10;
const int64_t _mod1 = 1000000007;
const int64_t _mod2 = 2000000033;
vector<int64_t> _pow1(inf), _pow2(inf);

int64_t multiplication(int64_t a, int64_t b, int64_t mod)
{
    return ((a % mod) * (b % mod)) % mod;
}

int64_t addition(int64_t a, int64_t b, int64_t mod)
{
    return ((a % mod) + (b % mod)) % mod;
}

int64_t subtraction(int64_t a, int64_t b, int64_t mod)
{
    return (((a - b) % mod) + mod) % mod;
}

void initial()
{
    _pow1[0] = _pow2[0] = 1;
    for (int i = 1; i < inf; ++i)
    {
        _pow1[i] = multiplication(_pow1[i - 1], _base1, _mod1);
        _pow2[i] = multiplication(_pow2[i - 1], _base2, _mod2);
        // _pow1[i] = _pow1[i - 1] * _base1 % _mod1;
        // _pow2[i] = _pow2[i - 1] * _base2 % _mod2;
    }
}

struct hashing
{
    int64_t H1 = 0, H2 = 0;
    array<int64_t, 2> *prefix;
    hashing(string &s)
    {
        prefix = new array<int64_t, 2>[s.size()];
        for (size_t i = 0; i < s.size(); ++i)
        {
            int64_t v = s[i] - 'a' + 1;
            // int64_t v = s[i];
            H1 = addition(multiplication(H1, _base1, _mod1), v, _mod1);
            H2 = addition(multiplication(H2, _base2, _mod2), v, _mod2);
            // H1 = (H1 * _base1 + v) % _mod1;
            // H2 = (H2 * _base2 + v) % _mod2;
            prefix[i] = {H1, H2};
        }
    }

    array<int64_t, 2> get(int l, int r)
    {
        int64_t _R1 = prefix[r][0];
        int64_t _R2 = prefix[r][1];
        if (l > 0)
        {
            int length = r - l + 1;
            int64_t _L1 = multiplication(prefix[l - 1][0], _pow1[length], _mod1);
            int64_t _L2 = multiplication(prefix[l - 1][1], _pow2[length], _mod2);
            // int64_t _L1 = (prefix[l - 1][0] * _pow1[length]) % _mod1;
            // int64_t _L2 = (prefix[l - 1][1] * _pow2[length]) % _mod2;
            _R1 = subtraction(_R1, _L1, _mod1);
            _R2 = subtraction(_R2, _L2, _mod2);
        }
        return {_R1, _R2};
    }
};

