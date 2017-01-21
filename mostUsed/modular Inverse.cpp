long modPow(long x, long y)
{
    // Calculates x raised to the y-th power modulo MOD
    // in O(log(y)) time by using repeated squaring.
    long r = 1;
    while (y > 0) {
        if ( (y&1) != 0) {
            r = (r * x) % MOD;
        }
        x = (x * x ) % MOD;
        y >>= 1;
    }
    return r;
}
// Modular multiplicative inverse:
// Since MOD is prime, we can use Fermat's little theorem.
// Which is really a special case of the extended Euclidean algorithm
long modInverse(long x)
{
    return modPow(x, MOD - 2);
}
