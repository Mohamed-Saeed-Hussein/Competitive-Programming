struct mint {
    int64_t value;

    mint(int64_t v = 0) {
        value = v % mod;
        if (value < 0) value += mod;
    }

    mint(int64_t a, int64_t b) : value(0) { *this += a, *this /= b; }

    mint &operator+=(mint const &b) {
        value += b.value;
        if (value >= mod) value -= mod;
        return *this;
    }

    mint &operator-=(mint const &b) {
        value -= b.value;
        if (value < 0) value += mod;
        return *this;
    }

    mint &operator*=(mint const &b) {
        value = (value * b.value) % mod;
        return *this;
    }

    friend mint power(mint a, int64_t p) {
        mint res = 1;
        while (p) {
            if (p & 1) res *= a;
            a *= a, p >>= 1;
        }
        return res;
    }

    friend mint inverse(mint a) {
        return power(a, mod - 2);
    }

    mint &operator/=(mint const &b) { return *this *= inverse(b); }

    friend mint operator+(mint a, mint const b) { return a += b; }

    friend mint operator-(mint a, mint const b) { return a -= b; }

    friend mint operator*(mint a, mint const b) { return a *= b; }

    friend mint operator/(mint a, mint const b) { return a /= b; }

    friend ostream &operator<<(ostream &os, mint const &a) { return os << a.value; }

    friend bool operator==(mint const &a, mint const &b) { return a.value == b.value; }

    friend bool operator!=(mint const &a, mint const &b) { return a.value != b.value; }

    friend bool operator<=(mint const &a, mint const &b) { return a.value <= b.value; }

    friend bool operator>=(mint const &a, mint const &b) { return a.value >= b.value; }

    friend bool operator<(mint const &a, mint const &b) { return a.value < b.value; }

    friend bool operator>(mint const &a, mint const &b) { return a.value > b.value; }
};