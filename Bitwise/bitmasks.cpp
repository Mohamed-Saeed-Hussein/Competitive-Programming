// Convert decimal to binary
string decimaltobinary(int64_t decimal) {
    if (decimal == 0) {
        return "0";
    }
    string binary = "";
    while (decimal > 0) {
        binary += to_string(decimal % 2);
        decimal /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

// Convert binary to decimal
int64_t binarytodecimal(const string& binary) {
    int64_t decimal = 0;
    int64_t base = 1;
    for (int64_t i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Check if a specific bit is set
bool knowbit(int64_t n, int64_t i) {
    return (n >> i) & 1;
}

// Set a specific bit
int64_t setbit(int64_t n, int64_t i) {
    return n | (1 << i);
}

// Reset a specific bit
int64_t resetbit(int64_t n, int64_t i) {
    return n & (~(1 << i));
}

// Flip a specific bit
int64_t flipbit(int64_t n, int64_t i) {
    return n ^ (1 << i);
}

// Check if a number is a power of two
bool ispoweroftwo(int64_t n) {
    if (n == 0) {
        return false;
    }
    return !(n & (n - 1));
}

// Count numbers with k-th bit set
int64_t getcount(int64_t n, int64_t k) {
    n++;
    int64_t res = (n >> (k + 1)) << k;
    if ((n >> k) & 1) {
        res += n & ((1ll << k) - 1);
    }
    return res;
}