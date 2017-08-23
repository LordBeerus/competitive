long mod_pow(long x, int y)
{
    // exponentiation by squaring
    long r = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            r = (r*x) % MOD;
        }
        x = (x*x) % MOD;
        y /= 2;
    }
    return r;
}
  vector<vector<long>> C(n+1, vector<long>(n+1));
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
