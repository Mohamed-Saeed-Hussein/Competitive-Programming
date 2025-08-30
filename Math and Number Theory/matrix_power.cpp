const int64_t mod = 1e9 + 7;

template <typename T>
struct matrix_power
{
    int n, m;
    vector<vector<T>> a;
    matrix_power() {}
    matrix_power(int _n, int _m)
    {
        n = _n;
        m = _m;
        a.assign(n, vector<T>(m, 0));
    }
    matrix_power(vector<vector<T>> &v)
    {
        n = v.size();
        m = n ? v[0].size() : 0;
        a = v;
    }

    void make_unit()
    {
        assert(n == m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = (i == j ? T(1) : T(0));
            }
        }
    }

    matrix_power operator+(const matrix_power &b)
    {
        assert(n == b.n and m == b.m);
        matrix_power ans = matrix_power(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
            }
        }
        return ans;
    }

    matrix_power operator-(const matrix_power &b)
    {
        assert(n == b.n and m == b.m);
        matrix_power ans = matrix_power(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
            }
        }
        return ans;
    }

    matrix_power operator*(const matrix_power &b)
    {
        assert(m == b.n);
        matrix_power ans = matrix_power(n, b.m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < b.m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    ans.a[i][j] = (ans.a[i][j] + T(1) * a[i][k] * b.a[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }

    matrix_power power(int64_t k)
    {
        assert(n == m);
        matrix_power ans(n, n), base(a);
        ans.make_unit();
        while (k)
        {
            if (k & 1)
                ans = ans * base;
            base = base * base;
            k >>= 1;
        }
        return ans;
    }

    matrix_power &operator+=(const matrix_power &b)
    {
        return *this = (*this) + b;
    }
    matrix_power &operator-=(const matrix_power &b)
    {
        return *this = (*this) - b;
    }
    matrix_power &operator*=(const matrix_power &b)
    {
        return *this = (*this) * b;
    }
    bool operator==(const matrix_power &b)
    {
        return a == b.a;
    }
    bool operator!=(const matrix_power &b)
    {
        return a != b.a;
    }
};
