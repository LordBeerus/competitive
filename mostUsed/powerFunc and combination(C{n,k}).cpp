ll mod_pow(ll x, ll y) {
    // exponentiation by squaring
    ll r = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            r = (r * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return r;
}

ll perm[MAXN];
ll invPerm[MAXN];
ll mod_pow(ll x, ll y)
{
    // exponentiation by squaring
    ll r = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            r = (r*x) % MOD;
        }
        x = (x*x) % MOD;
        y /= 2;
    }
    return r%MOD;
}
inline ll comb(int n,int k) {
    return (((perm[n]*invPerm[k])%MOD)*invPerm[n-k])%MOD;
}

perm[0] = 1;
    invPerm[0] = 1;
    rep (i,1,MAXN) {
        perm[i] = (perm[i-1]*i)%MOD;
        invPerm[i] = mod_pow(perm[i],MOD-2)%MOD;
    }

//-----
  vector<vector<long>> C(n+1, vector<long>(n+1));
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
