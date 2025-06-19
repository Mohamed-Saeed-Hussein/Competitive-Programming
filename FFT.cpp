onst double pi = acos(-1);
 
void fft(vector<complex<double>> &arr, bool invert) {
    int n = arr.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j |= bit;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * pi / len * (invert ? -1 : 1);
        complex<double> wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            complex<double> w(1);
            for (int j = 0; j < len / 2; ++j) {
                complex<double> u = arr[i + j];
                complex<double> v = arr[i + j + len / 2] * w;
                arr[i + j] = u + v;
                arr[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (auto &it: arr) {
            it /= n;
        }
    }
 
}
 
vector<double> multiply(vector<double> &arr, vector<double> &brr) {
    vector<complex<double>> fa(arr.begin(), arr.end()), fb(brr.begin(), brr.end());
    int n = 1;
    while (n < arr.size() + brr.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, 0);
    fft(fb, 0);
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, 1);
    vector<double> ans(n);
    for (int i = 0; i < n; ++i)
        ans[i] = round(fa[i].real());
    return ans;
}
 
