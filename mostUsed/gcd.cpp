int gcd(int a, int b) {
    while (a != 0) {
        int c = a;
        a = b % a;
        b = c;
    }
    return b;
}
