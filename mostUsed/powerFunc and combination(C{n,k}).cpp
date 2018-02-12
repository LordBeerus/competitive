ll mod_pow(ll x, ll y) {
    // exponentiation by squaring
    ll r = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            r = (r * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return r;
}

ll perm[maxn];
ll invPerm[maxn];
ll mod_pow(ll x, ll y)
{
    // exponentiation by squaring
    ll r = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            r = (r*x) % mod;
        }
        x = (x*x) % mod;
        y /= 2;
    }
    return r%mod;
}
inline ll comb(int n,int k) {
    if (k>n)return 0;
    return (((perm[n]*invPerm[k])%mod)*invPerm[n-k])%mod;
}

perm[0] = 1;
    invPerm[0] = 1;
    rep (i,1,maxn) {
        perm[i] = (perm[i-1]*i)%mod;
        invPerm[i] = mod_pow(perm[i],MOD-2)%mod;
    }

//-----
  vector<vector<long>> C(n+1, vector<long>(n+1));
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
