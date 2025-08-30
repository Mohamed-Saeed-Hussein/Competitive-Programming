// GCD
int64_t gcd(int64_t a, int64_t b) {
    if (b > a) {
        std::swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(a % b, b);
}

// LCM
int64_t lcm(int64_t a, int64_t b) {
    return (a * b / gcd(a, b));
}

// Sieve of Eratosthenes
const int inf = 1e6;
bool prime[inf];
void sieve() {
    fill(prime, prime + inf, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= inf; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= inf; j += i) {
                prime[j] = false;
            }
        }
    }
}

// Is Prime
bool is_prime(int64_t n) {
    if (n <= 1)
        return false;
    if (n != 2 && n % 2 == 0) {
        return false;
    }
    for (int64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Divisors
vector<int64_t> divisors(int64_t n) {
    vector<int64_t> divisors;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

// Prime Factors
vector<int64_t> prime_factors(int64_t n) {
    vector<int64_t> factors;
    for (int64_t i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

// Prime Factorization (Map)
map<int64_t, int64_t> prime_factorization1(int64_t n) {
    map<int64_t, int64_t> factor;
    for (int64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int64_t count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factor[i] += count;
        }
    }
    if (n > 1) {
        factor[n]++;
    }
    return factor;
}

// Prime Factorization (Vector of Pairs)
vector<pair<int64_t, int64_t>> prime_factorization2(int64_t n) {
    vector<pair<int64_t, int64_t>> factor;
    for (int64_t i = 2; i * i <= n; i++) {
        int64_t count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count)
            factor.push_back({i, count});
    }
    if (n > 1)
        factor.push_back({n, 1});
    return factor;
}

// Sum of First N Natural Numbers
int64_t sum(int64_t n) {
    return (n * (n + 1)) / 2;
}

int64_t fast_power(int64_t base, int64_t power) {
    int64_t ret = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            ret = (ret * base)
        }
        base = (base * base)
        power = power / 2;
    }
    return ret;
}



const int inf = 1e8;

vector<int> primes;

void sieve() {
    vector<bool> isPrime(inf + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= inf; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= inf; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= inf; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

vector<int> spf(int n) {
    vector<int> _primes;
    vector<int> _spf(n + 1, 0);
    iota(_spf.begin(), _spf.end(), 0);
    for (int64_t i = 2; i <= n; i++) {
        if (_spf[i] == i) {
            _primes.push_back(i);
        }
        for (auto it: _primes) {
            if (i * it > n) {
                break;
            }
            _spf[i * it] = min(it, _spf[i]);
            if (i % it == 0) {
                break;
            }
        }
    }
    return _spf;
}

vector<vector<int>> factors(int n) {
    auto _spf = spf(n);
    vector<vector<int>> fact(n + 1);
    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (1 < cur) {
            fact[i].push_back(_spf[cur]);
            cur /= _spf[cur];
        }
    }
    return fact;
}

vector<int> primes(int n) {
    vector<int> _primes;
    vector<bool> _is_prime(n + 1, 1);
    _is_prime[0] = _is_prime[1] = 0;
    for (int64_t i = 1; i <= n; i++) {
        if (_is_prime[i]) {
            _primes.push_back(i);
        }
        for (auto it : _primes) {
            if (i * it > n) {
                break;
            }
            _is_prime[i * it] = 0;
            if (i % it == 0) {
                break;
            }
        }
    }
    return _primes;
}



const int inf = 1e7 + 5;

vector<int64_t> factors(inf, 1);

void primes() {
    vector<int> _primes;
    vector<bool> _is_prime(inf + 1, 1);
    _is_prime[0] = _is_prime[1] = 0;
    for (int64_t i = 1; i <= inf; i++) {
        if (_is_prime[i]) {
            _primes.push_back(i);
            factors[i] = i;
        }
        for (auto it: _primes) {
            if (i * it > inf) {
                break;
            }
            _is_prime[i * it] = 0;
            factors[i * it] = it;
            if (i % it == 0) {
                break;
            }
        }
    }
}
