const int64_t _base1 = 31, _base2 = 37;
const int64_t inf = 1e6 + 10;
const int64_t _mod1 = 1e9 + 7, _mod2 = 2e9 + 11;
int64_t _inv1, _inv2;

vector<int64_t> _pow1(inf), _pow2(inf);

int64_t power(int64_t b, int64_t n, int64_t mod) {
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

void initial() {
    _inv1 = power(_base1, _mod1 - 2, _mod1);
    _inv2 = power(_base2, _mod2 - 2, _mod2);
    _pow1[0] = _pow2[0] = 1;
    for (int i = 1; i < inf; ++i) {
        _pow1[i] = (_pow1[i - 1] * _base1) % _mod1;
        _pow2[i] = (_pow2[i - 1] * _base2) % _mod2;
    }
}

struct hashing {
private:
    int64_t _H1, _H2;
    deque<char> digit;
public:
    hashing() {
        _H1 = _H2 = 0;
    }

    void _push_back(char ch) {
        _H1 = (((_H1 * _base1) % _mod1) + (ch - 'a' + 1)) % _mod1;
        _H2 = (((_H2 * _base2) % _mod2) + (ch - 'a' + 1)) % _mod2;
        digit.push_back(ch);
    }

    void _push_front(char ch) {
        _H1 = ((((ch - 'a' + 1) * _pow1[digit.size()]) % _mod1) + _H1) % _mod1;
        _H2 = ((((ch - 'a' + 1) * _pow2[digit.size()]) % _mod2) + _H2) % _mod2;
        digit.push_front(ch);
    }

    void _pop_back() {
        _H1 = (((_H1 - (digit.back() - 'a' + 1)) % _mod1) * _inv1) % _mod1;
        _H2 = (((_H2 - (digit.back() - 'a' + 1)) % _mod2) * _inv2) % _mod2;
        digit.pop_back();
    }

    void _pop_front() {
        _H1 = ((_H1 - ((((digit.front() - 'a' + 1) * _pow1[digit.size() - 1])) % _mod1)) + _mod1) % _mod1;
        _H2 = ((_H2 - ((((digit.front() - 'a' + 1) * _pow2[digit.size() - 1])) % _mod2)) + _mod2) % _mod2;
        digit.pop_front();
    }

    pair<int64_t, int64_t> get() {
        return {_H1, _H2};
    }
};
