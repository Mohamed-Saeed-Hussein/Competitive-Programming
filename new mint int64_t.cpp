template<class T>
constexpr T power(T a, int64_t b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

template<int P>
struct mint {
    int x;

    constexpr mint() : x{} {}

    constexpr mint(int64_t x) : x{fix(x % get_mod())} {}

    static int mod;

    constexpr static int get_mod() {
        if (P > 0) {
            return P;
        } else {
            return mod;
        }
    }

    constexpr static void set_mod(int _mod) {
        mod = _mod;
    }

    constexpr int fix(int x) const {
        if (x < 0) {
            x += get_mod();
        }
        if (x >= get_mod()) {
            x -= get_mod();
        }
        return x;
    }

    constexpr int value() const {
        return x;
    }

    explicit constexpr operator int() const {
        return x;
    }

    constexpr mint operator-() const {
        mint res;

        res.x = fix(get_mod() - x);
        return res;
    }

    constexpr mint inverse() const {
        assert(x != 0);
        return power(*this, get_mod() - 2);
    }

    constexpr mint &operator*=(mint rhs) &{
        x = 1LL * x * rhs.x % get_mod();
        return *this;
    }

    constexpr mint &operator+=(mint rhs) &{
        x = fix(x + rhs.x);
        return *this;
    }

    constexpr mint &operator-=(mint rhs) &{
        x = fix(x - rhs.x);
        return *this;
    }

    constexpr mint &operator/=(mint rhs) &{
        return *this *= rhs.inverse();
    }

    friend constexpr mint operator*(mint lhs, mint rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr mint operator+(mint lhs, mint rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr mint operator-(mint lhs, mint rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr mint operator/(mint lhs, mint rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr std::istream &operator>>(std::istream &is, mint &a) {
        int64_t v;
        is >> v;
        a = mint(v);
        return is;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const mint &a) {
        return os << a.value();
    }

    friend constexpr bool operator==(mint lhs, mint rhs) {
        return lhs.value() == rhs.value();
    }

    friend constexpr bool operator!=(mint lhs, mint rhs) {
        return lhs.value() != rhs.value();
    }
};

template<>
int mint<0>::mod = 1;

template<int V, int P>
constexpr mint<P> CInv = mint<P>(V).inverse();

constexpr int mod = 1000000007;
using Z = mint<mod>;

