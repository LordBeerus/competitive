typedef complex<double> cd;
typedef complex<double>  base;

typedef vector<cd> vcd;


void fft2(vector<base> & a, bool invert) {
    int n = (int)a.size();

    for (int i = 1, j = 0; i<n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    long double PI = acos(-1);
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * pi / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i<n; i += len) {
            base w(1.0);
            for (int j = 0; j<len / 2; ++j) {
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i = 0; i<n; ++i)
            a[i] /= n;

}

vector < int > multiply2(vector < int > a, vector < int > b)
{
    vector < int > res;
    vector < complex < double > > fa(a.begin(), a.end()),  fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size())){
        n *= 2;
    }
    n *= 2;
    fa.resize(n), fb.resize(n);
    fft2(fa, false), fft2(fb, false);
    for(int i = 0; i < n; i++){
        fa[i] *= fb[i];
    }
    fft2(fa, true);
    res.resize(n);
    for(int i = 0; i < n; i++){
        res[i] = int(fa[i].real() + 0.5);
    }
    return res;
}
